#pragma once
#include "stdafx.h"
//���û�������
namespace XScript::Runtime::BasicTypes
{
	typedef void Void;
	typedef wchar_t Character;
	typedef bool Boolean;
	typedef __int16 Int16;
	typedef __int32 Int32;
	typedef __int64 Int64;
	typedef unsigned __int16 UInt16;
	typedef unsigned __int32 UInt32;
	typedef unsigned __int64 UInt64;
	typedef char Byte;
	typedef unsigned char SByte;
	typedef float Single;
	typedef double Double;
	typedef const Character* String;//�̶��ַ���

	enum class BasicType//����ʱ�Ļ�Ԫ����
	{
		Void = 1,
		Boolean,
		UInt16,
		UInt32,
		UInt64,
		Int16,
		Int32,
		Int64,
		Single,
		Double,
		Byte,
		SByte,
		String,
		Class,
		Struct,
		Delegate,
		Enum,
		Null,
		Base,
		Unspecified,
		BasicTypeCountPlusOne
	};

	String GetBasicTypeName(BasicType type);
}