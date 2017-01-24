//FileRead
//Written by Patrick Woods 22/1/2017 to practise reading from .txt

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream myfile ("HelloWindows.txt");
	if (myfile.is_open())
	{
		myfile.seekg(0, ios::end);
		myfile << "This is another line.\n";
		myfile << "Yet another line.\n";
		myfile.close();
	}
	else cout << "Unable to open file" << endl;
	return 0;
}
