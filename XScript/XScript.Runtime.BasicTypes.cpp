#include "stdafx.h"
#include "XScript.Runtime.BasicTypes.h"
#include "XScript.DebugTools.h"
namespace XScript::Runtime::BasicTypes
{
	String GetBasicTypeName(BasicType type)
	{
		static const vector<Character*> basic_type_name =
		{
			L"Void",
			L"Boolean",
			L"UInt16",
			L"UInt32",
			L"UInt64",
			L"Int16",
			L"Int32",
			L"Int64",
			L"Single",
			L"Double",
			L"Byte",
			L"SByte",
			L"String",
			L"Class",
			L"Struct",
			L"Delegate",
			L"Enum",
			L"Null",
			L"Base",
			L"Unspecified"
		};
		DebugerAssert((basic_type_name.size() != (size_t)BasicType::BasicTypeCountPlusOne), ("数量不正确"));
		return basic_type_name[(size_t)type - 1];
	}

}
