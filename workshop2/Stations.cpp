#include "Stations.h"

using namespace w2;

Stations::Stations(char* fileName)
{
	file = new char[strlen(fileName)];
	strcpy(file, fileName);

	ifstream is(file);

	// make sure file is opened
	if (is.is_open())
	{
		// get station count
		is >> stationCount;
		
		// read character
		char c;
		is >> c;

		// check if character is right
		if (c != ';')
		{
			cerr << "File '" << file << "' expected a ';' but found a '" << c << "'. Can not continue." << endl;
			exit(2);
		}

		// create all stations
		stationTable = new Station[stationCount];
		for (int i = 0; i < stationCount; i++) 
			stationTable[i] = Station(is);

		// close file
		is.close();
	}
	else
	{
		cerr << "File '" << file << "' could not be opened." << endl;
		exit(1);
	}
}

void Stations::update()
{
	cout << endl;
	cout << "Passes Sold  :" << endl;
	cout << "--------------";

	for (int i = 0; i < stationCount; i++) 
		stationTable[i].update();

	cout << endl;
}

void Stations::restock()
{
	cout << "Passes Added :" << endl;
	cout << "--------------";

	for (int i = 0; i < stationCount; i++)
		stationTable[i].restock();

	cout << endl;
}

void Stations::report()
{
	cout << "Passes in Stock : Student Adult" << endl;
	cout << "-------------------------------" << endl;
	for (int i = 0; i < stationCount; i++)
		stationTable[i].report();
}

Stations::~Stations() 
{
	ofstream os(file);
	os.open(file, ios::trunc);

	// make sure file is opened
	if (os.is_open()) 
	{
		// write station count
		os << stationCount << ';' << endl;

		// write all stations
		for (int i = 0; i < stationCount; i++) 
			stationTable[i].write(os);

		// close file
		os.close();
	}
	else 
	{
		cerr << "File '" << file << "' could not be created." << endl;
		exit(3);
	}

	// clear dynamic array
	delete[] stationTable;
}