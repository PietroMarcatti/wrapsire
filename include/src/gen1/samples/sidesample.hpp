// Copyright pasyg.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "pokesample.hpp"
#include "siderby.hpp"

/*
* Sample compiletime Team objects to pass into battles
*
*/

namespace wrapsire {
namespace RBY {
    /// @brief Starmie and Rhydon with standard 4
    constexpr Side miedon  = make_side(starmie, chansey, snorlax, tauros, exegg, rhydon);
    /// @brief Zapdos and Jynx with standard 4
    constexpr Side zapjynx = make_side(jynx, chansey, snorlax, tauros, exegg, zapdos);
    /// @brief Zapdos and Jynx with standard 4
    constexpr Side zamdon = make_side(alakazam, chansey, snorlax, tauros, exegg, rhydon);
    /// @brief Zapdos and Jynx with standard 4
    constexpr Side miebro = make_side(starmie, chansey, snorlax, tauros, exegg, slowbro);
    /// @brief Zapdos and Jynx with standard 4
    constexpr Side zamjolt = make_side(alakazam, chansey, snorlax, tauros, exegg, jolteon);
    /// @brief Zapdos and Jynx with standard 4
    constexpr Side zambro = make_side(alakazam, chansey, snorlax, tauros, exegg, slowbro);
    /// @brief Zapdos and Jynx with standard 4
    constexpr Side miejolt = make_side(starmie, chansey, snorlax, tauros, exegg, jolteon);
    /// @brief Just a Snorlax
    constexpr Side monolax = make_side(snorlax, none, none, none, none, none);
    /// @brief Just a Tauros
    constexpr Side monodon = make_side(rhydon, none, none, none, none, none);
} // namespace RBY
} // namespace wrapsire