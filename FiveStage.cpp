// inlcude the standard library
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>

// include the self library
#include "CMemory.h"
#include "CRegister.h"
#include "CInstruction.h"
using namespace std;

// initialize the REGISTER, MEMORY, CACHE
vector<CRegister> Register(32);
vector<CMemory> Memory(10000);
vector<CMemory> Cache(256);

vector<CInstruction> Instructions(1000);
// Record
vector<string> InitRecord;
vector<string> MainCodeRecord; 
vector<string> PrintRecord;

//
regex rx("[a-zA-Z|\\=|\\-|[\\]]+");
string fmt(" ");
// Lexical analysis the record
bool Initialization(vector<string> InitRecord)
{
	for (int i = 0; i < InitRecord.size(); i++)
	{
		string str = InitRecord[i];
		int pos = str.find("-");
		if (str[0] == 'R')// initialize Register
		{			
			if (pos>0)
			{
				stringstream in(regex_replace(str, rx, fmt));
				int idx1, idx2, val;
				in >> idx1 >> idx2 >> val;
				for (int i = idx1; i <= idx2; i++)
				{
					Register[i].SetIdx(i);
					Register[i].SetIdx(val);
				}
			}
			else
			{
				stringstream in(regex_replace(str, rx, fmt));
				int idx, val;
				in >> idx >> val;
				Register[idx].SetIdx(idx);
				Register[idx].SetIdx(val);
			}
		}
		else// initialize Memory
		{
			if (pos > 0)
			{
				stringstream in(regex_replace(str, rx, fmt));
				int idx1, idx2, val;
				in >>idx1 >> idx2 >> val;
				for (int i = idx1; i <= idx2; i++)
				{
					Memory[i].SetIdx(i);
					Memory[i].SetIdx(val);
				}
			}
			else
			{
				stringstream in(regex_replace(str, rx, fmt));
				int idx, val;
				in >> idx >> val;
				Memory[idx].SetIdx(idx);
				Memory[idx].SetIdx(val);
			}
		}	
	}
	return 1;
}

// Print the Register and Memory
bool Print(vector<string> PrintRecord)
{
	for (int i = 0; i < PrintRecord.size(); i++)
	{
		string str = PrintRecord[i];
		if (str[0] == 'R')// Print Register
		{
			if (str.find("-"))
			{
				stringstream in(str);
				string s1, s2, s3;
				int idx1, idx2;
				in >> s1 >> idx1 >> s2 >> s3 >> idx2;
				for (int i = idx1; i <= idx2; i++)
				{
					Register[i].Print();
				}
			}
			else
			{
				stringstream in(str);
				string s1;
				int idx;
				in >> s1 >> idx;
				Register[idx].Print();
			}
		}
		else// Print Memory
		{
			if (str.find("-"))
			{
				stringstream in(str);
				string s1, s2, s3, s4;
				int idx1, idx2;
				in >> s1 >> s2 >> idx1 >> s2 >> s3 >> idx2 >> s4;
				for (int i = idx1; i <= idx2; i++)
				{
					Memory[i].Print();
				}
			}
			else
			{
				stringstream in(str);
				string s1, s2, s3;
				int idx;
				in >> s1 >> s2 >> idx >> s3;
				Memory[idx].Print();
			}
		}

	}
	return 1;
}

// Procsses the Five Stage Piple 
int string2int(string str)
{
	stringstream in(regex_replace(str, rx, fmt));
	int num;
	in >> num;
	return num;
}

void StoreInst(string s1, string s2, string s3, string s4, int No, int addr, int type)
{
	if (s1 == "ADD")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		int idx3 = string2int(s3);
		CInstruction inst1(0, No, addr, type, Register[idx1], Register[idx2], Register[idx3]);
		Instructions[No] = inst1;
	}
	else if (s1 == "ADDI")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		int val = string2int(s3);
		CInstruction inst1(1, No, addr, type, Register[idx1], Register[idx2], val);
		Instructions[No] = inst1;
	}
	else if (s1 == "SUB")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		int idx3 = string2int(s3);
		CInstruction inst1(2, No, addr, type, Register[idx1], Register[idx2], Register[idx3]);
		Instructions[No] = inst1;
	}
	else if (s1 == "SUBI")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		int val = string2int(s3);
		CInstruction inst1(3, No, addr, type, Register[idx1], Register[idx2], val);
		Instructions[No] = inst1;
	}
	else if (s1 == "MUL")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		int idx3 = string2int(s3);
		CInstruction inst1(4, No, addr, type, Register[idx1], Register[idx2], Register[idx3]);
		Instructions[No] = inst1;
	}
	else if (s1 == "MULI")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		int val = string2int(s3);
		CInstruction inst1(5, No, addr, type, Register[idx1], Register[idx2], val);
		Instructions[No] = inst1;
	}
	else if (s1 == "DIV")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		int idx3 = string2int(s3);
		CInstruction inst1(6, No, addr, type, Register[idx1], Register[idx2], Register[idx3]);
		Instructions[No] = inst1;
	}
	else if (s1 == "DIVI")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		int val = string2int(s3);
		CInstruction inst1(7, No, addr, type, Register[idx1], Register[idx2], val);
		Instructions[No] = inst1;
	}
	else if (s1 == "AND")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		int idx3 = string2int(s3);
		CInstruction inst1(8, No, addr, type, Register[idx1], Register[idx2], Register[idx3]);
		Instructions[No] = inst1;
	}
	else if (s1 == "ANDI")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		int val = string2int(s3);
		CInstruction inst1(9, No, addr, type, Register[idx1], Register[idx2], val);
		Instructions[No] = inst1;
	}
	else if (s1 == "OR")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		int idx3 = string2int(s3);
		CInstruction inst1(10, No, addr, type, Register[idx1], Register[idx2], Register[idx3]);
		Instructions[No] = inst1;
	}
	else if (s1 == "ORI")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		int val = string2int(s3);
		CInstruction inst1(11, No, addr, type, Register[idx1], Register[idx2], val);
		Instructions[No] = inst1;
	}
	else if (s1 == "NOT")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		CInstruction inst1(12, No, addr, type, Register[idx1], Register[idx2]);
		Instructions[No] = inst1;
	}
	else if (s1 == "NOTI")
	{
		int idx1 = string2int(s1);
		int val = string2int(s2);
		CInstruction inst1(13, No, addr, type, Register[idx1], val);
		Instructions[No] = inst1;
	}
	else if (s1 == "LD")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		CInstruction inst1(14, No, addr, type, Register[idx1], Register[idx2]);
		Instructions[No] = inst1;
	}
	else if (s1 == "LDI")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		int val = string2int(s3);
		CInstruction inst1(15, No, addr, type, Register[idx1], Register[idx2], val);
		Instructions[No] = inst1;
	}
	else if (s1 == "ST")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		CInstruction inst1(16, No, addr, type, Register[idx1], Register[idx2]);
		Instructions[No] = inst1;
	}
	else if (s1 == "STI")
	{
		int idx1 = string2int(s1);
		int idx2 = string2int(s2);
		int val = string2int(s3);
		CInstruction inst1(17, No, addr, type, Register[idx1], Register[idx2], val);
		Instructions[No] = inst1;
	}
	else if (s1 == "BRZ")
	{
		int idx1 = string2int(s1);
		CInstruction inst1(18, No, addr, type, Register[idx1]);
		Instructions[No] = inst1;
	}
	else if (s1 == "BRNZ")
	{
		int idx1 = string2int(s1);
		CInstruction inst1(19, No, addr, type, Register[idx1]);
		Instructions[No] = inst1;
	}
	else if (s1 == "BRG")
	{
		int idx1 = string2int(s1);
		CInstruction inst1(20, No, addr, type, Register[idx1]);
		Instructions[No] = inst1;
	}
	else if (s1 == "BRL")
	{
		int idx1 = string2int(s1);
		CInstruction inst1(21, No, addr, type, Register[idx1]);
		Instructions[No] = inst1;
	}
	else if (s1 == "JMY")
	{
		CInstruction inst1(22, No, addr, type);
		Instructions[No] = inst1;
	}
}

bool PreMainCode(vector<string> MainCodeRecord)
{
	// 
	int NOidx = 0;
	int TargetAddr = 0;
	int type;
	for (int i = 0; i < MainCodeRecord.size(); i++)
	{
		string str = MainCodeRecord[i];
		int pos1 = str.find("Loop");
		int pos2 = str.find("Branch");

		if (pos1 < 0 && pos2 < 0)
		{
			string s1, s2, s3, s4;
			stringstream in(str);
			in >> s1 >> s2 >> s3 >> s4;	
			StoreInst(s1, s2, s3, s4, NOidx, TargetAddr, type);
		}
		else if (pos1 == 0)
		{

		}




	}
	return 1;
}

int main()
{
	// read the file to load the instruction
	string m_nFileName = "test1.txt";
	ifstream m_nFp(m_nFileName);
	if (!m_nFp.is_open())
	{
		cout << m_nFileName << " can not open." << endl;
	}

	// read the record file per line
	string temp;
	while (getline(m_nFp, temp))
	{
		// read the Initialization
		if (temp[0] == 'R' || temp[0] == 'M')
		{
			InitRecord.push_back(temp);
		}
		else if (temp[0] == 'P')
		{
			PrintRecord.push_back(temp.substr(6));
		}
		else if (temp[0] == '/' && temp[1] == '/')
		{
			continue;
		}
		else
		{
			MainCodeRecord.push_back(temp);
		}
	}

	// Process the Initialization record
	if (!Initialization(InitRecord))
	{
		cout << "The initialization is failure" << endl;
	}

	// Main code
	if (!PreMainCode(MainCodeRecord))
	{
		cout << "The Main code running is failure" << endl;
	}

	// Print the Register and the Memory
	if (!Print(PrintRecord))
	{
		cout << "The Print is failure" << endl;
	}

	// Print the statistical values

	// close the file
	m_nFp.close();
	return 1;
}