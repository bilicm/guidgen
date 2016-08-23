#include "guidgen.h"

#ifdef LIBUUID
#include <uuid/uuid.h>
#endif

#ifdef GUID
#include <objbase.h>
#endif

using namespace std;

ostream &operator<<(ostream &s, const Guid &guid) {
	return s << hex << setfill('0')
		<< setw(2) << (int)guid._bytes[0]
		<< setw(2) << (int)guid._bytes[1]
		<< setw(2) << (int)guid._bytes[2]
		<< setw(2) << (int)guid._bytes[3]
		<< "-"
		<< setw(2) << (int)guid._bytes[4]
		<< setw(2) << (int)guid._bytes[5]
		<< "-"
		<< setw(2) << (int)guid._bytes[6]
		<< setw(2) << (int)guid._bytes[7]
		<< "-"
		<< setw(2) << (int)guid._bytes[8]
		<< setw(2) << (int)guid._bytes[9]
		<< "-"
		<< setw(2) << (int)guid._bytes[10]
		<< setw(2) << (int)guid._bytes[11]
		<< setw(2) << (int)guid._bytes[12]
		<< setw(2) << (int)guid._bytes[13]
		<< setw(2) << (int)guid._bytes[14]
		<< setw(2) << (int)guid._bytes[15];
}

Guid::Guid(const vector<unsigned char> &bytes) {
	_bytes = bytes;
}

Guid::Guid(const unsigned char *bytes) {
	_bytes.assign(bytes, bytes + 16);
}

unsigned char hexDigitToChar(char ch) {
	if (ch > 47 && ch < 58)
		return ch - 48;
	if (ch > 96 && ch < 103)
		return ch - 87;
	if (ch > 64 && ch < 71)
		return ch - 55;
	return 0;
}

unsigned char hexPairToChar(char a, char b) {
	return hexDigitToChar(a) * 16 + hexDigitToChar(b);
}

Guid::Guid(const string &fromString) {
	_bytes.clear();

	char charOne, charTwo;
	bool lookingForFirstChar = true;

	for (const char &ch : fromString) {
		if (ch == '-')	continue;
		if (lookingForFirstChar) {
			charOne = ch;
			lookingForFirstChar = false;
		} else {
			charTwo = ch;
			auto byte = hexPairToChar(charOne, charTwo);
			_bytes.push_back(byte);
			lookingForFirstChar = true;
		}
	}
}

Guid::Guid() {
	_bytes = vector<unsigned char>(16, 0);
}

Guid::Guid(const Guid &other) {
	_bytes = other._bytes;
}

Guid &Guid::operator=(const Guid &other) {
	_bytes = other._bytes;
	return *this;
}

bool Guid::operator==(const Guid &other) const {
	return _bytes == other._bytes;
}

bool Guid::operator!=(const Guid &other) const {
	return !((*this) == other);
}

#ifdef LIBUUID
Guid createGuid() {
	uuid_t id;
	uuid_generate(id);
	return id;
}
#endif

#ifdef GUID
Guid createGuid() {
	GUID newId;
	CoCreateGuid(&newId);

	const unsigned char bytes[16] = 
	{
		(newId.Data1 >> 24) & 0xFF,
		(newId.Data1 >> 16) & 0xFF,
		(newId.Data1 >> 8) & 0xFF,
		(newId.Data1) & 0xFF,
		(newId.Data2 >> 8) & 0xFF,
		(newId.Data2) & 0xFF,
		(newId.Data3 >> 8) & 0xFF,
		(newId.Data3) & 0xFF,
		newId.Data4[0],
		newId.Data4[1],
		newId.Data4[2],
		newId.Data4[3],
		newId.Data4[4],
		newId.Data4[5],
		newId.Data4[6],
		newId.Data4[7]
	};

	return bytes;
}
#endif