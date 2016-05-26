#include "Station.h"

using namespace w2;

Station::Station()
{

}

Station::Station(istream& is)
{
	string line;
	getline(is, line);
	cout << "Station(...) read -->" << line << "<--" << endl;

	stringstream ss(line);
	// ss >> stationName;	// does not work with words delimited by spaces
	getline(ss, stationName, ';');	// reads even with space delimiters

	ss >> passes[STUDENT_PASS];
	ss >> passes[ADULT_PASS];
	cout << "stationName, student, adult = " << stationName << ", " << passes[STUDENT_PASS] << ", " << passes[ADULT_PASS] << endl;
}