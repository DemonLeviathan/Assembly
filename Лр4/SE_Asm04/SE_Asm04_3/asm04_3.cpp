#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main()
{
	string readtext;
	ifstream in("D:\\”нивер\\3-й семестр\\Ћабы  ѕќ\\Assembler\\Ћр4\\SE_Asm04\\serialize.txt");
	ofstream out;
	out.open("D:\\”нивер\\3-й семестр\\Ћабы  ѕќ\\Assembler\\Ћр4\\SE_Asm04\\SE_Asm04\\asm_04.asm");

	out << ".586P" << endl << ".MODEL FLAT, STDCALL" << endl << "includelib kernel32.lib" << endl << "ExitProcess PROTO : DWORD" << endl 
		<< ".STACK 4096" << endl << ".DATA" << endl;

	if (in.is_open())
	{
		while (in >> readtext)
		{

			if (readtext == "0x02")
			{
				out << "var2 EQU ";
				in >> readtext;
				string str = readtext.substr(2);
				int test = stoi(str, 0, 16);
				out << test << endl;
				
			}
			else if (readtext == "0x01")
			{
				out << "var1 DB ";
				in >> readtext;

				string str = readtext.substr(2);
				int test = stoi(str, 0, 16);
				if (test == 1)
				{
					out << "1" << endl;
				}
				else
				{
					out << "0" << endl;
				}
			}

		}
	}
	in.close();
	out << ".CODE" << endl << "main PROC" << endl << "START:" << endl << "invoke ExitProcess, 0" << endl << "main ENDP" << endl << "end main";
}