//Filewrite
//Written by Patrick Woods 22/1/2017 to practise using c++ to write to .txt

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream myfile;
	myfile.open("HelloWindows.txt");
	myfile << "Hello Windows!";
	myfile.close();
	return 0;
}
