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

#ifndef VMU_WINAPI_HPP
#define VMU_WINAPI_HPP

namespace vmu { namespace detail { namespace winapi {

#ifndef JM_PROT_USE_CUSTOM_WINDOWS_INCLUDE
    #define NOMINMAX
    #define WIN32_LEAN_AND_MEAN
    #include <Windows.h>
    #undef NOMINMAX
    #undef WIN32_LEAN_AND_MEAN
#else
    JM_PROT_USE_CUSTOM_WINDOWS_INCLUDE;
#endif // !JM_PROT_USE_CUSTOM_WINDOWS_INCLUDE

}}} // namespace vmu::detail::winapi

#endif // !VMU_WINAPI_HPP