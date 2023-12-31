// Copyright pasyg.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <algorithm>

#include "pokemonrby.hpp"

namespace wrapsire {
namespace RBY {
    template<Gen gen>
    struct Side;
    
    /// @brief container class to create and store byte representation of a Side
    template<>
    struct Side<Gen::RBY> {
        /// @brief stores byte representation of the Side
        std::array<std::uint8_t, 184> bytes{ 0 };

        /// @brief Constructor to create byte representation of the Side
        /// empty default constructor
        constexpr Side() {
            
        }
        /// @brief Constructor to create byte representation of the Side
        /// @param pmember array of Pokemon that make up the Side
        template<typename ConT>
        constexpr Side(const ConT& side) {
            init(side);
        }
        template<typename ConT>
        constexpr void init(const ConT& pmember) {
            // braindamage or genius???
            for(int i = 0; i < 24; ++i) {
                *(bytes.begin() + i)        = *(pmember[0].bytes.begin() + i);
                *(bytes.begin() + i + 24)   = *(pmember[1].bytes.begin() + i);
                *(bytes.begin() + i + 48)   = *(pmember[2].bytes.begin() + i);
                *(bytes.begin() + i + 72)   = *(pmember[3].bytes.begin() + i);
                *(bytes.begin() + i + 96)   = *(pmember[4].bytes.begin() + i);
                *(bytes.begin() + i + 120)  = *(pmember[5].bytes.begin() + i);
            }

            // set active pokemon as first pokemon on the team
            // stats
            bytes[144] = pmember[0].bytes[0];
            bytes[145] = pmember[0].bytes[1];
            bytes[146] = pmember[0].bytes[2];
            bytes[147] = pmember[0].bytes[3];
            bytes[148] = pmember[0].bytes[4];
            bytes[149] = pmember[0].bytes[5];
            bytes[150] = pmember[0].bytes[6];
            bytes[151] = pmember[0].bytes[7];
            bytes[152] = pmember[0].bytes[8];
            bytes[153] = pmember[0].bytes[9];
            // species
            bytes[154] = pmember[0].bytes[21];
            // types
            bytes[155] = pmember[0].bytes[22];
            // boosts
            bytes[156] = 0;
            bytes[157] = 0;
            bytes[158] = 0;
            // zero padding
            bytes[159] = 0;
            // volatiles
            bytes[160] = 0;
            bytes[161] = 0;
            bytes[162] = 0;
            bytes[163] = 0;
            bytes[164] = 0;
            bytes[165] = 0;
            bytes[166] = 0;
            bytes[167] = 0;
            // moves
            bytes[168] = pmember[0].bytes[10];
            bytes[169] = pmember[0].bytes[11];
            bytes[170] = pmember[0].bytes[12];
            bytes[171] = pmember[0].bytes[13];
            bytes[172] = pmember[0].bytes[14];
            bytes[173] = pmember[0].bytes[15];
            bytes[174] = pmember[0].bytes[16];
            bytes[175] = pmember[0].bytes[17];

            bytes[176] = 1;
            bytes[177] = 2;
            bytes[178] = 3;
            bytes[179] = 4;
            bytes[180] = 5;
            bytes[181] = 6;
        }

        /// @brief  Iterator pointing to the begin of the byte representation
        /// @return Iterator pointing to the begin of the byte representation
        constexpr auto begin() { 
            return bytes.begin(); 
        }
        /// @brief  Iterator pointing one behind the last byte of the byte representation
        /// @return Iterator pointing one behind the last byte of the byte representation
        constexpr auto end() {
            return bytes.end();
        }
        /// @brief  const Iterator pointing to the begin of the byte representation
        /// @return const Iterator pointing to the begin of the byte representation
        constexpr auto cbegin() const { 
            return bytes.cbegin(); 
        }
        /// @brief  const Iterator pointing one behind the last byte of the byte representation
        /// @return const Iterator pointing one behind the last byte of the byte representation
        constexpr auto cend() const {
            return bytes.cend();
        }
        /// @brief  amount of bytes of the byte representation
        /// @return amount of bytes of the byte representation
        constexpr auto size() const {
            return bytes.size();
        }
    };
    /// @brief shortcut for a RBY Side type
    using rby_side = Side<Gen::RBY>;

    template<typename ConT>
    constexpr rby_side make_side(ConT side) {
        return rby_side(side);
    }

    constexpr rby_side make_side(const rby_poke& p1, 
                                 const rby_poke& p2, 
                                 const rby_poke& p3, 
                                 const rby_poke& p4, 
                                 const rby_poke& p5, 
                                 const rby_poke& p6) {
        return rby_side(std::array<rby_poke, 6>{p1, p2, p3, p4, p5, p6});
    }
} // namespace RBY
} // namespace wrapsire