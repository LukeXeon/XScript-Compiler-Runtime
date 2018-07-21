#pragma once
#include "stdafx.h"
#include "debug.h"
#include "xscript0.h"
#include "compiler.h"
#include "string.h"
#include "utils.h"
#include "type.h"
#include "error.h"
#include "create0.h"
using namespace std;
using namespace XScript;
using namespace XScript::Compilation;
using namespace XScript::Ast;
using namespace XScript::StringTools;
using namespace XScript::YaccInterface;
using namespace XScript::Errors;
using namespace XScript::utils;
extern int yylex();


#define register 
