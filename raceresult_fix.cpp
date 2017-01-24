//-----------------------------------------------------------------------------
//race|result_fix
//Written by Patrick Woods 23/1/2017
//Intends to read r|r data from csv file and merge data members for all instances of transponder1 duplication, then outputting as csv for import back into r|r event.
//-----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>

using namespace std;	//ok for now but I should probably be going with 							"using std::cout" etc.

class Participant{
public:
	Participant(const int bib = 0, const int transponder = 0, const string& surname = "", int start1 = 0, int finish1 = 0, int start2 = 0, int finish2 = 0);								  //Constructor prototype
	~Participant();									  //Destructor prototype
	Participant(const Participant& c);	   			 //Copy prototype
	Participant& operator=(const Participant& c);	//Operator '=' overload prototype

private:
	int m_bibNo;
	int m_transponder;
	string* m_surname;
	long m_start1;
	long m_finish1;
	long m_start2;
	long m_finish2;
};

//Participant Constructor definition
Participant::Participant(const int bib, const int transponder, const string& surname, int start1, int finish1, int start2, int finish2){
	cout << "Constructor Called";
	m_bibNo = bib;
	m_transponder = transponder;
	m_surname = new(surname);
	m_start1 = start1;
	m_start2 = start2;
	m_finish1 = finish1;
	m_finish2 = finish2;
}

//-----------------------------------------------------------------------------

int main(){
	ifstream original_file ("rrfix_input.txt");
	ofstream output_file ("rrfix_output.txt");
	string value;

//Data format BIB,TRAN,FIRST,LAST,START1,FIN1,STA2,FIN2\n
	if(original_file.is_open()){
		//while( original_file.good() ){
		getline(original_file,value,',');	//read string until next ','
		


		//output_file << string( value,1,value.length()-2);	//display value removing the first and last character from it. So from not the 0th, but the 1st element, and counting size-2 from that point.
		//}
	}
	else{
		cout << "File could not be opened." << endl;
		cout << "Please ensure file is named ""rrfix_input.txt""" << endl;
	}

	original_file.close();
	output_file.close();

}

//-----------------------------------------------------------------------------
