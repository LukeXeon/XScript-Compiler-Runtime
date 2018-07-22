#pragma once
#include "stdafx.h"
#include "XScript.Compilation.h"
#include "XScript.MemoryManager.StringManager.h"
namespace XScript::Compilation
{
	static Compiler& XScriptCall GetStaticCurrentCompilerRef()
	{
		static Compiler xsompiler = nullptr;
		return xsompiler;
	}

	static inline void XScriptCall SetCurrentCompiler(Compiler compiler)
	{
		GetStaticCurrentCompilerRef() = compiler;
	}

	Compiler XScriptCall CreateCompiler(FILE *fp)
	{
		Stotage*Memory = new Stotage();
		Compiler com = Memory->NewPointer<CompilerTag>(Memory, fp);
		SetCurrentCompiler(com);
		return com;
	}

	Compiler XScriptCall GetCurrentCompiler()
	{
		return GetStaticCurrentCompilerRef();
	}

	void XScriptCall DisposeCompiler(Compiler compilation)
	{
		delete	compilation->current_memory;
		SetCurrentCompiler(nullptr);
	}

	int XScriptCall GetCurrentLineNumber()
	{
		return GetCurrentCompiler()->current_line_number;
	}

	void CompilerTag::DoCompile()
	{
		extern int ::yyparse();
		if (yyparse())
		{
			fprintf(stderr, "Error ! Error ! Error !\n");
			exit(1);
		}
		//XvmExecutable exe;
		//xs_fix_tree(compiler);
		//XvmExecutable exe = dkc_generate(compiler);

		/*
		dvm_disassemble(exe);
		*/
		//return exe;
	}

	void CompilerTag::FixAst()
	{



	}

	CompilerTag::CompilerTag(Stotage*memory)
	{
		setlocale(LC_ALL, "chs");
		this->current_memory = memory;
		string_pool = memory->NewPointer<StringPool>();
		function_list = memory->NewPointer<list<FunctionDefinition>>();
		declaration_list = memory->NewPointer<list<Declaration>>();
		statement_list = memory->NewPointer<list<Statement>>();
		current_block = nullptr;
		this->current_line_number = 1;
	}

	CompilerTag::CompilerTag(Stotage*Memory, FILE * fp) :CompilerTag(Memory)
	{
		extern FILE *yyin;
		yyin = fp;
	}

	void CompilerTag::Compile()
	{
		DoCompile();
	}

	FunctionDefinition CompilerTag::SearchFunction(String name)
	{
		CompilerTag* Compilation = this;
		assert(function_list != nullptr);
		auto result = find_if(Compilation->function_list->begin(), Compilation->function_list->end(), [name](auto x) -> bool {
			return RawStringCompare(name, x->name);
		});
		if (result != Compilation->function_list->end())
		{
			return *result;
		}
		return nullptr;
	}

	Declaration CompilerTag::SearchDeclaration(String identifier, Block block)
	{
		assert(declaration_list != nullptr);
		for (auto b_pos = block; b_pos; b_pos = b_pos->outer_block)
		{
			for (auto d_pos = b_pos->declaration_list->begin(); d_pos != b_pos->declaration_list->end(); d_pos++)
			{
				if (RawStringCompare(identifier, (*d_pos)->name))
				{
					return *d_pos;
				}
			}
		}
		assert(declaration_list != nullptr);
		CompilerTag* Compilation = this;
		for (auto d_pos = Compilation->declaration_list->begin(); d_pos != Compilation->declaration_list->end(); d_pos++)
		{
			if (RawStringCompare(identifier, (*d_pos)->name))
			{
				return *d_pos;
			}
		}
		return nullptr;
	}

	void CompilerTag::AppendFunction(FunctionDefinition fd)
	{
		assert(function_list != nullptr);
		function_list->push_back(fd);
	}


}
