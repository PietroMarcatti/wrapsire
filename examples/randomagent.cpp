#include "wrapsire.hpp"

#include "agents/random.hpp"


// Can be used to randomly pick a team out of a container
template<typename Container>
typename Container::value_type random_team(const Container& teams) {
   static std::random_device rd;
   static std::mt19937 gen(rd());
   static std::uniform_int_distribution<> distrib(0, teams.size() - 1);
   return teams[distrib(gen)];
}

int main() {
    using namespace wrapsire::RBY;

    int battles = 10000;
    uint64_t seed = 0;

    // The probabilities for the agents to select a move over a switch
    double agent1_prob = 0.5;
    double agent2_prob = 0.75;

    auto Agent1 = RandomAgentRBY(agent1_prob);
    auto Agent2 = RandomAgentRBY(agent2_prob);

    // Sample teams
    std::vector<rby_side> teams = {miedon, zamdon, zapjynx, miebro, zamjolt, zambro, miejolt};

    // Counting variables for battle results
    int A=0, B=0, C=0;

    // RNG for battle seeds
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> distrib;

    // play out each matchup #battles of time
    // and count the wins/ties
    auto battle = rby_battle(&Agent1, &Agent2, zamdon, miebro, distrib(gen));
    for(auto&& team : teams) {
        for(auto&& team_ : teams) {
            for(int i = 0; i < battles; ++i) {
                battle = rby_battle(&Agent1, &Agent2, team, team_, distrib(gen));
                battle.play_battle();

                if(battle.result == PKMN_RESULT_WIN) {
                    ++A;
                } else if(battle.result == PKMN_RESULT_LOSE) {
                    ++B;
                } else if(battle.result == PKMN_RESULT_TIE) {
                    ++C;
                } else {
                    std::cout << "ERROR" << std::endl;
                    assert(false);
                }
            }
        }
    }

    int totalBattles = teams.size() * teams.size() * battles;
    
    std::cout << "After  " << totalBattles << " games:\n";
    std::cout << agent1_prob * 100 << "% move probability\twins: " << A << "\tPercentage: " << ((double)A / totalBattles) * 100 << "%\n";
    std::cout << agent2_prob * 100 << "% move probability\twins: " << B << "\tPercentage: " << ((double)B / totalBattles) * 100 << "%\n";
    std::cout << "\t\t\tTies:  "   << C << "\tPercentage: " << ((double)C / totalBattles) * 100 << "%\n";

    return 0;
}