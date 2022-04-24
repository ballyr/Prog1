#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <algorithm>

using namespace std;

struct Item {
public:
	Item() {}
	Item(string n, int id, double v) : name{n}, iid{id}, value{v} {}

	string name;
	int iid;
	double value;
};

// Operator overflow
istream& operator>> (istream& is, Item& i) {
	string n;
	int id;
	double v;

	is >> n >> id >> v;

	i = Item(n, id, v);
	return is;
}

ostream& operator<< (ostream& os, Item& i) {
	return os << i.name << ", " << i.iid << ", " << i.value;
}

void print_items(list<Item> li) {
	for (Item i : li) {
		cout << i << endl;
	}
}

// Sorting by name 
bool compare_name(const string& a, const string& b) {
	return (a < b);
}

// Converts strings to lowercase
string lower(string s) {
	transform(s.begin(), s.end(), s.begin(),
    [](unsigned char c){ return std::tolower(c); });
    return s;
}

// Finds the postition of the item, by looking for its name
int find_position_by_name(list<Item> li, string s) {
	int position = 0;
	for (Item i : li) {
		if (i.name == s)
			break;
		else
			position++;
	}
	return position;
}

// Finds the postition of the item, by looking for its iid
int find_position_by_iid(list<Item> li, int id) {
	int position = 0;
	for (Item i : li) {
		if (i.iid == id)
			break;
		else
			position++;
	}
	return position;
}

int main()
try {
	// Reading from file "input_items.txt"
	const string iname{"input_items.txt"};
	ifstream ifs {iname};
	if(!ifs) throw runtime_error("Couldn't read from file: " + iname);

	list<Item> li;
	for(Item i; ifs >> i;) {
		li.push_back(i);
	}
	ifs.close();

	cout << "Elements of li:\n";
	print_items(li);
	
	// Sorting
	cout << "\nSorted by name:\n";
	li.sort([](Item const & a, Item const & b) -> bool { return lower(a.name) < lower(b.name); });
	print_items(li);

	// Sorting by iid
	cout << "\nSorted by iid:\n";
	li.sort([](Item const & a, Item const & b) -> bool { return a.iid < b.iid; });
	print_items(li);

	// Sorting by value (decreasing)
	cout << "\nSorted by value:\n";
	li.sort([](Item const & a, Item const & b) -> bool { return a.value > b.value; });
	print_items(li);

	// Inserting 2 items
	cout << "\nInserted 2 new items:\n";
	li.push_back(Item("horse shoe", 99, 12.34));
	li.push_back(Item("Cannon S400", 9988, 499.95));
	print_items(li);

	// Removing by name
	cout << "\nRemoved Item with the name 'gloves' and 'steering_wheel':\n";
	list<Item>::iterator it1, it2, it3, it4;

	it1 = it2 = it3 = it4 = li.begin();
	advance(it1, find_position_by_name(li, "gloves"));
	advance(it2, find_position_by_name(li, "steering_wheel"));

	li.erase(it1);
	li.erase(it2);
	print_items(li);

	// Removing by iid
	cout << "\nRemoved Item with the iid '7' and '2':\n";

	advance(it3, find_position_by_iid(li, 7));
	advance(it4, find_position_by_iid(li, 2));

	li.erase(it3);
	li.erase(it4);
	print_items(li);

	return 0;
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cout << "Something went wrong" << endl;
	return 2;
}
