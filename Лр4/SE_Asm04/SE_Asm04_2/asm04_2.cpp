#include <iostream>
#include <fstream>
using namespace std;

void main()
{
	bool BooleanVar = true;

	ofstream out;
	out.open("D:\\������\\3-� �������\\���� ���\\Assembler\\��4\\SE_Asm04\\serialize.txt");

	if (out.is_open())
	{
		out << "0x01" << " " << "0x" << "" << hex << (int)BooleanVar << " ";
		out << "0x02" << " " << "0x" << hex << 257 << endl;
	}
}