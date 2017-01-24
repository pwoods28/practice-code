//filesize
//Written by Patrick Woods 23/1/2017 to practise working with file pointers
//Aims to determine the size of an input file in bytes.

#include <iostream>
#include <fstream>
using namespace std;

int main(){
	streampos begin,end;
	fstream myfile ("HelloWindows.txt");
	begin = myfile.tellg();
	myfile.seekg(0, ios::end);
	end = myfile.tellg();
	myfile.close();
	cout << "size is: " << (end-begin) << " bytes.\n";
	return 0;
}
