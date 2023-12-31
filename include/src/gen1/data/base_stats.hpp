// Copyright pasyg.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <array>

#include "species.hpp"

namespace wrapsire {
namespace RBY {
    // skip special defense, due to reusability reasons.
    enum Stat : uint8_t {
        HP   = 0,
        ATK  = 1,
        DEF  = 2,
        SPE  = 3,
        SPC  = 4,
    };

    constexpr std::array<std::uint16_t, 6> get_base_stats(std::uint8_t species) {
        switch (species) {
            case RBY::Species::None:
                return {0, 0, 0, 0, 0};                             
            case RBY::Species::Bulbasaur:
                return {45, 49, 49, 65, 45};             
            case RBY::Species::Ivysaur:
                return {60, 62, 63, 80, 60};             
            case RBY::Species::Venusaur:
                return {80, 82, 83, 100, 80 };            
            case RBY::Species::Charmander:
                return {39, 52, 43, 65, 50};             
            case RBY::Species::Charmeleon:
                return {58, 64, 58, 80, 65};             
            case RBY::Species::Charizard:
                return {78, 84, 78, 100, 85 };            
            case RBY::Species::Squirtle:
                return {44, 48, 65, 43, 50};             
            case RBY::Species::Wartortle:
                return {59, 63, 80, 58, 65};             
            case RBY::Species::Blastoise:
                return {79, 83, 100, 78, 85};             
            case RBY::Species::Caterpie:
                return {45, 30, 35, 45, 20};             
            case RBY::Species::Metapod:
                return {50, 20, 55, 30, 25};             
            case RBY::Species::Butterfree:
                return {60, 45, 50, 70, 80};             
            case RBY::Species::Weedle:
                return {40, 35, 30, 50, 20};             
            case RBY::Species::Kakuna:
                return {45, 25, 50, 35, 25};             
            case RBY::Species::Beedrill:
                return {65, 80, 40, 75, 45};             
            case RBY::Species::Pidgey:
                return {40, 45, 40, 56, 35};             
            case RBY::Species::Pidgeotto:
                return {63, 60, 55, 71, 50};             
            case RBY::Species::Pidgeot:
                return {83, 80, 75, 91, 70};             
            case RBY::Species::Rattata:
                return {30, 56, 35, 72, 25};             
            case RBY::Species::Raticate:
                return {55, 81, 60, 97, 50};             
            case RBY::Species::Spearow:
                return {40, 60, 30, 70, 31};             
            case RBY::Species::Fearow:
                return {65, 90, 65, 100, 61 };            
            case RBY::Species::Ekans:
                return {35, 60, 44, 55, 40};             
            case RBY::Species::Arbok:
                return {60, 85, 69, 80, 65};             
            case RBY::Species::Pikachu:
                return {35, 55, 30, 90, 50};             
            case RBY::Species::Raichu:
                return {60, 90, 55, 100, 90 };            
            case RBY::Species::Sandshrew:
                return {50, 75, 85, 40, 30};             
            case RBY::Species::Sandslash:
                return {75, 100, 110, 65, 55};             
            case RBY::Species::Nidoran_F:
                return {55, 47, 52, 41, 40};             
            case RBY::Species::Nidorina:
                return {70, 62, 67, 56, 55};             
            case RBY::Species::Nidoqueen:
                return {90, 82, 87, 76, 75};             
            case RBY::Species::Nidoran_M:
                return {46, 57, 40, 50, 40};             
            case RBY::Species::Nidorino:
                return {61, 72, 57, 65, 55};             
            case RBY::Species::Nidoking:
                return {81, 92, 77, 85, 75};             
            case RBY::Species::Clefairy:
                return {70, 45, 48, 35, 60};             
            case RBY::Species::Clefable:
                return {95, 70, 73, 60, 85};             
            case RBY::Species::Vulpix:
                return {38, 41, 40, 65, 65};             
            case RBY::Species::Ninetales:
                return {73, 76, 75, 100, 100};            
            case RBY::Species::Jigglypuff:
                return {115, 45, 20, 20, 25};             
            case RBY::Species::Wigglytuff:
                return {140, 70, 45, 45, 50};             
            case RBY::Species::Zubat:
                return {40, 45, 35, 55, 40};             
            case RBY::Species::Golbat:
                return {75, 80, 70, 90, 75};             
            case RBY::Species::Oddish:
                return {45, 50, 55, 30, 75};             
            case RBY::Species::Gloom:
                return {60, 65, 70, 40, 85};             
            case RBY::Species::Vileplume:
                return {75, 80, 85, 50, 100};             
            case RBY::Species::Paras:
                return {35, 70, 55, 25, 55};             
            case RBY::Species::Parasect:
                return {60, 95, 80, 30, 80};             
            case RBY::Species::Venonat:
                return {60, 55, 50, 45, 40};             
            case RBY::Species::Venomoth:
                return {70, 65, 60, 90, 90};             
            case RBY::Species::Diglett:
                return {10, 55, 25, 95, 45};             
            case RBY::Species::Dugtrio:
                return {35, 80, 50, 120, 70 };            
            case RBY::Species::Meowth:
                return {40, 45, 35, 90, 40};             
            case RBY::Species::Persian:
                return {65, 70, 60, 115, 65 };            
            case RBY::Species::Psyduck:
                return {50, 52, 48, 55, 50};             
            case RBY::Species::Golduck:
                return {80, 82, 78, 85, 80};             
            case RBY::Species::Mankey:
                return {40, 80, 35, 70, 35};             
            case RBY::Species::Primeape:
                return {65, 105, 60, 95, 60};             
            case RBY::Species::Growlithe:
                return {55, 70, 45, 60, 50};             
            case RBY::Species::Arcanine:
                return {90, 110, 80, 95, 80};             
            case RBY::Species::Poliwag:
                return {40, 50, 40, 90, 40};             
            case RBY::Species::Poliwhirl:
                return {65, 65, 65, 90, 50};             
            case RBY::Species::Poliwrath:
                return {90, 85, 95, 70, 70};             
            case RBY::Species::Abra:
                return {25, 20, 15, 90, 105};             
            case RBY::Species::Kadabra:
                return {40, 35, 30, 105, 120};            
            case RBY::Species::Alakazam:
                return {55, 50, 45, 120, 135};            
            case RBY::Species::Machop:
                return {70, 80, 50, 35, 35};             
            case RBY::Species::Machoke:
                return {80, 100, 70, 45, 50};             
            case RBY::Species::Machamp:
                return {90, 130, 80, 55, 65};             
            case RBY::Species::Bellsprout:
                return {50, 75, 35, 40, 70};             
            case RBY::Species::Weepinbell:
                return {65, 90, 50, 55, 85};             
            case RBY::Species::Victreebel:
                return {80, 105, 65, 70, 100};             
            case RBY::Species::Tentacool:
                return {40, 40, 35, 70, 100};             
            case RBY::Species::Tentacruel:
                return {80, 70, 65, 100, 120};             
            case RBY::Species::Geodude:
                return {40, 80, 100, 20, 30};             
            case RBY::Species::Graveler:
                return {55, 95, 115, 35, 45};             
            case RBY::Species::Golem:
                return {80, 110, 130, 45, 55};             
            case RBY::Species::Ponyta:
                return {50, 85, 55, 90, 65};             
            case RBY::Species::Rapidash:
                return {65, 100, 70, 105, 80 };            
            case RBY::Species::Slowpoke:
                return {90, 65, 65, 15, 40};             
            case RBY::Species::Slowbro:
                return {95, 75, 110, 30, 80};             
            case RBY::Species::Magnemite:
                return {25, 35, 70, 45, 95};             
            case RBY::Species::Magneton:
                return {50, 60, 95, 70, 120};             
            case RBY::Species::Farfetchd:
                return {52, 65, 55, 60, 58};             
            case RBY::Species::Doduo:
                return {35, 85, 45, 75, 35};             
            case RBY::Species::Dodrio:
                return {60, 110, 70, 100, 60 };            
            case RBY::Species::Seel:
                return {65, 45, 55, 45, 70};             
            case RBY::Species::Dewgong:
                return {90, 70, 80, 70, 95};             
            case RBY::Species::Grimer:
                return {80, 80, 50, 25, 40};             
            case RBY::Species::Muk:
                return {105, 105, 75, 50, 65};             
            case RBY::Species::Shellder:
                return {30, 65, 100, 40, 45};             
            case RBY::Species::Cloyster:
                return {50, 95, 180, 70, 85};             
            case RBY::Species::Gastly:
                return {30, 35, 30, 80, 100};             
            case RBY::Species::Haunter:
                return {45, 50, 45, 95, 115};             
            case RBY::Species::Gengar:
                return {60, 65, 60, 110, 130};            
            case RBY::Species::Onix:
                return {35, 45, 160, 70, 30};             
            case RBY::Species::Drowzee:
                return {60, 48, 45, 42, 90};             
            case RBY::Species::Hypno:
                return {85, 73, 70, 67, 115};             
            case RBY::Species::Krabby:
                return {30, 105, 90, 50, 25};             
            case RBY::Species::Kingler:
                return {55, 130, 115, 75, 50};             
            case RBY::Species::Voltorb:
                return {40, 30, 50, 100, 55 };            
            case RBY::Species::Electrode:
                return {60, 50, 70, 140, 80 };            
            case RBY::Species::Exeggcute:
                return {60, 40, 80, 40, 60};             
            case RBY::Species::Exeggutor:
                return {95, 95, 85, 55, 125};             
            case RBY::Species::Cubone:
                return {50, 50, 95, 35, 40};             
            case RBY::Species::Marowak:
                return {60, 80, 110, 45, 50};             
            case RBY::Species::Hitmonlee:
                return {50, 120, 53, 87, 35};             
            case RBY::Species::Hitmonchan:
                return {50, 105, 79, 76, 35};             
            case RBY::Species::Lickitung:
                return {90, 55, 75, 30, 60};             
            case RBY::Species::Koffing:
                return {40, 65, 95, 35, 60};             
            case RBY::Species::Weezing:
                return {65, 90, 120, 60, 85};             
            case RBY::Species::Rhyhorn:
                return {80, 85, 95, 25, 30};             
            case RBY::Species::Rhydon:
                return {105, 130, 120, 40, 45};             
            case RBY::Species::Chansey:
                return {250, 5, 5, 50, 105};             
            case RBY::Species::Tangela:
                return {65, 55, 115, 60, 100};             
            case RBY::Species::Kangaskhan:
                return {105, 95, 80, 90, 40};             
            case RBY::Species::Horsea:
                return {30, 40, 70, 60, 70};             
            case RBY::Species::Seadra:
                return {55, 65, 95, 85, 95};             
            case RBY::Species::Goldeen:
                return {45, 67, 60, 63, 50};             
            case RBY::Species::Seaking:
                return {80, 92, 65, 68, 80};             
            case RBY::Species::Staryu:
                return {30, 45, 55, 85, 70};             
            case RBY::Species::Starmie:
                return {60, 75, 85, 115, 100};            
            case RBY::Species::Mr_Mime:
                return {40, 45, 65, 90, 100};             
            case RBY::Species::Scyther:
                return {70, 110, 80, 105, 55 };            
            case RBY::Species::Jynx:
                return {65, 50, 35, 95, 95};             
            case RBY::Species::Electabuzz:
                return {65, 83, 57, 105, 85 };            
            case RBY::Species::Magmar:
                return {65, 95, 57, 93, 85};             
            case RBY::Species::Pinsir:
                return {65, 125, 100, 85, 55};             
            case RBY::Species::Tauros:
                return {75, 100, 95, 110, 70 };            
            case RBY::Species::Magikarp:
                return {20, 10, 55, 80, 20};             
            case RBY::Species::Gyarados:
                return {95, 125, 79, 81, 100};             
            case RBY::Species::Lapras:
                return {130, 85, 80, 60, 95};             
            case RBY::Species::Ditto:
                return {48, 48, 48, 48, 48};             
            case RBY::Species::Eevee:
                return {55, 55, 50, 55, 65};             
            case RBY::Species::Vaporeon:
                return {130, 65, 60, 65, 110};             
            case RBY::Species::Jolteon:
                return {65, 65, 60, 130, 110};            
            case RBY::Species::Flareon:
                return {65, 130, 60, 65, 110};             
            case RBY::Species::Porygon:
                return {65, 60, 70, 40, 75};             
            case RBY::Species::Omanyte:
                return {35, 40, 100, 35, 90};             
            case RBY::Species::Omastar:
                return {70, 60, 125, 55, 115};             
            case RBY::Species::Kabuto:
                return {30, 80, 90, 55, 45};             
            case RBY::Species::Kabutops:
                return {60, 115, 105, 80, 70};             
            case RBY::Species::Aerodactyl:
                return {80, 105, 65, 130, 60 };            
            case RBY::Species::Snorlax:
                return {160, 110, 65, 30, 65};             
            case RBY::Species::Articuno:
                return {90, 85, 100, 85, 125};             
            case RBY::Species::Zapdos:
                return {90, 90, 85, 100, 125};            
            case RBY::Species::Moltres:
                return {90, 100, 90, 90, 125};             
            case RBY::Species::Dratini:
                return {41, 64, 45, 50, 50};             
            case RBY::Species::Dragonair:
                return {61, 84, 65, 70, 70};             
            case RBY::Species::Dragonite:
                return {91, 134, 95, 80, 100};             
            case RBY::Species::Mewtwo:
                return {106, 110, 90, 130, 154};            
            case RBY::Species::Mew:
                return {100, 100, 100, 100, 100};
        }
    }
} // namespace RBY
} // namespace wrapsire