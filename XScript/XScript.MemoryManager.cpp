#include "stdafx.h"
#include "XScript.MemoryManager.h"
using namespace XScript::MemoryManager;
namespace XScript::MemoryManager
{
	Stotage::Stotage()
	{
	}

	Stotage::~Stotage()
	{
		Dispose();
	}

	void Stotage::Dispose()
	{
		for (auto it = destructor_list.begin(); it != destructor_list.end(); it++)
		{
			(*it)();
		}
		destructor_list.clear();
		while (block_list)
		{
			MemoryBlock*block = block_list;
#ifdef _DEBUG
			cout << "block dispose : use :" << block->cell_index << " alloc :" << block->cell_count << endl;
#endif // _DEBUG
			block_list = block_list->next;
			free(block);
		}
#ifdef _DEBUG
		cout << "stotage dispose" << endl;
#endif // _DEBUG
	}

	void * Stotage::Allocate(size_t size)
	{
		size_t	cell_alloc_mun = ((size - 1) / sizeof(MemoryCell)) + 1;
		if (block_list != nullptr && (block_list->cell_index + cell_alloc_mun < block_list->cell_count))
		{
			void* p = &(block_list->cell_lsit[block_list->cell_index]);
			block_list->cell_index += cell_alloc_mun;
			return p;
		}
		else
		{
			size_t	new_block_cell_count = larger(cell_alloc_mun, block_cell_count);
			MemoryBlock*new_block = (MemoryBlock*)malloc(sizeof(MemoryBlock) + sizeof(MemoryCell)*new_block_cell_count);
			new_block->next = block_list;
			new_block->cell_count = new_block_cell_count;
			block_list = new_block;
			void*p = &(block_list->cell_lsit[0]);
			block_list->cell_index = cell_alloc_mun;
			return p;
		}
	}
}