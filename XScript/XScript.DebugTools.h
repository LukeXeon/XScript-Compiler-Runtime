#pragma once
#include "stdafx.h"

#ifndef _DEBUG
#define debuger_assert(expression,msg)  ((void)0)
#else /* DBG_NO_DEBUG */
namespace XScript::DebugTool
{
	inline void _DebugerAssert(char*flie, int line, char* expression, char *msg)
	{
		cout << flie << "(" << line << "): expression: " << expression << "  message: " << msg << endl;
		abort();
	}
}
#define DebugerAssert(expression,msg)\
((expression) ? (void)(0):(XScript::DebugTool::_DebugerAssert(__FILE__,__LINE__,#expression,msg)))
#endif