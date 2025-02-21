#include "wrapsire.hpp"

#include <chrono>
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
//10223443
int main(int argc, char **argv)
{
   using namespace wrapsire::RBY;
   auto start = std::chrono::high_resolution_clock::now();
   for (int i = 0; i < 1000000; i++) {
       auto battle = wrapsire::RBY::miedon_zapjynx;
       pkmn_result result = PKMN_RESULT_NONE;
       pkmn_choice c1;
       pkmn_choice c2;
       pkmn_psrng random;
       uint64_t seed = 0;
       pkmn_psrng_init(&random, seed);
       pkmn_choice choices[9];

       battle.init();

       while (!pkmn_result_type(battle.result))
       {
           c1 = choose(battle(), &random, PKMN_PLAYER_P1, pkmn_result_p1(battle.result), choices);
           c2 = choose(battle(), &random, PKMN_PLAYER_P2, pkmn_result_p2(battle.result), choices);
           battle.play_turn(c1, c2);
       }
       //battle.print_result();
   }
   auto stop = std::chrono::high_resolution_clock::now();
   auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
   std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

   return 0;
}
