#include "guidgen.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	cout << "Generating 2 uuids:" << endl;
	
	Guid gen_guid1 = createGuid();
	Guid gen_guid2 = createGuid();
	
	cout << "UUID1: " << gen_guid1 << endl;
	cout << "UUID2: " << gen_guid2 << endl;
	
	if(gen_guid1 == gen_guid2) {
		cout << "WARNING: Random uuids are equal value!" << endl;
	}
	
	if(gen_guid1 != gen_guid2) {
		cout << "SUCCESS: The uuids are different." << endl;
	}
	
	cout << "Creating 3 uuids from string:" << endl;
	
	Guid str_guid1("3d0e53b0-763f-4642-b76e-cc84410cf041");
	Guid str_guid2("2c45907c-1b2e-40ca-bde0-57ec9824fe4a");
	Guid str_guid3("3d0e53b0-763f-4642-b76e-cc84410cf041");
	
	cout << "UUID1: " << str_guid1 << endl;
	cout << "UUID2: " << str_guid2 << endl;
	cout << "UUID3: " << str_guid3 << endl;
	
	if(str_guid1 == str_guid2) {
		cout << "ERROR: UUID1 and UUID2 should be different." << endl;
	}
	
	if(str_guid1 != str_guid2) {
		cout << "SUCCESS: UUID1 and UUID2 are different." << endl;
	}
	
	if(str_guid1 == str_guid3) {
		cout << "SUCCESS: UUID1 and UUID3 are of equal value." << endl;
	}
	
	if(str_guid1 != str_guid3) {
		cout << "ERROR: UUID1 and UUID3 should be of equal value." << endl;
	}
	
	cout << "Creating empty uuid and assigning it the value of UUID1:" << endl;
	
	cout << "DONE!" << endl;
	
}
