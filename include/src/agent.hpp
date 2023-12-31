// Copyright pasyg.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "generation.hpp"

/*
* Abstract templated class to derive Agents for different generations from
*/
namespace wrapsire {
    template<Gen gen, typename GameState, typename Choice>
    struct Agent {
        pkmn_player player;
        GameState* gamestate = nullptr;
        virtual Choice make_choice() = 0;
    };

    // Generation specific Agent typedefs
    typedef Agent<Gen::RBY, pkmn_gen1_battle, pkmn_choice> AgentRBY;
} // namespace wrapsire
