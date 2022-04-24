#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <algorithm>
#include <numeric>

using namespace std;

// Prints the elements of a container
template <typename T>
void print(const T& t) {
	cout << "Elements of container:\n";
	
	for (const auto a : t) {
		cout << a << endl;
	}
	cout << endl;
}

int main()
try {
	// Reading from file "input_items.txt"
	const string iname{"input_doubles.txt"};
	ifstream ifs {iname};
	if(!ifs) throw runtime_error("Couldn't read from file: " + iname);

	vector<double> vd;
	for(double d ; ifs >> d;) {
		vd.push_back(d);
	}
	ifs.close();

	print(vd);

	// Copy of vector<double> into a vector<int>
	vector<int> vi(vd.size());
	copy(vd.begin(), vd.end(), vi.begin());
	print(vi);

	// Comparing the two vectors
	cout << "Pairs of vector<double> and vector<int>:";
	for (int i = 0; i < vd.size(); i++) {
		cout << vd[i] << '\t' << vi[i] << endl;
	}

	// Difference between the sums of the two vectors
	double sum_vd = accumulate(vd.begin(), vd.end(), 0.0);
	int sum_vi = accumulate(vi.begin(), vi.end(), 0);
	double diff = sum_vd - sum_vi;

	cout << "\nDifference between sum of vector<double> and vector<int>:" << diff << "\n\n";

	// Reverse of vector<double>
	reverse(vd.begin(), vd.end());
	print(vd);

	// Mean of vector<double>
	double mean_vd = sum_vd / vd.size();
	cout << "Mean of vector<double>:" << mean_vd << "\n\n";

	// A copy of vector<double>, contains elements smaller than mean
	vector<double> vd2;
	for (double d : vd) {
		if (d < mean_vd) vd2.push_back(d);
	}
	print(vd2);

	// Sort of vector<double>
	sort(vd.begin(), vd.end());
	print(vd);
	return 0;	
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cout << "Something went wrong" << endl;
	return 2;
}
