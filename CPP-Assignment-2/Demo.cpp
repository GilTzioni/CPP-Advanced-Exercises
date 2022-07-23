
#include "FamilyTree.hpp"
#include <iostream>

using namespace std;

int main() {

	family::Tree T ("Yosef");
	T.addFather("Yosef", "Yaakov");
	T.addMother("Yosef", "Rachel");
	T.addFather("Yaakov", "Isaac");
	T.addMother("Yaakov", "Rivka");
	T.addFather("Rachel", "Avi");
	T.addMother("Rachel", "Ruti");
	T.addFather("Isaac", "Avraham");
	T.addMother("Isaac", "Ruti");
	T.addFather("Avraham", "Yosi");
	
	T.addFather("Avi", "Israel");
	T.addMother("Avi", "Sara");
    	T.remove("Yosi");
    	T.addFather("Avraham", "Ido");
	
    	T.display(); 
    	T.find("father");
    
	cout << T.relation("Yaakov") << endl;  // prints "father"
	cout << T.relation("Rachel") << endl;  // prints "mother"
	cout << T.relation("Rivka") << endl;  // prints "grandmother"
	cout << T.relation("Avraham") << endl;  // prints "great-grandfather"
	cout << T.relation("Terah") << endl;  // prints "great-great-grandfather"
	cout << T.relation("xyz") << endl;  // prints "unrelated"
	
	cout << T.relation("Yosef") << endl;  // prints "me"
	
	cout << T.find("mother") << endl;  // prints "Rachel"
	cout << T.find("great-grandmother") << endl;  // prints "Terah"
	
	try {
		cout << T.find("uncle") << endl;  // throws an exception
	}
	catch (const exception& ex) {
	 	cout << ex.what() << endl;  // prints "The tree cannot handle the 'uncle' relation"
	}

	T.remove("Avraham"); // removes Avraham and Terah
    
	cout << T.relation("Terah") << endl;  // prints "unrelated"
    	return 0;
}
