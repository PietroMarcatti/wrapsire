// Copyright pasyg.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "agent.hpp"
#include "battlerby.hpp"

#include <random>

namespace wrapsire {
namespace RBY {
    struct RandomAgentRBY : AgentRBY {
        std::mt19937 rng;
        std::uniform_real_distribution<double> dist;
        double move_prob = 1.0;
        RandomAgentRBY(double MoveProb) :
            rng(std::random_device{}()), dist(0.0, 1.0), move_prob(MoveProb) {}

        pkmn_choice make_choice() {
            pkmn_choice move_choices[9];
            pkmn_choice switch_choices[9];
            uint8_t moves_n    = pkmn_gen1_battle_choices(gamestate, player, PKMN_CHOICE_MOVE, move_choices, PKMN_CHOICES_SIZE);
            uint8_t switches_n = pkmn_gen1_battle_choices(gamestate, player, PKMN_CHOICE_SWITCH, switch_choices, PKMN_CHOICES_SIZE);
            
            if (moves_n > 0) {
                if (switches_n > 0) {
                    // Both moves and switches are available
                    if (dist(rng) < move_prob) {
                        // Choose a move
                        return move_choices[std::uniform_int_distribution<>(0, moves_n - 1)(rng)];
                    } else {
                        // Choose a switch
                        return switch_choices[std::uniform_int_distribution<>(0, switches_n - 1)(rng)];
                    }
                } else {
                    // Only moves are available
                    return move_choices[std::uniform_int_distribution<>(0, moves_n - 1)(rng)];
                }
            } else if (switches_n > 0) {
                // Only switches are available
                return switch_choices[std::uniform_int_distribution<>(0, switches_n - 1)(rng)];
            } else {
                throw std::logic_error("No moves and switches available");
            }
        }
    };
} // namespace RBY
} // namespace wrapsire
