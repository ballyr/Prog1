#include <iostream>
#include <string>
#include <vector>

using namespace std;

// struct S
template<typename T> struct S{
	S(T vv = 0) : val{vv}{};
	T& get();
	const T& get() const;

	void set(T new_t) {val = new_t;};
	void operator=(const T&);

private:
	T val;
};

// function defining from struct S
template<typename T>
T& S<T>::get(){
	return val;
}

template<typename T>
const T& S<T>::get() const{
	return val;
}

template<typename T>
void S<T>::operator=(const T& s){
	val = s;
}

template<typename T>
void read_val(T& v){
	cin >> v;
}

// operator overload
template<typename T>
ostream& operator<<(ostream& os, const vector<T> ve){
	os << "{ ";
	for(int i = 0; i < ve.size(); ++i){
		os << ve[i] << (i < ve.size() - 1 ? ", " : " }");
	}
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& ve){
	char ch = 0;
	int val = 0;
	is >> ch;
	if (ch != '{'){
		is.unget();
		return is;
	}
	while(cin >> val){
		ve.push_back(val);
		is >> ch;
		if (ch != ',') break;
	}
	return is;
}

int main()
try {
	// defining variables with type S<T>
	S<int> s;
	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd {3.2};
	S<string> ss {"Hello"};
	S<vector<int>> svi {vector<int>{1, 1, 2, 3, 5, 8}};

	cout << "S<int>: " << s.get() << endl;
	cout << "S<int>: " << si.get() << endl;
	cout << "S<char>: " << sc.get() << endl;
	cout << "S<double>: " << sd.get() << endl;
	cout << "S<string>: " << ss.get() << endl;
	cout << "S<vector<int>>: " << svi.get() << endl;

	/*cout << "S<vector<int>>: ";
	for (auto a : svi.get()){
		cout << a << ' ';
	}*/
	cout << endl;

	sc.set('s');
	cout << "S<char>: " << sc.get() << endl;

	si = 30;
	cout << "S<int>: " << si.get() << endl;

	// read_val with all variables types from before
	int ii;
	read_val(ii);
	S<int> si2{ii};
	cout << "S<int>: " << si2.get() << endl;

	char cc;
	read_val(cc);
	S<char> sc2{cc};
	cout << "S<char>: " << sc2.get() << endl;

	double dd;
	read_val(dd);
	S<double> sd2{dd};
	cout << "S<double>: " << sd2.get() << endl;

	string str;
	read_val(str);
	S<string> ss2{str};
	cout << "S<str>: " << ss2.get() << endl;

	vector<int> vec;
	read_val(vec);
	S<vector<int>> svec{vec};
	cout << "S<vector<int>>: " << svec.get() << endl;

	return 0;
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cout << "Something went wrong" << endl;
	return 2;
}