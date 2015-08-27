#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	ifstream f1("32_bit.asm");
	ofstream f2("64_bit_translated.asm");
	string s;

	while (getline(f1, s))
	{
		s.erase(s.begin(), find_if(s.begin(), s.end(), bind1st(not_equal_to<char>(), '\t')));
		s.erase(find_if(s.rbegin(), s.rend(), bind1st(not_equal_to<char>(), ' ')).base(), s.end());

		if(s == "mov eax, 4") {
			f2 << "\tmov rax, 1" << endl;
		}
		else if(s == "mov ebx, 1") {
			f2 << "\tmov rdi, 1" << endl;
		}
		else if(s == "mov eax, 1") {
			f2 << "\tmov rax, 60" << endl;
		}
		else if(s == "mov ebx, 0") {
			f2 << "\tmov rdi, 0" << endl;
		}
		else if(s == "mov ecx, message") {
			f2 << "\tmov rsi, message" << endl;
		}
		else if(s == "mov edx, len") {
			f2 << "\tmov rdx, len" << endl;
		}
		else if(s == "int 80h") {
			f2 << "\tsyscall" << endl;
		}
		else {
			f2 << s << endl;
		}
	}
	f1.close();
	f2.close();
	return 0;
}
