#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>

using namespace std;

// Print elements from container
template <typename C>
void print_elements(const C& c){
	for (auto& a : c){
		cout << a << ' ';
	}
	cout << endl;
}

// Increment elements of container by n
template <typename C>
void increment_by(C& c, int n){
	for (auto& a : c){
		a+=n;
	}
}

// copy function
template <typename Iter1, typename Iter2>
Iter2 drill_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for (Iter1 p = f1; p!= e1; ++p){
		*f2 = *p;
		f2++;
	}
	return f2;
}

int main()
try {
	constexpr int size = 10;

	// Array, vector, list with numbers from 0-9
	array<int, size> ai {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> vi {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> li {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	cout << "Elements of array<int>: ";
	print_elements(ai);

	cout << "Elements of vector<int>: ";
	print_elements(vi);

	cout << "Elements of list<int>: ";
	print_elements(li);

	cout << endl;

	// Second set of array, vector, list with the elements from the first set
	array<int, ai.size()> ai2 = ai;
	vector<int> vi2 = vi;
	list<int> li2 = li;

	cout << "Elements of array<int>2: ";
	print_elements(ai2);

	cout << "Elements of vector<int>2: ";
	print_elements(vi2);

	cout << "Elements of list<int>2: ";
	print_elements(li2);

	cout << endl;

	// Increment second array by 2, vector by 3 and list by 5
	increment_by(ai2, 2);
	increment_by(vi2, 3);
	increment_by(li2, 5);

	cout << "Elements of array<int>2 after incrementing by 2: ";
	print_elements(ai2);

	cout << "Elements of vector<int>2 after incrementing by 3: ";
	print_elements(vi2);

	cout << "Elements of list<int>2 after incrementing by 5: ";
	print_elements(li2);

	cout << endl;

	// Copy elements from the first array to the second
	drill_copy(ai.begin(), ai.end(), ai2.begin());
	cout << "Elements of array<int>2 after copying elements from array<int>: ";
	print_elements(ai2);
	return 0;
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cout << "Something went wrong" << endl;
	return 2;
}