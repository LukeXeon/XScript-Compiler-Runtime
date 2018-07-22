#pragma once
#include "stdafx.h"
namespace XScript::MemoryManager
{
	//统一分配统一释放的内存分配器

	class Stotage
	{
		union MemoryCell
		{
			long		l_dummy;
			double      d_dummy;
			void        *p_dummy;
		};
		struct MemoryBlock
		{
			size_t cell_count;
			size_t cell_index;
			MemoryBlock*next;
			MemoryCell cell_lsit[1];
		};
	public:
		Stotage();
		~Stotage();
		Stotage(const Stotage&) = delete;
		Stotage&operator=(Stotage&&) = delete;
		Stotage&operator=(const Stotage&) = delete;
		template<class _Objty, class ..._Types, typename enable_if<is_trivially_destructible<_Objty>::value, int>::type = 0>
		inline typename _Objty* NewPointer(_Types && ..._Args)
		{
			static_assert(!is_const<_Objty>::value,
				"The C++ Standard forbids containers of const elements "
				"because allocator<const T> is ill-formed.");
			static_assert(is_trivially_destructible<_Objty>::value, "析构函数不够安全.");
			void*_Ptr = Allocate(sizeof(_Objty));
			::new (const_cast<void *>(static_cast<const volatile void *>(_Ptr)))
				_Objty(_STD forward<_Types>(_Args)...);
			//cout << "stotage alloc type : " << typeid(_Objty).name() << endl;
			return  static_cast<typename _Objty*>(_Ptr);
		}
		template<class _Objty, class ..._Types, typename enable_if<(!is_trivially_destructible<_Objty>::value
			&&is_nothrow_destructible<_Objty>::value), int>::type = 0 >
		inline typename _Objty* NewPointer(_Types && ..._Args)
		{
			static_assert(!is_const<_Objty>::value,
				"The C++ Standard forbids containers of const elements "
				"because allocator<const T> is ill-formed.");
			static_assert((!is_trivially_destructible<_Objty>::value
				&&is_nothrow_destructible<_Objty>::value), "析构函数不够安全.");
			void*_Ptr = Allocate(sizeof(_Objty));
			::new (const_cast<void *>(static_cast<const volatile void *>(_Ptr)))
				_Objty(_STD forward<_Types>(_Args)...);
			auto ret = static_cast<typename _Objty*>(_Ptr);
			destructor_list.push_front([ret]()->void
			{
				ret->~_Objty();
			});
			return ret;
		}
		void Dispose();
	private:
		forward_list<function<void(void)>> destructor_list;
		MemoryBlock* block_list;
		static constexpr size_t block_cell_count = 8192;
		void*Allocate(size_t size);
	};

}

