// Critter Farm
// Demonstrates object containment
// Written by Patrick Woods 18/1/2017
// from Beginning C++ Through Game Programming Third Edition, Michael Dawson

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;


class Critter
{
public:
	static int s_Total;	// static data member variable declaration, counts total number of critters
	Critter(const string& name = "");	// Constructor prototype
	string GetName() const;

private:
	string m_Name;	// An example of aggregation
};

int Critter::s_Total = 0;	// Always initialize static variables before incrementing, stupid!

Critter::Critter(const string& name):	/* Constructor definition. By using the colon, the author uses member initializers as a shorthand way to assign data values. If there were multiple data members, they would be separated by commas. */
	m_Name(name)
{		// The constuctor body
	++ s_Total;
}

inline string Critter::GetName() const
{
	return m_Name;
}

class Farm
{
public:
	Farm(int spaces = 1);	// Constructor prototype, default size of 1
	void Add(const Critter& aCritter);	// Arg is read only of type = Critter
	void RollCall() const;

private:
	vector<Critter> m_Critters;		// m_Critters is a vector containing the farm's Critter population
};

Farm::Farm(int spaces)
{
	m_Critters.reserve(spaces);
}

void Farm::Add(const Critter& aCritter)
{
	m_Critters.push_back(aCritter);	// m_Critters is a vector, so we use the push_back() function to add new critters to the farm
}

void Farm::RollCall() const
{
	// Because m_Critters is of type = vector<Critter>, that is to say a vector of Critters, our iterator (iter) must also be a constant iterator (const_iterator) within the namespace vector<Critter>. We can use begin() and end() to find the start and end of our vector.
	for (vector<Critter>::const_iterator iter = m_Critters.begin();
			iter != m_Critters.end();
			++iter)
	{
		std::cout << iter->GetName() << " here.\n";	// This line suggests that iter is a pointer to a critter in the vector.
	}
}

int main()
{
	Critter crit("Poochie");
	std::cout << "My critter's name is " << crit.GetName() << std::endl;

	std::cout << "\nCreating critter farm.\n";
	Farm myFarm(4);

	std::cout << "\nAdding three new critters to the farm.\n";
	myFarm.Add(crit);
	myFarm.Add(Critter("Moe"));
	myFarm.Add(Critter("Larry"));
	myFarm.Add(Critter("Curly"));

	std::cout << "\nCalling Roll...\n";
	myFarm.RollCall();

	return 0;
}