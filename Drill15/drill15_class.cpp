#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

// Somelines of code in comment cause of refactoring

class Person{
public:
	Person(){}
	// Person(string n, int a) : n{n}, a{a}{
	Person(string f, string l, int a) : f{f}, l{l}, a{a}{
		if (a < 0 or a >= 150) throw runtime_error("Invalid age");

		string n = f + l;

		for (char c : n){
			switch(c) {
				case ':':
				case ';':
				case '"':
				case '\'':
				case '[':
				case ']':
				case '*':
				case '%':
				case '$':
				case '#':
				case '@':
				case '!': throw runtime_error("Invalid name");
			}
		}
	};
	// string name() const {return n};
	string first() const {return f;};
	string last() const {return l;};
	int age() const {return a;};

private:
	// string n;
	string f;
	string l;
	int a;
};

// Input & Output operator overload
ostream& operator<< (ostream& os, const Person& p){
	// return os << p.name() << " " << p.age();
	return os << p.first() << " " << p.last() << " " << p.age();
}

istream& operator>> (istream& is, Person& p){
	// string n;
	string f;
	string l;
	int a;

	// is >> n >> a;
	is >> f >> l >> a;

	// p = Person(n, a);
	p = Person(f, l, a);
	return is;
	
}
int main()
try {

	// Person p;
	Person p = Person("Goofy", "A", 63);
	// p.n = "Goofy";
	// p.a = 63;

	// cout << p.name() << " " << p.age();
	cout << p.first() << " " << p.last() << " " << p.age();

	Person p2;
	cin >> p2;
	cout << p2 << endl;

	vector<Person> vec;

	while(cin >> p){ // Alt: for (Person p; cin >> p;){
		if (p.first() == "end") break;
		vec.push_back(p);
	}

	for(Person p : vec){
		cout << p << endl;
	}
	return 0;
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cout << "Something went wrong" << endl;
	return 2;
}