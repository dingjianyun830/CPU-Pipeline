#include<vector>
#include<string>

#include"CRegister.h"
class CInstruction;

enum InstructionCode
{
	ADD, ADDI, SUB, SUBI, MUL, MULI, DIV, DIVI,
	AND, ANDI, OR, ORI, NOT, NOTI, 
	LD, LDI, ST, STI, BRZ, BRNZ, BRG, BRL, JMP
};

int ProcessInstruction(int InstCode, int RegVal1, int RegVal2)
{
	switch (InstCode)
	{
	case ADD:
		return RegVal1 + RegVal2;
	case ADDI:
		return RegVal1 + RegVal2;
	case SUB:
		return RegVal1 - RegVal2;
	case SUBI:
		return RegVal1 - RegVal2;
	case MUL:
		return RegVal1 * RegVal2;
	case MULI:
		return RegVal1 * RegVal2;
	case DIV:
		return RegVal1 / RegVal2;
	case DIVI:
		return RegVal1 / RegVal2;
	case AND:
		return RegVal1 & RegVal2;
	case ANDI:
		return RegVal1 & RegVal2;
	case OR:
		return RegVal1 | RegVal2;
	case ORI:
		return RegVal1 | RegVal2;
	case NOT:
		return !RegVal1;
	case NOTI:
		return !RegVal1;
	}
		
}

class CInstruction
{
private :
	int InstCode;
	int TargetAddress;
	int TargetType;
	CRegister Reg1;
	CRegister Reg2;
	CRegister Reg3;
	int ConstVal;
	int StageNO;// reflect the stage of  instrction [1,2,3,4,5] . 0--not in the pipeline
	int Cycles;
	bool m_bRun;// the instrction is run or not
	int NOidx;// the NO. in the instruction set
public:
	CInstruction()
	{
		InstCode			= -1;
		TargetAddress		= -1;
		TargetType			= -1;
		ConstVal			= -1;
		StageNO				= 0;
		Cycles				= 0;
		m_bRun				= false;
		NOidx				= -1;
	}
	//constructor 1
	CInstruction(int c, int No, int addr, int t, CRegister r1, CRegister r2, CRegister r3)
	{
		InstCode = c;
		Reg1 = r1;
		Reg2 = r2;
		Reg3 = r3;
		NOidx = No;
		TargetAddress = addr;
		TargetType = t;
	}
	//constructor 2
	CInstruction(int c, int No, int addr, int t, CRegister r1, CRegister r2, int val)
	{
		InstCode = c;
		Reg1 = r1;
		Reg2 = r2;
		ConstVal = val;
		NOidx = No;
		TargetAddress = addr;
		TargetType = t;
	}
	//constructor 3
	CInstruction(int c, int No, int addr, int t, CRegister r1)
	{
		InstCode = c;
		Reg1 = r1;
		NOidx = No;
		TargetAddress = addr;
		TargetType = t;
	}
	//constructor 4
	CInstruction(int c, int No, int addr, int t, CRegister r1, CRegister r2)
	{
		InstCode = c;
		Reg1 = r1;
		Reg2 = r2;
		NOidx = No;
		TargetAddress = addr;
		TargetType = t;
	}
	//constructor 5
	CInstruction(int c, int No, int addr, int t, CRegister r1, int val)
	{
		InstCode = c;
		Reg1 = r1;
		ConstVal = val;
		NOidx = No;
		TargetAddress = addr;
		TargetType = t;
	}
	//constructor 6
	CInstruction(int c, int No, int addr, int t)
	{
		InstCode = c;
		NOidx = No;
		TargetAddress = addr;
		TargetType = t;
	}
	//Set the value
	void setStageNO(int n)
	{
		StageNO = n;
	}

	void setCycles(int c)
	{
		Cycles = c;
	}

	void setRun(bool t)
	{
		m_bRun = t;
	}

};
#pragma once
