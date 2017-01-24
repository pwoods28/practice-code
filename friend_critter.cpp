// Friend Critter
// Demonstrates friend functions and operator level overloading//
// Written by Patrick Woods 18/1/2017 using work from Beginning C++ Through Game Programming, Third Edition, Michael Dawson.

#include <iostream>
#include <string>

using namespace std;

class Critter
{
	friend void Peek(const Critter& aCritter);	// Peek gets aCritter by const reference, so a copy of the object is not made (benefit of passing by reference!) but the object is also protected against unwanted changes (by being const). Win win win win!
	friend ostream& operator<<(ostream& os, const Critter& aCritter);

public:
	Critter(const string& name = "");

private:
	string m_Name;
};

Critter::Critter(const string& name):
	m_Name(name)
{}

void Peek(const Critter& aCritter);
ostream& operator<<(ostream& os, const Critter& aCritter);

int main()
{
	Critter crit("Poochie");

	cout << "Calling Peek() to access crit's private data member, m_Name: \n";
	Peek(crit);

	cout << "\nSending crit object to cout with the << operator:\n";
	cout << crit << endl;

	return 0;
}

//global friend function which can access all of a Critter object's members
void Peek(const Critter& aCritter)
{
	cout << aCritter.m_Name << endl;
}

//global friend function which can access all of Critter object's members. Overloads the << operator so you can send a Critter object to cout
ostream& operator<<(ostream& os, const Critter& aCritter)
{
	os << "Critter Object - ";
	os << "m_Name: " << aCritter.m_Name;
	return os;
}
