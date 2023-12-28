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

namespace engine
{
namespace RBY
{
    /// @brief Starmie and Rhydon with standard 4
    static constexpr Side miedon  = make_side(starmie, chansey, snorlax, tauros, exegg, rhydon);
    /// @brief Zapdos and Jynx with standard 4
    static constexpr Side zapjynx = make_side(jynx, chansey, snorlax, tauros, exegg, zapdos);
    /// @brief Zapdos and Jynx with standard 4
    static constexpr Side zamdon = make_side(alakazam, chansey, snorlax, tauros, exegg, rhydon);
    /// @brief Zapdos and Jynx with standard 4
    static constexpr Side miebro = make_side(starmie, chansey, snorlax, tauros, exegg, slowbro);
    /// @brief Zapdos and Jynx with standard 4
    static constexpr Side zamjolt = make_side(alakazam, chansey, snorlax, tauros, exegg, jolteon);
    /// @brief Zapdos and Jynx with standard 4
    static constexpr Side zambro = make_side(alakazam, chansey, snorlax, tauros, exegg, slowbro);
    /// @brief Zapdos and Jynx with standard 4
    static constexpr Side miejolt = make_side(starmie, chansey, snorlax, tauros, exegg, jolteon);
    /// @brief Just a Snorlax
    static constexpr Side monolax = make_side(snorlax, none, none, none, none, none);
    /// @brief Just a Tauros
    static constexpr Side monodon = make_side(rhydon, none, none, none, none, none);
} // namespace RBY
} // namespace engine