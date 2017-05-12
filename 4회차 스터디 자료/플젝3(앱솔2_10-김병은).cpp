#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char inputString[1000];

int main(void)
{
	ofstream fout("textfile.txt");
	fout << "I hate C++ and hate programming!" << endl;
	fout.close();

	ifstream fin("textfile.txt");
	fin.getline(inputString, 1000);
	fin.close();

	for (int i = 0; i <= strlen(inputString) - 4; i++)
	{
		if ((inputString[i] == 'h') && (inputString[i + 1] == 'a') && 
			(inputString[i + 2] == 't') && (inputString[i + 3] == 'e'))
		{
			inputString[i] = 'l';
			inputString[i + 1] = 'o';
			inputString[i + 2] = 'v';
			inputString[i + 3] = 'e';
		}
	}

	cout << inputString << endl;

	return 0;
}