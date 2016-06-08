#include "Station.h"

using namespace w2;

Station::Station()
{

}

Station::Station(istream& is)
{
	string line;

	getline(is, line, ';');		// get name of the station
	stationName = line;

	is >> passes[STUDENT_PASS];//number of student passes
	is.ignore();

	is >> passes[ADULT_PASS];//number of adult passes
	is.ignore();
}

void Station::update() 
{
	int count;

	cout << stationName << "\n";
	cout << " Student Passes sold : ";
	cin >> count;
	passes[STUDENT_PASS] -= count;

	cout << " Adult   Passes sold : ";
	cin >> count;
	passes[ADULT_PASS] -= count;
}

void Station::restock() 
{
	int count;

	cout << stationName << "\n";
	cout << " Student Passes added : ";
	cin >> count;
	passes[STUDENT_PASS] += count;

	cout << " Adult   Passes added : ";
	cin >> count;
	passes[ADULT_PASS] += count;
}

void Station::report() 
{
	cout << setw(19) << left << stationName;
	cout << setw(6) << right << passes[STUDENT_PASS];
	cout << setw(6) << right << passes[ADULT_PASS];
	cout << endl;
}

void Station::write(ostream& os) 
{
	os << stationName << ';'
		 << passes[STUDENT_PASS] << ' '
		 << passes[ADULT_PASS] << endl;
}