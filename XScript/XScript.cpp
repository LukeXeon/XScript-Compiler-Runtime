#include "stdafx.h"
#include "XScript.Compilation.h"
#include <exception>
#include "XScript.DebugTools.h"
#pragma warning(disable:4996)
using namespace XScript::Compilation;
int main(int argc, char** argv)
{

	FILE *fp = NULL;
/*
	if (argc < 2) 
	{
		fprintf(stderr, "usage:%s filename arg1, arg2, ...", argv[0]);
		system("pause");
		exit(1);
	}
*/


	auto begin_time = clock();
	fp = fopen("test.x", "r");
	if (fp == NULL) {
		fprintf(stderr, "%s not found.\n", argv[1]);
		system("pause");
		exit(1);
	}
	Compiler com = CreateCompiler(fp);
	com->Compile();
	DisposeCompiler(com);
	cout << "compiler time : " << (clock() - begin_time) << endl;
	system("pause");
	return 0;
}
