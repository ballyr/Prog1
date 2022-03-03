#include <iostream>
#include <iostream>

using namespace std;

// virtual and non-virtual functions outputs class name and function name
class B1 {
public:
	virtual void vf(){cout << "B1::vf()" << endl;}
	void f(){cout << "B1::f()" << endl;}
	virtual void pvf() = 0;		// pure void/abstact function, makes class abstract
};

// Inherits B1 overrides the functions
class D1 : public B1 {
public:
	void vf(){cout << "D1::vf()" << endl;}
	void f(){cout << "D1::f()" << endl;}
};

class D2 : public D1 {
public:
	void pvf(){cout << "D2::pvf()" << endl;}
};

class B2 {
public:
	virtual void pvf() = 0;
};

class D21 : public B2 {
public:
	string s;
	void pvf(){cout << s << endl;}
};

class D22 : public B2 {
public:
	int n;
	void pvf(){cout << n << endl;}
};

void f(B2& b2) {
	b2.pvf();
}

int main()
try {
	// Calling classes and their functions

	/* Can't  declare variable of abstract type
	B1 b1;
	b1.vf();
	b1.f();

	D1 d1;
	d1.vf();
	d1.f();

	B1& b1ref = d1;
	b1ref.vf();
	b1ref.f();
	b1ref.pvf();
	*/

	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();

	D21 d21;
	d21.s = "d21.s";
	d21.pvf();

	D22 d22;
	d22.n = 22;
	d22.pvf();

	f(d21);
	f(d22);

	return 0;
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cout << "Something went wrong" << endl;
	return 2;
}