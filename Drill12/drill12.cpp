#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

// g++ drill12.cpp GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp -o drill12 `fltk-config --ldflags --use-images`
// TODO: Comment, change elements(color, pos, size etc.)
int main()
try {

	using namespace Graph_lib;

	// Simple window
	Point p (100, 100);

	Simple_window win (p, 600, 400, "My Window");

	win.wait_for_button();

	// X and Y axis
	Axis xa {Axis::x, Point{30, 375}, 350, 15, "x axis"};
	xa.set_color(Color::blue);
	xa.label.set_color(Color::dark_blue);
	win.attach(xa);

	win.set_label("X axis");
	win.wait_for_button();

	Axis ya {Axis::y, Point{30, 375}, 350, 15, "y axis"};
	ya.set_color(Color::blue);
	ya.label.set_color(Color::dark_blue);
	win.attach(ya);

	win.set_label("Y axis");
	win.wait_for_button();

	// Sine Function
	Function sine {sin, 0, 100, Point{30, 200}, 1000, 25, 25};
	sine.set_color(Color::red);
	win.attach(sine);

	win.set_label("Sine Function");
	win.wait_for_button();

	// Triangle using Polygon
	Polygon poly;
	poly.add(Point{200, 300});
	poly.add(Point{350, 75});
	poly.add(Point{175, 150});

	poly.set_color(Color::dark_yellow);
	poly.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dot, 3.5));
	win.attach(poly);

	win.set_label("Polygon");
	win.wait_for_button();

	// Rectangle
	Rectangle r {Point{300, 175}, 140, 75};
	win.attach(r);

	win.set_label("Rectangle");
	win.wait_for_button();

	// Closed Polyline
	Closed_polyline poly_rect;
	poly_rect.add(Point{555, 75});
	poly_rect.add(Point{475, 60});
	poly_rect.add(Point{600, 100});
	poly_rect.add(Point{500, 300});
	poly_rect.add(Point{400, 100});
	poly_rect.add(Point{460, 150});

	win.attach(poly_rect);

	win.set_label("Rectangle 2");
	win.wait_for_button();

	r.set_fill_color(Color::magenta);
	r.set_color(Color::dark_magenta);
	r.set_style(Line_style(Line_style::dashdotdot, 4));

	poly_rect.set_style(Line_style(Line_style::solid, 2));
	poly_rect.set_color(Color::dark_green);
	poly_rect.set_fill_color(Color::green);

	win.set_label("Fill");
	win.wait_for_button();

	// Text
	Text t {Point{150, 350}, "Hello world! I'm a text."};
	//t.set_font(Font::times);		// error: reference to "Font" is ambiguous
	t.set_font_size(30);

	win.attach(t);

	win.set_label("Text");
	win.wait_for_button();

	// Image
	Image img {Point{10, 150}, "GUI/badge.jpg"};

	win.attach(img);

	win.set_label("Image");
	win.wait_for_button();

	// Moving Image
	img.move(175, 175);

	win.set_label("Image Moved");
	win.wait_for_button();

	// Circle
	Circle c {Point{100, 200}, 75};
	c.set_fill_color(Color::red);
	c.set_color(Color::dark_red);
	win.attach(c);

	// Ellipse
	Ellipse e {Point{100, 200}, 100, 50};
	e.set_color(Color::dark_green);
	e.set_fill_color(Color::green);
	win.attach(e);

	// Mark
	Mark m {Point{100, 200}, 'X'};
	m.set_color(Color::red);
	win.attach(m);

	// Screen/Window Size
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max() 
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100, 20}, oss.str()};
	sizes.set_font_size(15);
	win.attach(sizes);
	
	win.set_label("Circe, Ellipse, Mark");
	win.wait_for_button();
	return 0;
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cout << "Something went wrong" << endl;
	return 2;
}