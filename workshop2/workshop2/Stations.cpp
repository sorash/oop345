#include "Stations.h"

using namespace w2;

Stations::Stations(char* fileName)
{
	ifstream is(fileName);
	
	// show error if file could not be opened and exit safely
	if (is.is_open())
	{
		string line;
		getline(is, line);

		// get station count
		stringstream ss(line);
		ss >> stationCount;
		cout << "stationCount = " << stationCount << endl;

		// check for ';' and exit if file is not in the order necessary
		char c;
		ss >> c;
		if (c != ';')
		{
			cerr << "File " << fileName << ": expected a ';' but found a '" << c << "'. Not our file, cannot continue." << endl;
			exit(2);
		}

		// create all stations
		stationTable = new Station[stationCount];
		for (int i = 0; i < stationCount; i++)
		{
			stationTable[i] = Station(is);
		}
	}
	else
	{
		cerr << "Can not open file '" << fileName << "'" << endl;
		exit(1);
	}
}

void Stations::update()
{

}

void Stations::restock()
{

}

void Stations::report()
{

}