#include "wrapsire.hpp"

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using namespace engine::RBY;
using Pokebytes = std::array<std::uint8_t, 24>;

constexpr Pokemon test_alakazam  = rby_poke(Alakazam, {SeismicToss, Psychic, Recover, ThunderWave}); 
constexpr Pokebytes exp_alakazam = {0x39, 0x01, 0xc6, 0x00, 0xbc, 0x00, 0x52, 0x01, 0x70, 0x01, 0x45, 0x20, 
                                    0x5e, 0x10, 0x69, 0x20, 0x56, 0x20, 0x39, 0x01, 0x00, 0x41, 0xcc, 0x64};
    
constexpr Pokemon test_chansey   = rby_poke(Chansey,  {IceBeam, SeismicToss, ThunderWave, SoftBoiled});
constexpr Pokebytes exp_chansey  = {0xbf, 0x02, 0x6c, 0x00, 0x6c, 0x00, 0xc6, 0x00, 0x34, 0x01, 0x3a, 0x10, 
                                    0x45, 0x20, 0x56, 0x20, 0x87, 0x10, 0xbf, 0x02, 0x00, 0x71, 0x00, 0x64};

constexpr Pokemon test_cloyster  = rby_poke(Cloyster, {Clamp, Blizzard, Explosion, Rest});
constexpr Pokebytes exp_cloyster = {0x2f, 0x01, 0x20, 0x01, 0xca, 0x01, 0xee, 0x00, 0x0c, 0x01, 0x80, 0x10, 
                                    0x3b, 0x08, 0x99, 0x08, 0x9c, 0x10, 0x2f, 0x01, 0x00, 0x5b, 0xd9, 0x64};

constexpr Pokemon test_exegg     = rby_poke(Exeggutor,{SleepPowder, Psychic, Explosion, DoubleEdge});
constexpr Pokebytes exp_exegg    = {0x89, 0x01, 0x20, 0x01, 0x0c, 0x01, 0xd0, 0x00, 0x5c, 0x01, 0x4f, 0x18, 
                                    0x5e, 0x10, 0x99, 0x08, 0x26, 0x18, 0x89, 0x01, 0x00, 0x67, 0xca, 0x64};

constexpr Pokemon test_gengar    = rby_poke(Gengar,   {Hypnosis, Thunderbolt, NightShade, Explosion});
constexpr Pokebytes exp_gengar   = {0x43, 0x01, 0xe4, 0x00, 0xda, 0x00, 0x3e, 0x01, 0x66, 0x01, 0x5f, 0x20, 
                                    0x55, 0x18, 0x65, 0x18, 0x99, 0x08, 0x43, 0x01, 0x00, 0x5e, 0x37, 0x64};

constexpr Pokemon test_jolteon   = rby_poke(Jolteon,  {Thunderbolt, ThunderWave, DoubleKick, Rest});
constexpr Pokebytes exp_jolteon  = {0x4d, 0x01, 0xe4, 0x00, 0xda, 0x00, 0x66, 0x01, 0x3e, 0x01, 0x55, 0x18, 
                                    0x56, 0x20, 0x18, 0x30, 0x9c, 0x10, 0x4d, 0x01, 0x00, 0x87, 0xbb, 0x64};

constexpr Pokemon test_jynx      = rby_poke(Jynx,     {LovelyKiss, Psychic, IceBeam, Rest});
constexpr Pokebytes exp_jynx     = {0x4d, 0x01, 0xc6, 0x00, 0xa8, 0x00, 0x20, 0x01, 0x20, 0x01, 0x8e, 0x10, 
                                    0x5e, 0x10, 0x3a, 0x10, 0x9c, 0x10, 0x4d, 0x01, 0x00, 0x7c, 0xcd, 0x64};

constexpr Pokemon test_rhydon    = rby_poke(Rhydon,   {Earthquake, RockSlide, BodySlam, Substitute});
constexpr Pokebytes exp_rhydon   = {0x9d, 0x01, 0x66, 0x01, 0x52, 0x01, 0xb2, 0x00, 0xbc, 0x00, 0x59, 0x10, 
                                    0x9d, 0x10, 0x22, 0x18, 0xa4, 0x10, 0x9d, 0x01, 0x00, 0x70, 0x54, 0x64};

constexpr Pokemon test_slowbro   = rby_poke(Slowbro,  {Amnesia, Surf, Reflect, Rest});
constexpr Pokebytes exp_slowbro  = {0x89, 0x01, 0xf8, 0x00, 0x3e, 0x01, 0x9e, 0x00, 0x02, 0x01, 0x85, 0x20, 
                                    0x39, 0x18, 0x73, 0x20, 0x9c, 0x10, 0x89, 0x01, 0x00, 0x50, 0xc9, 0x64};

constexpr Pokemon test_snorlax   = rby_poke(Snorlax,  {BodySlam, Earthquake, HyperBeam, SelfDestruct});
constexpr Pokebytes exp_snorlax  = {0x0b, 0x02, 0x3e, 0x01, 0xe4, 0x00, 0x9e, 0x00, 0xe4, 0x00, 0x22, 0x18, 
                                    0x59, 0x10, 0x3f, 0x08, 0x78, 0x08, 0x0b, 0x02, 0x00, 0x8f, 0x00, 0x64};

constexpr Pokemon test_starmie   = rby_poke(Starmie,  {Surf, Blizzard, ThunderWave, Recover});
constexpr Pokebytes exp_starmie  = {0x43, 0x01, 0xf8, 0x00, 0x0c, 0x01, 0x48, 0x01, 0x2a, 0x01, 0x39, 0x18, 
                                    0x3b, 0x08, 0x56, 0x20, 0x69, 0x20, 0x43, 0x01, 0x00, 0x79, 0xc9, 0x64};

constexpr Pokemon test_tauros    = rby_poke(Tauros,   {BodySlam, Earthquake, Blizzard, HyperBeam});
constexpr Pokebytes exp_tauros   = {0x61, 0x01, 0x2a, 0x01, 0x20, 0x01, 0x3e, 0x01, 0xee, 0x00, 0x22, 0x18, 
                                    0x59, 0x10, 0x3b, 0x08, 0x3f, 0x08, 0x61, 0x01, 0x00, 0x80, 0x00, 0x64};

constexpr Pokemon test_zapdos    = rby_poke(Zapdos,   {Thunderbolt, DrillPeck, Agility, ThunderWave});
constexpr Pokebytes exp_zapdos   = {0x7f, 0x01, 0x16, 0x01, 0x0c, 0x01, 0x2a, 0x01, 0x5c, 0x01, 0x55, 0x18, 
                                    0x41, 0x20, 0x61, 0x30, 0x56, 0x20, 0x7f, 0x01, 0x00, 0x91, 0x2b, 0x64};

TEST_CASE("test Pokemon instantiation")
{
    CHECK(test_alakazam.bytes == exp_alakazam);
    CHECK(test_chansey.bytes  == exp_chansey);
    CHECK(test_cloyster.bytes == exp_cloyster);
    CHECK(test_exegg.bytes    == exp_exegg);
    CHECK(test_gengar.bytes   == exp_gengar);
    CHECK(test_jolteon.bytes  == exp_jolteon);
    CHECK(test_jynx.bytes     == exp_jynx);
    CHECK(test_rhydon.bytes   == exp_rhydon);
    CHECK(test_slowbro.bytes  == exp_slowbro);
    CHECK(test_snorlax.bytes  == exp_snorlax);
    CHECK(test_starmie.bytes  == exp_starmie);
    CHECK(test_tauros.bytes   == exp_tauros);
    CHECK(test_zapdos.bytes   == exp_zapdos);
}

using Sidebytes = std::array<std::uint8_t, 184>;

constexpr Side test_side1       = make_side(test_alakazam,
                                            test_chansey,
                                            test_cloyster,
                                            test_exegg,
                                            test_gengar,
                                            test_jolteon);
constexpr Sidebytes exp_side1   = {0x39, 0x01, 0xc6, 0x00, 0xbc, 0x00, 0x52, 0x01, 0x70, 0x01, 0x45, 0x20, 0x5e, 0x10, 0x69, 0x20, 0x56, 0x20, 0x39, 0x01, 0x00, 0x41, 0xcc, 0x64, 
                                   0xbf, 0x02, 0x6c, 0x00, 0x6c, 0x00, 0xc6, 0x00, 0x34, 0x01, 0x3a, 0x10, 0x45, 0x20, 0x56, 0x20, 0x87, 0x10, 0xbf, 0x02, 0x00, 0x71, 0x00, 0x64, 
                                   0x2f, 0x01, 0x20, 0x01, 0xca, 0x01, 0xee, 0x00, 0x0c, 0x01, 0x80, 0x10, 0x3b, 0x08, 0x99, 0x08, 0x9c, 0x10, 0x2f, 0x01, 0x00, 0x5b, 0xd9, 0x64, 
                                   0x89, 0x01, 0x20, 0x01, 0x0c, 0x01, 0xd0, 0x00, 0x5c, 0x01, 0x4f, 0x18, 0x5e, 0x10, 0x99, 0x08, 0x26, 0x18, 0x89, 0x01, 0x00, 0x67, 0xca, 0x64, 
                                   0x43, 0x01, 0xe4, 0x00, 0xda, 0x00, 0x3e, 0x01, 0x66, 0x01, 0x5f, 0x20, 0x55, 0x18, 0x65, 0x18, 0x99, 0x08, 0x43, 0x01, 0x00, 0x5e, 0x37, 0x64, 
                                   0x4d, 0x01, 0xe4, 0x00, 0xda, 0x00, 0x66, 0x01, 0x3e, 0x01, 0x55, 0x18, 0x56, 0x20, 0x18, 0x30, 0x9c, 0x10, 0x4d, 0x01, 0x00, 0x87, 0xbb, 0x64, 
                                   0x39, 0x01, 0xc6, 0x00, 0xbc, 0x00, 0x52, 0x01, 0x70, 0x01, 0x41, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                                   0x45, 0x20, 0x5e, 0x10, 0x69, 0x20, 0x56, 0x20, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x00, 0x00};

constexpr Side test_side2       = make_side(test_jynx,
                                            test_rhydon,
                                            test_slowbro,
                                            test_snorlax,
                                            test_starmie,
                                            test_tauros);
constexpr Sidebytes exp_side2   = {0x4d, 0x01, 0xc6, 0x00, 0xa8, 0x00, 0x20, 0x01, 0x20, 0x01, 0x8e, 0x10, 0x5e, 0x10, 0x3a, 0x10, 0x9c, 0x10, 0x4d, 0x01, 0x00, 0x7c, 0xcd, 0x64, 
                                   0x9d, 0x01, 0x66, 0x01, 0x52, 0x01, 0xb2, 0x00, 0xbc, 0x00, 0x59, 0x10, 0x9d, 0x10, 0x22, 0x18, 0xa4, 0x10, 0x9d, 0x01, 0x00, 0x70, 0x54, 0x64, 
                                   0x89, 0x01, 0xf8, 0x00, 0x3e, 0x01, 0x9e, 0x00, 0x02, 0x01, 0x85, 0x20, 0x39, 0x18, 0x73, 0x20, 0x9c, 0x10, 0x89, 0x01, 0x00, 0x50, 0xc9, 0x64, 
                                   0x0b, 0x02, 0x3e, 0x01, 0xe4, 0x00, 0x9e, 0x00, 0xe4, 0x00, 0x22, 0x18, 0x59, 0x10, 0x3f, 0x08, 0x78, 0x08, 0x0b, 0x02, 0x00, 0x8f, 0x00, 0x64, 
                                   0x43, 0x01, 0xf8, 0x00, 0x0c, 0x01, 0x48, 0x01, 0x2a, 0x01, 0x39, 0x18, 0x3b, 0x08, 0x56, 0x20, 0x69, 0x20, 0x43, 0x01, 0x00, 0x79, 0xc9, 0x64, 
                                   0x61, 0x01, 0x2a, 0x01, 0x20, 0x01, 0x3e, 0x01, 0xee, 0x00, 0x22, 0x18, 0x59, 0x10, 0x3b, 0x08, 0x3f, 0x08, 0x61, 0x01, 0x00, 0x80, 0x00, 0x64, 
                                   0x4d, 0x01, 0xc6, 0x00, 0xa8, 0x00, 0x20, 0x01, 0x20, 0x01, 0x7c, 0xcd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                                   0x8e, 0x10, 0x5e, 0x10, 0x3a, 0x10, 0x9c, 0x10, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x00, 0x00};

constexpr Side test_side3       = make_side(test_zapdos,
                                            test_snorlax,
                                            test_tauros,
                                            test_chansey,
                                            test_alakazam,
                                            test_exegg);
constexpr Sidebytes exp_side3   = {0x7f, 0x01, 0x16, 0x01, 0x0c, 0x01, 0x2a, 0x01, 0x5c, 0x01, 0x55, 0x18, 0x41, 0x20, 0x61, 0x30, 0x56, 0x20, 0x7f, 0x01, 0x00, 0x91, 0x2b, 0x64, 
                                   0x0b, 0x02, 0x3e, 0x01, 0xe4, 0x00, 0x9e, 0x00, 0xe4, 0x00, 0x22, 0x18, 0x59, 0x10, 0x3f, 0x08, 0x78, 0x08, 0x0b, 0x02, 0x00, 0x8f, 0x00, 0x64, 
                                   0x61, 0x01, 0x2a, 0x01, 0x20, 0x01, 0x3e, 0x01, 0xee, 0x00, 0x22, 0x18, 0x59, 0x10, 0x3b, 0x08, 0x3f, 0x08, 0x61, 0x01, 0x00, 0x80, 0x00, 0x64, 
                                   0xbf, 0x02, 0x6c, 0x00, 0x6c, 0x00, 0xc6, 0x00, 0x34, 0x01, 0x3a, 0x10, 0x45, 0x20, 0x56, 0x20, 0x87, 0x10, 0xbf, 0x02, 0x00, 0x71, 0x00, 0x64, 
                                   0x39, 0x01, 0xc6, 0x00, 0xbc, 0x00, 0x52, 0x01, 0x70, 0x01, 0x45, 0x20, 0x5e, 0x10, 0x69, 0x20, 0x56, 0x20, 0x39, 0x01, 0x00, 0x41, 0xcc, 0x64, 
                                   0x89, 0x01, 0x20, 0x01, 0x0c, 0x01, 0xd0, 0x00, 0x5c, 0x01, 0x4f, 0x18, 0x5e, 0x10, 0x99, 0x08, 0x26, 0x18, 0x89, 0x01, 0x00, 0x67, 0xca, 0x64, 
                                   0x7f, 0x01, 0x16, 0x01, 0x0c, 0x01, 0x2a, 0x01, 0x5c, 0x01, 0x91, 0x2b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                                   0x55, 0x18, 0x41, 0x20, 0x61, 0x30, 0x56, 0x20, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x00, 0x00};

TEST_CASE("test Side instantiation")
{
    CHECK(test_side1.bytes == exp_side1);
    CHECK(test_side2.bytes == exp_side2);
    CHECK(test_side3.bytes == exp_side3);
}

using Battlebytes = std::array<std::uint8_t, 384>;

Battle test_battle1       = rby_battle(test_side1, test_side2, 0x20);
Battlebytes exp_battle1   = {0x39, 0x01, 0xc6, 0x00, 0xbc, 0x00, 0x52, 0x01, 0x70, 0x01, 0x45, 0x20, 0x5e, 0x10, 0x69, 0x20, 0x56, 0x20, 0x39, 0x01, 0x00, 0x41, 0xcc, 0x64, 
                             0xbf, 0x02, 0x6c, 0x00, 0x6c, 0x00, 0xc6, 0x00, 0x34, 0x01, 0x3a, 0x10, 0x45, 0x20, 0x56, 0x20, 0x87, 0x10, 0xbf, 0x02, 0x00, 0x71, 0x00, 0x64, 
                             0x2f, 0x01, 0x20, 0x01, 0xca, 0x01, 0xee, 0x00, 0x0c, 0x01, 0x80, 0x10, 0x3b, 0x08, 0x99, 0x08, 0x9c, 0x10, 0x2f, 0x01, 0x00, 0x5b, 0xd9, 0x64, 
                             0x89, 0x01, 0x20, 0x01, 0x0c, 0x01, 0xd0, 0x00, 0x5c, 0x01, 0x4f, 0x18, 0x5e, 0x10, 0x99, 0x08, 0x26, 0x18, 0x89, 0x01, 0x00, 0x67, 0xca, 0x64, 
                             0x43, 0x01, 0xe4, 0x00, 0xda, 0x00, 0x3e, 0x01, 0x66, 0x01, 0x5f, 0x20, 0x55, 0x18, 0x65, 0x18, 0x99, 0x08, 0x43, 0x01, 0x00, 0x5e, 0x37, 0x64, 
                             0x4d, 0x01, 0xe4, 0x00, 0xda, 0x00, 0x66, 0x01, 0x3e, 0x01, 0x55, 0x18, 0x56, 0x20, 0x18, 0x30, 0x9c, 0x10, 0x4d, 0x01, 0x00, 0x87, 0xbb, 0x64, 
                             0x39, 0x01, 0xc6, 0x00, 0xbc, 0x00, 0x52, 0x01, 0x70, 0x01, 0x41, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                             0x45, 0x20, 0x5e, 0x10, 0x69, 0x20, 0x56, 0x20, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x00, 0x00, 0x4d, 0x01, 0xc6, 0x00, 0xa8, 0x00, 0x20, 0x01, 
                             0x20, 0x01, 0x8e, 0x10, 0x5e, 0x10, 0x3a, 0x10, 0x9c, 0x10, 0x4d, 0x01, 0x00, 0x7c, 0xcd, 0x64, 0x9d, 0x01, 0x66, 0x01, 0x52, 0x01, 0xb2, 0x00, 
                             0xbc, 0x00, 0x59, 0x10, 0x9d, 0x10, 0x22, 0x18, 0xa4, 0x10, 0x9d, 0x01, 0x00, 0x70, 0x54, 0x64, 0x89, 0x01, 0xf8, 0x00, 0x3e, 0x01, 0x9e, 0x00, 
                             0x02, 0x01, 0x85, 0x20, 0x39, 0x18, 0x73, 0x20, 0x9c, 0x10, 0x89, 0x01, 0x00, 0x50, 0xc9, 0x64, 0x0b, 0x02, 0x3e, 0x01, 0xe4, 0x00, 0x9e, 0x00, 
                             0xe4, 0x00, 0x22, 0x18, 0x59, 0x10, 0x3f, 0x08, 0x78, 0x08, 0x0b, 0x02, 0x00, 0x8f, 0x00, 0x64, 0x43, 0x01, 0xf8, 0x00, 0x0c, 0x01, 0x48, 0x01, 
                             0x2a, 0x01, 0x39, 0x18, 0x3b, 0x08, 0x56, 0x20, 0x69, 0x20, 0x43, 0x01, 0x00, 0x79, 0xc9, 0x64, 0x61, 0x01, 0x2a, 0x01, 0x20, 0x01, 0x3e, 0x01, 
                             0xee, 0x00, 0x22, 0x18, 0x59, 0x10, 0x3b, 0x08, 0x3f, 0x08, 0x61, 0x01, 0x00, 0x80, 0x00, 0x64, 0x4d, 0x01, 0xc6, 0x00, 0xa8, 0x00, 0x20, 0x01, 
                             0x20, 0x01, 0x7c, 0xcd, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8e, 0x10, 0x5e, 0x10, 0x3a, 0x10, 0x9c, 0x10, 
                             0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

Battle test_battle2       = rby_battle(test_side3, test_side1, 0x50);
Battlebytes exp_battle2   = {0x7f, 0x01, 0x16, 0x01, 0x0c, 0x01, 0x2a, 0x01, 0x5c, 0x01, 0x55, 0x18, 0x41, 0x20, 0x61, 0x30, 0x56, 0x20, 0x7f, 0x01, 0x00, 0x91, 0x2b, 0x64, 
                             0x0b, 0x02, 0x3e, 0x01, 0xe4, 0x00, 0x9e, 0x00, 0xe4, 0x00, 0x22, 0x18, 0x59, 0x10, 0x3f, 0x08, 0x78, 0x08, 0x0b, 0x02, 0x00, 0x8f, 0x00, 0x64, 
                             0x61, 0x01, 0x2a, 0x01, 0x20, 0x01, 0x3e, 0x01, 0xee, 0x00, 0x22, 0x18, 0x59, 0x10, 0x3b, 0x08, 0x3f, 0x08, 0x61, 0x01, 0x00, 0x80, 0x00, 0x64, 
                             0xbf, 0x02, 0x6c, 0x00, 0x6c, 0x00, 0xc6, 0x00, 0x34, 0x01, 0x3a, 0x10, 0x45, 0x20, 0x56, 0x20, 0x87, 0x10, 0xbf, 0x02, 0x00, 0x71, 0x00, 0x64, 
                             0x39, 0x01, 0xc6, 0x00, 0xbc, 0x00, 0x52, 0x01, 0x70, 0x01, 0x45, 0x20, 0x5e, 0x10, 0x69, 0x20, 0x56, 0x20, 0x39, 0x01, 0x00, 0x41, 0xcc, 0x64, 
                             0x89, 0x01, 0x20, 0x01, 0x0c, 0x01, 0xd0, 0x00, 0x5c, 0x01, 0x4f, 0x18, 0x5e, 0x10, 0x99, 0x08, 0x26, 0x18, 0x89, 0x01, 0x00, 0x67, 0xca, 0x64, 
                             0x7f, 0x01, 0x16, 0x01, 0x0c, 0x01, 0x2a, 0x01, 0x5c, 0x01, 0x91, 0x2b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                             0x55, 0x18, 0x41, 0x20, 0x61, 0x30, 0x56, 0x20, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x00, 0x00, 0x39, 0x01, 0xc6, 0x00, 0xbc, 0x00, 0x52, 0x01, 
                             0x70, 0x01, 0x45, 0x20, 0x5e, 0x10, 0x69, 0x20, 0x56, 0x20, 0x39, 0x01, 0x00, 0x41, 0xcc, 0x64, 0xbf, 0x02, 0x6c, 0x00, 0x6c, 0x00, 0xc6, 0x00, 
                             0x34, 0x01, 0x3a, 0x10, 0x45, 0x20, 0x56, 0x20, 0x87, 0x10, 0xbf, 0x02, 0x00, 0x71, 0x00, 0x64, 0x2f, 0x01, 0x20, 0x01, 0xca, 0x01, 0xee, 0x00, 
                             0x0c, 0x01, 0x80, 0x10, 0x3b, 0x08, 0x99, 0x08, 0x9c, 0x10, 0x2f, 0x01, 0x00, 0x5b, 0xd9, 0x64, 0x89, 0x01, 0x20, 0x01, 0x0c, 0x01, 0xd0, 0x00, 
                             0x5c, 0x01, 0x4f, 0x18, 0x5e, 0x10, 0x99, 0x08, 0x26, 0x18, 0x89, 0x01, 0x00, 0x67, 0xca, 0x64, 0x43, 0x01, 0xe4, 0x00, 0xda, 0x00, 0x3e, 0x01, 
                             0x66, 0x01, 0x5f, 0x20, 0x55, 0x18, 0x65, 0x18, 0x99, 0x08, 0x43, 0x01, 0x00, 0x5e, 0x37, 0x64, 0x4d, 0x01, 0xe4, 0x00, 0xda, 0x00, 0x66, 0x01, 
                             0x3e, 0x01, 0x55, 0x18, 0x56, 0x20, 0x18, 0x30, 0x9c, 0x10, 0x4d, 0x01, 0x00, 0x87, 0xbb, 0x64, 0x39, 0x01, 0xc6, 0x00, 0xbc, 0x00, 0x52, 0x01, 
                             0x70, 0x01, 0x41, 0xcc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x45, 0x20, 0x5e, 0x10, 0x69, 0x20, 0x56, 0x20, 
                             0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

TEST_CASE("test Battle instantiation")
{
    for(int i = 0; i < exp_battle1.size(); ++i)
    {
        CHECK(test_battle1.bytes()[i] == exp_battle1[i]);
    }
    for(int i = 0; i < exp_battle1.size(); ++i)
    {
        CHECK(test_battle2.bytes()[i] == exp_battle2[i]);
    }
}

// get each side from a battle
auto s1 = side1(test_battle1);
auto s2 = side2(test_battle1);

// get the pokemon of first side
auto p1 = pokemon1(s1);
auto p2 = pokemon2(s1);
auto p3 = pokemon3(s1);
auto p4 = pokemon4(s1);
auto p5 = pokemon5(s1);
auto p6 = pokemon6(s1);

// get active pokemon of first side
auto a1 = active(s1);
auto a2 = active(s2);

auto o1 = order(s1);
auto o2 = order(s2);

TEST_CASE("test battle access side and pokemon")
{
    for(int i = 0; i < test_side1.bytes.size(); ++i)
    {
        CHECK(s1[i] == test_side1.bytes[i]);
        CHECK(s2[i] == test_side2.bytes[i]);
    }
    for(int i = 0; i < test_alakazam.bytes.size(); ++i)
    {
        CHECK(p1[i] == test_alakazam.bytes[i]);
        CHECK(p2[i] == test_chansey.bytes[i]);
        CHECK(p3[i] == test_cloyster.bytes[i]);
        CHECK(p4[i] == test_exegg.bytes[i]);
        CHECK(p5[i] == test_gengar.bytes[i]);
        CHECK(p6[i] == test_jolteon.bytes[i]);
    }

    CHECK(o1[0] == 1);
    CHECK(o1[1] == 2);
    CHECK(o1[2] == 3);
    CHECK(o1[3] == 4);
    CHECK(o1[4] == 5);
    CHECK(o1[5] == 6);

    CHECK(o2[0] == 1);
    CHECK(o2[1] == 2);
    CHECK(o2[2] == 3);
    CHECK(o2[3] == 4);
    CHECK(o2[4] == 5);
    CHECK(o2[5] == 6);

    CHECK(p6 != test_rhydon.bytes);
    set_pokemon6(s1, test_rhydon);
    CHECK(p6 == test_rhydon.bytes);
}

TEST_CASE("test moves")
{
    std::cout << std::dec;
    // Alakazam
    CHECK((int)move_1_id(p1) == (int)SeismicToss);
    set_move1(p1, SleepPowder);
    CHECK(move_1_id(p1) == SleepPowder);
    set_move1(p1, SeismicToss);
    CHECK(move_1_id(p1) == SeismicToss);
    
    CHECK(move_1_pp(p1) == 32);
    set_pp1(p1, 17.17);
    CHECK(move_1_pp(p1) == 17);
    set_pp1(p1, 32);
    CHECK(move_1_pp(p1) == 32);

    // Chansey
    CHECK(move_2_id(p2) == SeismicToss);
    set_move2(p2, Surf);
    CHECK(move_2_id(p2) == Surf);
    set_move2(p2, SeismicToss);
    CHECK(move_2_id(p2) == SeismicToss);
    
    CHECK(move_2_pp(p2) == 32);
    set_pp2(p2, 0);
    CHECK(move_2_pp(p2) == 0);
    set_pp2(p2, 32);
    CHECK(move_2_pp(p2) == 32);
    
    // Cloyster
    CHECK(move_3_id(p3) == Explosion);
    set_move3(p3, SwordsDance);
    CHECK(move_3_id(p3) == SwordsDance);
    set_move3(p3, Explosion);
    CHECK(move_3_id(p3) == Explosion);
    
    CHECK(move_3_pp(p3) == 8);
    set_pp3(p3, -1);
    CHECK(move_3_pp(p3) == 255);
    set_pp3(p3, 8);
    CHECK(move_3_pp(p3) == 8);
    
    // Exeggutor
    CHECK(move_4_id(p4) == DoubleEdge);
    set_move4(p4, LeechSeed);
    CHECK(move_4_id(p4) == LeechSeed);
    set_move4(p4, DoubleEdge);
    CHECK(move_4_id(p4) == DoubleEdge);
    
    CHECK(move_4_pp(p4) == 24);
    set_pp4(p4, 99);
    CHECK(move_4_pp(p4) == 99);
    set_pp4(p4, 24);
    CHECK(move_4_pp(p4) == 24);
}

TEST_CASE("test status")
{
    CHECK(status(p1) == Status::HLT);
    set_status(p1, Status::BRN);
    CHECK(status(p1) == Status::BRN);

    CHECK(status(p2) == Status::HLT);
    set_status(p2, Status::FRZ);
    CHECK(status(p2) == Status::FRZ);

    CHECK(status(p3) == Status::HLT);
    set_status(p3, Status::PAR);
    CHECK(status(p3) == Status::PAR);

    CHECK(status(p4) == Status::HLT);
    set_status(p4, Status::PSN);
    CHECK(status(p4) == Status::PSN);

    CHECK(status(p5) == Status::HLT);
    set_status(p5, Status::SLP);
    CHECK(status(p5) == Status::SLP);

    CHECK(status(p6) == Status::HLT);
    set_status(p6, Status::EXT);
    CHECK(status(p6) == Status::EXT);

    set_status(p1, Status::HLT);
    set_status(p2, Status::HLT);
    set_status(p3, Status::HLT);
    set_status(p4, Status::HLT);
    set_status(p5, Status::HLT);
    set_status(p6, Status::HLT);

    CHECK(status(p1) == Status::HLT);
    CHECK(status(p2) == Status::HLT);
    CHECK(status(p3) == Status::HLT);
    CHECK(status(p4) == Status::HLT);
    CHECK(status(p5) == Status::HLT);
    CHECK(status(p6) == Status::HLT);
}

TEST_CASE("test stats")
{
    // Alakazam
    CHECK(hitpoints(p1) == 313);
    set_hp(p1, 200);
    CHECK(hitpoints(p1) == 200);
    set_hp(p1, 313);
    CHECK(hitpoints(p1) == 313);

    // Chansey
    CHECK(attack(p2) == 108);
    set_atk(p2, 0);
    CHECK(attack(p2) == 0);
    set_atk(p2, 108);
    CHECK(attack(p2) == 108);

    // Cloyster
    CHECK(defense(p3) == 458);
    set_def(p3, -1);
    CHECK(defense(p3) == 0xffff);
    set_def(p3, 458);
    CHECK(defense(p3) == 458);

    // Exeggutor
    CHECK(special(p4) == 348);
    set_spc(p4, 0xffff);
    CHECK(special(p4) == 0xffff);
    set_spc(p4, 348);
    CHECK(special(p4) == 348);

    // Gengar
    CHECK(speed(p5) == 318);
    set_spe(p5, 55.5);
    CHECK(speed(p5) == 55);
    set_spe(p5, 318);
   CHECK(speed(p5) == 318);
}

TEST_CASE("test boosts")
{
    CHECK(boost_atk(a2) == 0);
    set_atk_boost(a2, 6);
    CHECK(boost_atk(a2) == 6);
    set_atk_boost(a2, -6);
    CHECK(boost_atk(a2) == 10);
    set_atk_boost(a2, 16);
    CHECK(boost_atk(a2) == 0);

    CHECK(boost_def(a2)  == 0);
    CHECK(boost_spec(a2) == 0);
    CHECK(boost_spe(a2)  == 0);
    CHECK(boost_acc(a2)  == 0);
    CHECK(boost_eva(a2)  == 0);
}    
