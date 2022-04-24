#include <iostream>
#include <string>
#include <map>
#include <numeric>
#include <stdexcept>

using namespace std;

// Reads Key(string) and value(int) pairs from input stream
void read_map(map<string, int>& m) {
	string s;
	int i;

	while(m.size() < 10) {
		cin >> s >> i;
		m.insert(make_pair(s, i));
	}
}

// Calculates the sum of ints from the map
template<typename K>
int sum_map(map<K, int>& m) {
	int sum = 0;
	for(auto& a : m){
		sum += a.second;
	}
	return sum;
}

// Prints the elements of a map
template<typename K, typename V>
void print_map(const map<K, V>& m) {
	for(auto a : m) {
		cout << a.first << '\t' << a.second << endl;
	}
}

int main()
try {
	// Map initilaziation
	map<string, int> msi;
	msi["a"] = 1;
	msi["b"] = 2;
	msi["asd"] = 123;
	msi["dsa"] = 321;
	msi["rb"] = 33;
	msi["f"] = 16;
	msi["mto"] = 101;
	msi["fidsoj"] = 1365;
	msi["e"] = 87;
	msi["rtx"] = 3090;

	cout << "Elements of msi:\n";
	print_map(msi);

	// Clearing the map
	msi.erase(msi.begin(), msi.end());
	cout << "\nElements of msi after removing everything:\n";
	print_map(msi);

	// Reading 10 key and value pairs
	cout << "\nEnter 10 pairs:\n";
	read_map(msi);
	cout << "\nmsi:\n";
	print_map(msi);

	// Sum of ints in map
	cout << "\nSum of msi:" << sum_map(msi) << endl;

	// Map with int keys and string values
	map<int, string> mis;
	for (pair<string, int> a : msi) {
		mis[a.second] = a.first;
		mis.insert(make_pair(a.second, a.first));
	}

	cout << "\nElements of mis:\n";
	print_map(mis);

	return 0;
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cout << "Something went wrong" << endl;
	return 2;
}
