// Copyright pasyg.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "sidesample.hpp"
#include "battlerby.hpp"

/*
* Sample compiletime Battles to play around with
*
*/

namespace wrapsire {
namespace RBY {
    // example instantiaion with predefined sides
    constexpr Battle<Gen::RBY> miedon_miedon  = rby_battle(miedon, miedon, 2291);
    constexpr Battle<Gen::RBY> miedon_zapjynx = rby_battle(miedon, zapjynx, 2290);
    constexpr Battle<Gen::RBY> LaxVsDon       = rby_battle(monolax, monodon, 0);

    // example for completely fresh battle instantiation
    constexpr Battle<Gen::RBY> miezam_zamdon  = rby_battle(
                                                            make_side(rby_poke(Starmie,   {Surf, Psychic, Recover, ThunderWave}),
                                                                      rby_poke(Snorlax,   {BodySlam, IceBeam, Reflect, Rest}),
                                                                      rby_poke(Chansey,   {IceBeam, SeismicToss, Sing, SoftBoiled}),
                                                                      rby_poke(Exeggutor, {Psychic, DoubleEdge, SleepPowder, Explosion}),
                                                                      rby_poke(Tauros,    {BodySlam, HyperBeam, Earthquake, Blizzard}),
                                                                      rby_poke(Alakazam,  {Psychic, SeismicToss, ThunderWave, Recover})),
                                                            make_side(rby_poke(Alakazam,  {Psychic, SeismicToss, ThunderWave, Recover}),
                                                                      rby_poke(Snorlax,   {BodySlam, Earthquake, HyperBeam, SelfDestruct}),
                                                                      rby_poke(Chansey,   {Thunderbolt, IceBeam, ThunderWave, SoftBoiled}),
                                                                      rby_poke(Exeggutor, {Psychic, DoubleEdge, SleepPowder, Explosion}),
                                                                      rby_poke(Tauros,    {BodySlam, HyperBeam, Earthquake, Blizzard}),
                                                                      rby_poke(Rhydon,    {BodySlam, Earthquake, Substitute, Rest})),
                                                            0xf5a8b3958a2ef6c8);
} // namespace RBY
} // namespace wrapsire