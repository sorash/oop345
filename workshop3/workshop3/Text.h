#ifndef W3_TEXT_H__
#define W3_TEXT_H__

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

namespace w3
{
	class Text
	{
		string* strings;

	public:
		Text();
		Text(const string fileName);

		// copy constructor and operator
		Text(const Text& other);
		Text& operator=(const Text& other);

		// move constructor and operator
		Text(Text&& other);
		Text& operator=(Text&& other);

		~Text();

		// returns number of records of text data
		size_t size() const;
	};
}

#endif