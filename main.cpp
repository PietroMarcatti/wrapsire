#include "wrapsire.hpp"

#include "agents/random.hpp"

pkmn_choice choose(
   pkmn_gen1_battle *battle,
   pkmn_psrng *random,
   pkmn_player player,
   pkmn_choice_kind request,
   pkmn_choice choices[])
{
   uint8_t n = pkmn_gen1_battle_choices(battle, player, request, choices, PKMN_CHOICES_SIZE);
   // Technically due to Generation I's Transform + Mirror Move/Metronome PP
   // error if the battle contains Pokémon with a combination of Transform,
   // Mirror Move/Metronome, and Disable its possible that there are no
   // available choices (softlock), though this is impossible here given that
   // our example battle involves none of these moves
   assert(n > 0);
   // pkmn_gen1_battle_choices determines what the possible choices are - the
   // simplest way to choose an option here is to just use the PSRNG to pick one
   // at random
   return choices[(uint64_t)pkmn_psrng_next(random) * n / 0x100000000];
}

template<typename Container>
typename Container::value_type random_team(const Container& teams)
{
   static std::random_device rd;
   static std::mt19937 gen(rd());
   static std::uniform_int_distribution<> distrib(0, teams.size() - 1);
   return teams[distrib(gen)];
}

int main(int argc, char **argv)
{
   using namespace engine::RBY;
   
   auto battle = engine::RBY::miedon_zapjynx;
   pkmn_result result = PKMN_RESULT_NONE;
   pkmn_choice c1;
   pkmn_choice c2;
   pkmn_psrng random;
   uint64_t seed = 2;
   pkmn_psrng_init(&random, seed);
   pkmn_choice choices[PKMN_CHOICES_SIZE];

   battle.init();

   while(!pkmn_result_type(battle.result))
   {
      c1 = choose(&battle.battle_, &random, PKMN_PLAYER_P1, pkmn_result_p1(result), choices);
      c2 = choose(&battle.battle_, &random, PKMN_PLAYER_P2, pkmn_result_p2(result), choices);
      result = battle.play_turn(c1, c2);
   }

   battle.print_result();

   int battles = 50000;
   double agent1_prob = 0.97;
   double agent2_prob = 1;
   auto Agent1 = RandomAgentRBY(agent1_prob);
   auto Agent2 = RandomAgentRBY(agent2_prob);
   std::vector<rby_side> teams = {miedon, zapjynx, zamdon, miebro, zamjolt, zambro, miejolt};

   auto battle2 = rby_battle(&Agent1, &Agent2, miedon, miedon, seed);

   int A=0, B=0, C=0;

    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> distrib;

   for(int i=0; i<battles; ++i)
   {
      battle2 = rby_battle(&Agent1, &Agent2, random_team(teams), random_team(teams), distrib(gen));
      battle2.play_battle();
      if(battle2.result == PKMN_RESULT_WIN) {
         ++A;
      }
      else if(battle2.result == PKMN_RESULT_LOSE) {
         ++B;
      } else if(battle2.result == PKMN_RESULT_TIE) {
         ++C;
      } else {
         std::cout << "ERROR" << std::endl;
      }
   }
   std::cout << "After  " << battles << " games:\n";
   std::cout << agent1_prob * 100 << "% move probability\twins: " << A << "\tPercentage: " << ((double)A / battles) * 100 << "%\n";
   std::cout << agent2_prob * 100 << "% move probability\twins: " << B << "\tPercentage: " << ((double)B / battles) * 100 << "%\n";
   std::cout << "\t\t\tTies:  "   << C << "\tPercentage:   " << ((double)C / battles) * 100 << "%\n";

   return 0;
}
