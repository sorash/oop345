#include "Text.h"

using namespace w3;

Text::Text()
{
	// set the object to a safe empty state
	strings = nullptr;
	fieldCount = 0;
}

// PARAM fileName: name of text file that contains records to be stored
Text::Text(const string fileName) : fieldCount(0)
{
	ifstream is(fileName);

	// check if file exists
	if (is.is_open())
	{
		int count = 0;
		string line;

		// get count of fields
		do
		{
			getline(is, line, '\n');
			count++;
		} while (!is.fail());

		// go back to beginning of file
		is.clear();
		is.seekg(0, ios::beg);

		// allocate memory for fields
		strings = new string[count];

		// read into the array
		for (int i = 0; !is.fail(); i++)
			getline(is, strings[i], '\n');

		// set field count
		fieldCount = count;

		// close file
		is.close();
	}
	else
		Text();	// assume a safe empty state instead
}

// copy constructor
// PARAM other: object being copied from
Text::Text(const Text& other)
{
	fieldCount = 0;
	strings = '\0';
	*this = other;
}

// copy operator=
// PARAM other: object being copied from
Text& Text::operator=(const Text& other)
{
	if (this != &other) 
	{
		if (strings) 
		{
			delete[] strings;
			strings = '\0';
			fieldCount = 0;
		}

		if (other.strings) 
		{
			fieldCount = other.fieldCount;
			strings = new string[fieldCount];

			for (size_t i = 0; i < fieldCount; i++)
				strings[i] = other.strings[i];
		}
	}

	return *this;
}

// move constructor
// PARAM other: object being moved from
Text::Text(Text&& other)
{
	fieldCount = 0;
	strings = '\0';
	*this = move(other);
}

// move operator=
// PARAM other: object being moved from
Text&& Text::operator=(Text&& other)
{
	if (this != &other) 
	{
		if (strings)
		{
			delete[] strings;
			strings = '\0';
			fieldCount = 0;
		}

		fieldCount = other.fieldCount;
		strings = other.strings;

		other.fieldCount = 0;
		other.strings = '\0';
	}

	return move(*this);
}

// destructor
Text::~Text()
{
	// take care of dynamic array for strings
	delete[] strings;
	strings = nullptr;
}

// returns the number of records of text data
size_t Text::size() const
{
	return fieldCount;
}