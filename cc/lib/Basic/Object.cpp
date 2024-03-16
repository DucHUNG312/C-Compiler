#include "cc/Basic/Object.h"

namespace cc
{
	const c8* Object::typeToString()
	{
		switch (type)
		{
#define OBJECT(ID, STR) case ID: return STR;
#include "cc/Basic/ObjectType.def"
		default: break;
		}
		return nullptr;
	}
}
