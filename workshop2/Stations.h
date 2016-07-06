#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>	
#include <sstream>
#include "Station.h"

using namespace std;

namespace w2
{
	class Stations
	{
		int stationCount;
		Station* stationTable;
		char* file;
	public:
		Stations(char* fileName);

		void update();
		void restock();
		void report(); 

		~Stations();
	};
}