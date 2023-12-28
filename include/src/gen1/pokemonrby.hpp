// Copyright pasyg.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "base_stats.hpp"
#include "generation.hpp"
#include "move.hpp"
#include "species.hpp"
#include "types.hpp"

namespace engine
{
namespace RBY
{
    template<Gen gen>
    struct Pokemon;
        
    inline constexpr std::uint16_t calc_other_stat(Pokemon<Gen::RBY>& poke, Stat stat_);
    inline constexpr std::uint16_t calc_hp(Pokemon<Gen::RBY>& poke);

    /// @brief container class to create and store byte representation of a Pokemon
    template<>
    struct Pokemon<Gen::RBY>
    {
        /// @brief stores byte information of the Pokemon
        std::array<std::uint8_t, 24> bytes{ };

        /// @brief Constructor to create byte representation of the Pokemon
        /// @param p_species species of the Pokemon
        /// @param p_moves   moveset of the Pokemon
        /// @param p_level   level of the Pokemon, defaulted to 100
        constexpr Pokemon(Species p_species, std::array<Move, 4> p_moves, int p_level=100)
        {
            bytes[20]   = 0; // status
            bytes[21]   = p_species;
            bytes[23]   = p_level;
            
            base = get_base_stats(bytes[21]);

            bytes[22] = get_type(p_species)[0] | (get_type(p_species)[1] << 4);

            bytes[10] = p_moves[0];
            bytes[11] = move_pp(p_moves[0]);
            bytes[12] = p_moves[1];
            bytes[13] = move_pp(p_moves[1]);
            bytes[14] = p_moves[2];
            bytes[15] = move_pp(p_moves[2]);
            bytes[16] = p_moves[3];
            bytes[17] = move_pp(p_moves[3]);

            calc_stats();

            // this sounds rough but we are killing None here before it had a chance to live
            if(p_species == None)
            {
                bytes[18] = 0;
                bytes[19] = 0;
            }
        }

        /// @brief computes and sets the stats hp, atk, def, spe, spec for the Pokemon
        constexpr void calc_stats()
        {
            bytes[0]  = calc_hp(*this);
            bytes[1]  = calc_hp(*this) >> 8;
            bytes[18] = bytes[0];
            bytes[19] = bytes[1];
            bytes[2]  = calc_other_stat(*this, ATK);
            bytes[3]  = calc_other_stat(*this, ATK) >> 8;
            bytes[4]  = calc_other_stat(*this, DEF);
            bytes[5]  = calc_other_stat(*this, DEF) >> 8;
            bytes[6]  = calc_other_stat(*this, SPE);
            bytes[7]  = calc_other_stat(*this, SPE) >> 8;
            bytes[8]  = calc_other_stat(*this, SPC);
            bytes[9]  = calc_other_stat(*this, SPC) >> 8;
        }
        /// @brief  Iterator pointing to the begin of the byte representation
        /// @return Iterator pointing to the begin of the byte representation
        constexpr auto begin()
        {
            return bytes.begin();
        }
        /// @brief  Iterator pointing one behind the last byte of the byte representation
        /// @return Iterator pointing one behind the last byte of the byte representation
        constexpr auto end()
        {
            return bytes.end();
        }
        /// @brief  const Iterator pointing to the begin of the byte representation
        /// @return const Iterator pointing to the begin of the byte representation
        constexpr auto cbegin() const
        {
            return bytes.cbegin();
        }
        /// @brief  const Iterator pointing one behind the last byte of the byte representation
        /// @return const Iterator pointing one behind the last byte of the byte representation
        constexpr auto cend() const
        {
            return bytes.cend();
        }
        /// @brief  amount of bytes of the byte representation
        /// @return amount of bytes of the byte representation
        constexpr auto size() const
        {
            return bytes.size();
        }

        /// @brief stores the base stats of the Pokemon
        std::array<std::uint16_t, 6> base{ };
        /// @brief stores the EV of the Pokemon, defaulted to max
        std::array<int, 6> EV{ 63, 63, 63, 63, 63 };
        /// @brief stores the IV of the Pokemon, defaulted to max
        std::array<int, 6> IV{ 15, 15, 15, 15, 15 };
    };
    /// @brief shortcut for a RBY Pokemon type
    using rby_poke = Pokemon<Gen::RBY>;

    /// @brief computes the HP stat of a Pokemon
    /// @param poke the Pokemon to compute HP stat from
    /// @return the HP stat of poke
    inline constexpr std::uint16_t calc_hp(Pokemon<Gen::RBY>& poke)
    {
        std::uint16_t hp = poke.base[0] + poke.IV[0];
        hp *= 2;
        hp += poke.EV[0];
        // multiply by level
        hp *= poke.bytes[23];
        hp /= 100;
        hp += poke.bytes[23] + 10;

        return hp;
    }

    /// @brief computes ATK, DEF, SPE and SPEC of a Pokemon
    /// @param poke  Pokemon to compute stat value from
    /// @param stat_ specifies the stat to compute
    /// @return the computed stat of poke
    inline constexpr std::uint16_t calc_other_stat(Pokemon<Gen::RBY>& poke, Stat stat_)
    {
        std::uint16_t stat = poke.base[stat_] + poke.IV[stat_];
        stat *= 2;
        stat += poke.EV[stat_];
        // multiply by level
        stat *= poke.bytes[23];
        stat /= 100;
        stat += 5;

        return stat;
    }
} // namespace RBY
} // namespace engine