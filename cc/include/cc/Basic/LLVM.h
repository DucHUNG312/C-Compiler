#pragma once

#include "llvm/Support/Casting.h"
#include "llvm/ADT/SmallVector.h"

namespace llvm
{
	// Containers.
	class StringRef;
	class StringLiteral;
	template <unsigned N> class SmallString;
}

namespace cc
{
	using llvm::ArrayRef;
	using llvm::SmallString;
	using llvm::SmallVector;
}
