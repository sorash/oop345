#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>	
#include <sstream>

using namespace std;

namespace w2
{
	enum PASS_TYPE { STUDENT_PASS, ADULT_PASS, PASS_COUNT };
	class Station
	{
		string stationName;
		int passes[PASS_COUNT];

	public:
		Station();
		Station(istream& is);
	};
}