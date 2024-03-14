#pragma once

#include "cc/core/CC.h"
#include "cc/utils/Traits.h"

namespace cc
{
	using ObjectValue = std::variant <std::monostate, u8, u16, u32, u64, i8, i16, i32, i64, f32, f64, f128, c8, const c8*, std::string>;

	template<typename T>
	constexpr size_t index_of_v = utils::index_of<T, ObjectValue>::value;

	class Object
	{
		enum ObjectType : u8
		{
			EMPTY,
			U8,
			U16,
			U32,
			U64,
			I8,
			I16,
			I32,
			I64,
			F32,
			F64,
			F128,
			C8,
			LITERAL,
			STRING,

		};
	public:
		Object() = default;
		template<typename T>
		Object(T val)
		{
			static_assert(utils::is_one_of<T, ObjectValue>::value, "Data type is not supported");
			value = val;
			type = ObjectType(index_of_v<T>);
		}

		template<typename T>
		T getValue()
		{
			static_assert(utils::is_one_of<T, ObjectValue>::value, "Data type is not supported");
			CC_CHECK_EQ(index_of_v<T>, ObjectType(type));
			return std::get<T>(value);
		}

		ObjectType getType()
		{
			return type;
		}

		bool isEmpty()
		{
			return value.index() == 0;
		}
	private:
		ObjectValue value;
		ObjectType type;
	};
}
