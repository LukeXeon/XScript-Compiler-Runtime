#pragma once
#include "stdafx.h"
#include "XScript.Runtime.BasicTypes.h"
#define RawStringCompare(s1,s2) (wcscmp(s1,s2)==0)

using namespace XScript::Runtime::BasicTypes;
namespace XScript::Memory::StringTools
{
	class StringPool
	{
		forward_list<Character*> string_list;
	public:
		StringPool();
		StringPool(const StringPool&) = delete;
		StringPool&operator=(StringPool&&) = delete;
		StringPool&operator=(const StringPool&) = delete;
		String CreateFromMultiByte(const char*cstr);
		void Dispose()noexcept;
		String Chain(String s1, String s2);
		~StringPool()noexcept;
	private:
		Character*NewString(size_t length);
	};
}