#include<iostream>
#include<string>
#include<vector>
#include"MYSTRING.h"
void SplitFilename(const myString& str)
{
	std::cout << "Splitting: " << str << '\n';
	std::size_t found = str.find_last_of("/\\");
	std::cout << " path: " << str.substr(0, found) << '\n';
	std::cout << " file: " << str.substr(found + 1) << '\n';
}

void main(){
	myString str;
	myString base = "The quick brown fox jumps over a lazy dog.";

	// used in the same order as described above:

	str.assign(base);
	std::cout << str << '\n';
	cout << str.length() << endl;
	cout << str._capacity() << endl;

	str.assign(base, 10, 9);
	std::cout << str << '\n';         // "brown fox"
	cout << str.length() << endl;
	cout << str._capacity() << endl;
	str.assign("pangrams are cool", 7);
	std::cout << str << '\n';         // "pangram"
	cout << str.length() << endl;
	cout << str._capacity() << endl;
	str.assign("c-string");
	std::cout << str << '\n';         // "c-string"
	cout << str.length() << endl;
	cout << str._capacity() << endl;
	str.assign(10, '*');
	std::cout << str << '\n';         // "**********"
	cout << str.length() << endl;
	cout << str._capacity() << endl;
	str.assign<int>(10, 0x2D);
	std::cout << str << '\n';         // "----------"
	cout << str.length() << endl;
	cout << str._capacity() << endl;
	str.assign(base.begin() + 16, base.end() - 12);
	std::cout << str << '\n';
	cout << str.length() << endl;
	cout << str._capacity() << endl;


	char buffer[20];
	myString l("Test string...");
	size_t length = l.copy(buffer, 6, 5);
	buffer[length] = '\0';
	std::cout << "buffer contains: " << buffer << '\n';
}