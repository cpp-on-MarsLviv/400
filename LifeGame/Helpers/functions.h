#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <type_traits>

namespace Helpers {

template <typename E>
constexpr auto to_underlying(E e) noexcept { return static_cast<std::underlying_type_t<E>>(e); }

}
#endif // FUNCTIONS_H
