#include "../Drill12-13/GUI/Simple_window.h"
#include "../Drill12-13/GUI/Graph.h"

// Functions
double one(double){return 1;}
double slope(double x){return x/2;}
double square(double x){return x*x;}
double sloping_cos(double x){return cos(x) + slope(x);}

int main()
try {
	using namespace Graph_lib;

	// Simple window
	Point p (100, 100);

	Simple_window win (p, 600, 600, "Function graphs");

	win.wait_for_button();

	// X and Y axis
	Axis xa {Axis::x, Point{300, 300}, 400, 20, "x axis"};
	xa.set_color(Color::red);
	win.attach(xa);

	Axis ya {Axis::y, Point{300, 300}, 400, 20, "y axis"};
	ya.set_color(Color::red);
	win.attach(ya);

	win.wait_for_button();

	// Function one
	Function onef{one, -10, 11, Point{300, 300}, 400, 20, 20};

	win.attach(onef);
	win.wait_for_button();

	// Function slope
	Function slopef{slope, -10, 11, Point{300, 300}, 400, 20, 20};
	Text slopet{Point{100, 380}, "x/2"};

	win.attach(slopef);
	win.attach(slopet);
	win.wait_for_button();

	// Function square
	Function squaref{square, -10, 11, Point{300, 300}, 400, 20, 20};

	win.attach(squaref);
	win.wait_for_button();

	// Function cosine
	Function cosf{cos, -10, 11, Point{300, 300}, 400, 20, 20};
	cosf.set_color(Color::blue);

	win.attach(cosf);
	win.wait_for_button();

	// Function sloping cosine
	Function slop_cosf{sloping_cos, -10, 11, Point{300, 300}, 400, 20, 20};

	win.attach(slop_cosf);
	win.wait_for_button();

	return 0;
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cout << "Something went wrong" << endl;
	return 2;
}