#ifndef GUIDGEN_H
#define GUIDGEN_H

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

class Guid
{
	public:
		// create constructors
		Guid(const std::vector<unsigned char> &bytes);
		Guid(const unsigned char *bytes);
		Guid(const std::string &fromString);
		Guid();
		
		// copy constructor
		Guid(const Guid &other);
		
		// assign operator		
		Guid &operator=(const Guid &other);
		
		// compare operators
		bool operator==(const Guid &other) const;
		bool operator!=(const Guid &other) const;

	private:
		std::vector<unsigned char> _bytes;
		friend std::ostream &operator<<(std::ostream &s, const Guid &guid);
};

Guid createGuid();

#endif