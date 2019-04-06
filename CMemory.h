#include <iostream>
class CMemory
{
private:
	int idx;
	int val;
public:
	CMemory()
	{
		idx = -1;
		val = -1;
	}
	CMemory(int ii, int vv)
	{
		idx = ii;
		val = vv;
	}

	int GetValue()
	{
		return val;
	}
	int GetIdx()
	{
		return idx;
	}

	void SetValue(int vv)
	{
		val = vv;
	}
	void SetIdx(int ii)
	{
		idx = ii;
	}

	void Print()
	{
		std::cout << "M[" << idx << "] = " << val << std::endl;
	}
};
#pragma once
