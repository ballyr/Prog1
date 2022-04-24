#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctype.h>

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

void print_items(vector<Item> vi) {
	for (Item i : vi) {
		cout << i << endl;
	}
}

// Converts strings to lowercase
string lower(string s) {
	transform(s.begin(), s.end(), s.begin(),
    [](unsigned char c){ return std::tolower(c); });
    return s;
}

// Finds the postition of the item, by looking for its name
int find_position_by_name(vector<Item> vi, string s) {
	int position = 0;
	for (Item i : vi) {
		if (i.name == s)
			break;
		else
			position++;
	}
	return position;
}

// Finds the postition of the item, by looking for its iid
int find_position_by_iid(vector<Item> vi, int id) {
	int position = 0;
	for (Item i : vi) {
		if (i.iid == id)
			break;
		else
			position++;
	}
	return position;
}

int main()
try {
	
	const string iname{"input_items.txt"};
	ifstream ifs {iname};
	if(!ifs) throw runtime_error("Couldn't read from file: " + iname);

	vector<Item> vi;
	for(Item i; ifs >> i;) {
		vi.push_back(i);
	}
	ifs.close();

	cout << "Elements of vi:\n";
	print_items(vi);
	
	// Sorting by name
	cout << "\nSorted by name:\n";
	sort(vi.begin(), vi.end(), [](Item const & a, Item const & b) -> bool { return lower(a.name) < lower(b.name); });
	print_items(vi);

	// Sorting by iid
	cout << "\nSorted by iid:\n";
	sort(vi.begin(), vi.end(), [](Item const & a, Item const & b) -> bool { return a.iid < b.iid; });
	print_items(vi);

	// Sorting by value (decreasing)
	cout << "\nSorted by value:\n";
	sort(vi.begin(), vi.end(), [](Item const & a, Item const & b) -> bool { return a.value > b.value; });
	print_items(vi);

	// Inserting 2 items
	cout << "\nInserted 2 new items:\n";
	vi.push_back(Item("horse shoe", 99, 12.34));
	vi.push_back(Item("Cannon S400", 9988, 499.95));
	print_items(vi);

	// Removing by name
	cout << "\nRemoved Item with the name 'gloves' and 'steering_wheel':\n";
	vi.erase (vi.begin() + find_position_by_name(vi, "gloves"));
	vi.erase (vi.begin() + find_position_by_name(vi, "steering_wheel"));
	print_items(vi);

	// Removing by iid
	cout << "\nRemoved Item with the iid '7' and '2':\n";
	vi.erase (vi.begin() + find_position_by_iid(vi, 7));
	vi.erase (vi.begin() + find_position_by_iid(vi, 2));
	print_items(vi);

	return 0;
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cout << "Something went wrong" << endl;
	return 2;
}
