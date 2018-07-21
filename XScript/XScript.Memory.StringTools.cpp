#include "stdafx.h"
#include "XScript.Memory.StringTools.h"
#pragma warning(disable:4996)
namespace XScript::Memory::StringTools
{
	static inline size_t XScriptCall GetMultiByteToWideByteLength(const char *src)
	{
		size_t src_idx, dest_idx;
		size_t status;
		mbstate_t ps;
		memset(&ps, 0, sizeof(mbstate_t));
		for (src_idx = dest_idx = 0; src[src_idx] != '\0'; )
		{
			status = mbrtowc(NULL, &src[src_idx], MB_LEN_MAX, &ps);
			if (status == static_cast<size_t>(-1))
			{
				return status;
			}
			dest_idx++;
			src_idx += status;
		}
		return dest_idx;
	}
	
	static inline size_t XScriptCall GetWideByteToMultiByteLength(const Character *src)
	{
		size_t src_idx, dest_idx;
		size_t status;
		char dummy[MB_LEN_MAX];
		mbstate_t ps;
		memset(&ps, 0, sizeof(mbstate_t));
		for (src_idx = dest_idx = 0; src[src_idx] != L'\0'; )
		{
			status = wcrtomb(dummy, src[src_idx], &ps);
			if (status == static_cast<size_t>(-1))
			{
				return status;
			}
			src_idx++;
			dest_idx += status;
		}
		return dest_idx;
	}
	
	static inline void XScriptCall MultiByteToWideByte(const char *src, Character *dest)
	{
		size_t src_idx, dest_idx;
		size_t status;
		mbstate_t ps;
		memset(&ps, 0, sizeof(mbstate_t));
		for (src_idx = dest_idx = 0; src[src_idx] != '\0'; )
		{
			status = mbrtowc(&dest[dest_idx], &src[src_idx], MB_LEN_MAX, &ps);
			dest_idx++;
			src_idx += status;
		}
		dest[dest_idx] = L'\0';
	}

	static inline void XScriptCall WideByteToMultiByte(const Character *src, char *dest)
	{
		size_t src_idx, dest_idx;
		size_t status;
		mbstate_t ps;
		memset(&ps, 0, sizeof(mbstate_t));
		for (src_idx = dest_idx = 0; src[src_idx] != '\0'; )
		{
			status = wcrtomb(&dest[dest_idx], src[src_idx], &ps);
			src_idx++;
			dest_idx += status;
		}
		dest[dest_idx] = '\0';
	}

	StringPool::StringPool()
	{
	}

	String StringPool::CreateFromMultiByte(const char * cstr)
	{
		Character* raw = NewString(GetMultiByteToWideByteLength(cstr));
		MultiByteToWideByte(cstr, raw);
		return raw;
	}

	void StringPool::Dispose()noexcept
	{
		for (auto it = string_list.begin(); it != string_list.end(); it++)
		{
			free(*it);
		}
		string_list.clear();
	}

	String StringPool::Chain(String s1, String s2)
	{
		Character* string = NewString(wcslen(s1) + wcslen(s2) + 1);
		wcscpy(string, s1);
		wcscat(string, s2);
		return string;
	}

	StringPool::~StringPool()noexcept
	{
		Dispose();
	}

	Character*StringPool::NewString(size_t length)
	{
		Character* string = (Character*)malloc((length) * sizeof(Character));
		this->string_list.push_front(string);
		return string;
	}
}
