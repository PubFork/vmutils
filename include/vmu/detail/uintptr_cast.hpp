/*
* Copyright 2017 Justas Masiulis
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#ifndef VMU_UINTPTR_CAST_HPP
#define VMU_UINTPTR_CAST_HPP

#include <cstdint>
#include <type_traits>
#include <cstring>

namespace vmu { namespace detail {

    template<std::size_t S>
    struct _select_uintptr_t;

    template<>
    struct _select_uintptr_t<4> {
        using type = std::uint32_t;
    };
    template<>
    struct _select_uintptr_t<8> {
        using type = std::uint64_t;
    };

    template<class T>
    struct is_pointer_or_unsigned {
        static constexpr bool value = std::is_pointer<T>::value || std::is_unsigned<T>::value;
    };

    template<class T>
    using as_uintptr_t = typename _select_uintptr_t<sizeof(T)>::type;

    template<class A1, class A2>
    inline constexpr A1 address_cast_unchecked(A2 addr) noexcept
    {
        static_assert(is_pointer_or_unsigned<A1>::value && is_pointer_or_unsigned<A2>::value,
            "address cast can only be used on valid address types");

        // clang, gcc and msvc all optimize the memcpy away
        A1 value{ 0 };
        std::memcpy(&value, &addr, sizeof(A2));

        return value;
    };

    template<class Address>
    inline constexpr auto uintptr_cast(Address address) noexcept
    {
        return address_cast_unchecked<as_uintptr_t<Address>>(address);
    }

}}

#endif // include guard
