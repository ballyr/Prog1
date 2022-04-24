#include <iostream>
#include <iomanip>
#include <cmath>
#include <complex>
#include <cerrno>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
try {
	// Size of different types
	cout << "Size of:\n"
		<< "char\t" << sizeof(char) << endl
		<< "short\t" << sizeof(short) << endl
		<< "int\t" << sizeof(int) << endl
		<< "long\t" << sizeof(long) << endl
		<< "double\t" << sizeof(double) << endl
		<< "int*\t" << sizeof(int*) << endl
		<< "double*\t" << sizeof(double*) << endl;

	// Size of different Matrices
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10, 10);
	Matrix<int, 3> e(10, 10, 10);
	
	cout << "\nMatrix sizes:\n"
		<< "1D, int, 10 elements\t" << sizeof(a) << endl
		<< "1D, int, 100 elements\t" << sizeof(b) << endl
		<< "1D, double, 10 elements\t" << sizeof(c) << endl
		<< "2D, int, 10x10 elements\t" << sizeof(d) << endl
		<< "3D, int, 10x10x10 elements\t" << sizeof(e) << endl

	// Number of elements in Matrices
		<< "\nNumber of elements:\n"
		<< "a:\t" << a.size() << endl
		<< "b:\t" << b.size() << endl
		<< "c:\t" << c.size() << endl
		<< "d:\t" << d.size() << endl
		<< "e:\t" << e.size() << endl;

	// Square root of ints
	cout << "Enter ints:\n";
	int num_int = 0;
	while(cin >> num_int) {
		errno = 0;
		sqrt(num_int);
		if (errno == EDOM) cout << "no square root\n";
		else cout << num_int << '\t' << sqrt(num_int) << endl;
	}

	cin.clear();
	cin.ignore();

	// Matrix with 10 floating point values
	cout << "Enter 10 floating point values:\n";
	Matrix<double> m(10);
	double d2;
	for (int i = 0; i < m.size(); ++i) {
		cin >> d2;
		if(!cin) throw runtime_error("Problem reading from cin");
		m[i] = d2;
	}
	cout << "\nMatrix:\n" << m << endl;

	// Multiplication table using a Matrix
	cout << "\nMultiplication table: Enter width:";
	int width;
	cin >> width;

	cout << "Enter height:";
	int height;
	cin >> height;

	Matrix<int, 2> mtable(height, width);

	for(Index i = 0; i < mtable.dim1(); ++i) {
		for (Index j = 0; j < mtable.dim2(); ++j) {
			mtable(i, j) = (i + 1) * (j + 1);
			cout << setw(5) << mtable(i, j);
		}
		cout << endl;
	}

	cin.clear();
	cin.ignore();

	// Matrix with complex numbers 
	Matrix<complex<double>> mcomp(10);
	complex<double> comp;
	cout << "\nEnter 10 complex numbers (Re, Im):";
	for (int i = 0; i < mcomp.size(); ++i) {
		cin >> comp;
		if(!cin) throw runtime_error("Problem reading from cin");
		mcomp[i] = comp;
	}

	cout << "\nComplex matrix: " << mcomp << endl;

	// Sum of the complex matrix
	complex<double> sum;
	for (int i = 0; i < mcomp.size(); ++i) {
		sum += mcomp[i];
	}

	cout << "\nSum of the complex matrix: " << sum << endl;
	// 2 Dimensonal Matrix with six ints
	Matrix<int, 2> mint(2, 3);
	num_int = 0;

	cout << "\nEnter 6 integer values:";
	for(Index i = 0; i < mint.dim1(); ++i) {
		for (Index j = 0; j < mint.dim2(); ++j) {
			cin >> num_int;
			mint(i, j) = num_int;
		}
	}
	cout << "Int Matrix" << mint << endl;
	return 0;
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cout << "Something went wrong" << endl;
	return 2;
}
