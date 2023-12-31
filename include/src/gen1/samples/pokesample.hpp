#pragma once

#include "pokemonrby.hpp"

/*
* Sample compiletime Pokemon objects to pass into teams
*
*/

namespace wrapsire {
namespace RBY {
    /// @brief placeholder to create Side with less than 6 members
    constexpr Pokemon none     = rby_poke(None, {None_, None_, None_, None_});
    /// @brief Standard Alakazam set
    constexpr Pokemon alakazam = rby_poke(Alakazam,  {SeismicToss, Psychic, Recover, ThunderWave}); 
    /// @brief Standard Chansey set
    constexpr Pokemon chansey  = rby_poke(Chansey,   {IceBeam, SeismicToss, ThunderWave, SoftBoiled});
    /// @brief Standard Cloyster set
    constexpr Pokemon cloyster = rby_poke(Cloyster,  {Clamp, Blizzard, Explosion, Rest});
    /// @brief Standard Exeggutor set
    constexpr Pokemon exegg    = rby_poke(Exeggutor, {SleepPowder, Psychic, Explosion, DoubleEdge});
    /// @brief Standard Gengar set
    constexpr Pokemon gengar   = rby_poke(Gengar,    {Hypnosis, Thunderbolt, NightShade, Explosion});
    /// @brief Standard Jolteon set
    constexpr Pokemon jolteon  = rby_poke(Jolteon,   {Thunderbolt, ThunderWave, DoubleKick, Rest});
    /// @brief Standard Jynx set
    constexpr Pokemon jynx     = rby_poke(Jynx,      {LovelyKiss, Psychic, IceBeam, Rest});
    /// @brief Standard Rhydon set
    constexpr Pokemon rhydon   = rby_poke(Rhydon,    {Earthquake, RockSlide, BodySlam, Substitute});
    /// @brief Standard Slowbro set
    constexpr Pokemon slowbro  = rby_poke(Slowbro,   {Amnesia, Surf, Reflect, Rest});
    /// @brief Offensive Snorlax set
    constexpr Pokemon snorlax  = rby_poke(Snorlax,   {BodySlam, Earthquake, HyperBeam, SelfDestruct});
    /// @brief Standard Starmie set
    constexpr Pokemon starmie  = rby_poke(Starmie,   {Surf, Blizzard, ThunderWave, Recover});
    /// @brief Standard Tauros set
    constexpr Pokemon tauros   = rby_poke(Tauros,    {BodySlam, Earthquake, Blizzard, HyperBeam});
    /// @brief Standard Zapdos set
    constexpr Pokemon zapdos   = rby_poke(Zapdos,    {Thunderbolt, DrillPeck, Agility, ThunderWave});
} // namespace RBY
} // namespace wrapsire