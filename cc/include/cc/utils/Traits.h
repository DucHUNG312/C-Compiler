#pragma once

#include <type_traits>
#include <variant>

namespace cc
{
	namespace utils
	{
		template<typename T, typename... Ts>
		struct is_one_of;

		template<typename T, typename... Ts>
		struct is_one_of<T, std::variant<Ts...>> : std::disjunction<std::is_same<T, Ts>...> {};

		template<typename T, typename... Types>
		struct index_of;

		template<typename T, typename... Types>
		struct index_of<T, std::variant<Types...>>
		{
			static constexpr size_t value = []() constexpr
				{
					size_t index = 0;
					bool found = false;
					(void(std::is_same_v<T, Types> ? (found = true) : ++index), ...);
					return found ? index : std::variant_npos;
				}();
		};
	}
}
