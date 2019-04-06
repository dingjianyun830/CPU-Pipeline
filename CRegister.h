#include <iostream>
class CRegister
{
private:
	int idx;
	int val;
	int StageNO;
public:

	CRegister()
	{
		idx = 0;
		val = 0;
		StageNO = 0;
	}
	CRegister(int ii, int vv)
	{
		idx = ii;
		val = vv;
		StageNO = 0;
	}

	int GetValue()
	{
		return val;
	}
	int GetIdx()
	{
		return idx;
	}
	int GetStage()
	{
		return StageNO;
	}

	void SetValue(int vv)
	{
		val = vv;
	}
	void SetIdx(int ii)
	{
		idx = ii;
	}

	void SetStage(int n)
	{
		StageNO = n;
	}

	void Print()
	{
		std::cout << "R" << idx << " = " << val << std::endl;
	}
};
#pragma once
