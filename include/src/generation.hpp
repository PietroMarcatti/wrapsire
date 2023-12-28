// Copyright pasyg.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <cstdint>

namespace engine
{
    /// @brief specifies the generation in use
    enum class Gen : std::uint8_t
    {
        RBY  = 1,
        GSC  = 2,
        ADV  = 3,
        DPP  = 4,
        BW   = 5,
        ORAS = 6,
        SM   = 7,
        SS   = 8,
        SV   = 9,
    };
} // namespace engine
