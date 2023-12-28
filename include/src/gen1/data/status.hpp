// Copyright pasyg.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstdint>

enum Status : std::uint8_t
{
    HLT = 0,
    SLP = 2,
    PSN,
    BRN,
    FRZ,
    PAR,
    EXT,
};