#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

// g++ drill13.cpp GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`
int main()
try {

	using namespace Graph_lib;

	// Simple Window
	Point p (100, 100);

	Simple_window win (p, 800, 1000, "Drill 13");

	win.wait_for_button();

	// 8x8 grid
	Lines grid;
	int x_size = 800;
	int y_size = 800;

	for (int i = 100; i <= x_size; i += 100){
		grid.add(Point(i, 0), Point(i, y_size));
		grid.add(Point(0, i), Point(x_size, i));
	}
	win.attach(grid);

	win.wait_for_button();

	// Diagnoal Red Squares
	Graph_lib::Vector_ref<Rectangle> vr;

	for (int i = 0; i < 8; i++){
		vr.push_back(new Rectangle {Point{i * 100, i * 100}, 101, 101});
		vr[vr.size()-1].set_fill_color(Color::red);
		win.attach(vr[vr.size()-1]);
	}

	win.wait_for_button();

	// 3 200x200 Picture
	Graph_lib::Vector_ref<Image> vimg;

	for (int i = 1; i < 4; i++){
		vimg.push_back(new Image {Point{i * 200, 0}, "GUI/badge.jpg"});
		vimg[vimg.size()-1].set_mask(Point{0, 200}, 200, 200);
		win.attach(vimg[vimg.size()-1]);
	}

	win.set_label("Drill 13");

	win.wait_for_button();

	// Moving Image
	Image img_moving {Point{0, 0}, "GUI/badge.jpg"};
	img_moving.set_mask(Point{0, 300}, 100, 100);
	win.attach(img_moving);

	win.wait_for_button();
	int x_pos;
	int y_pos;
	int counter;
	while (true){
		counter++;
		x_pos++;
		img_moving.move(100, 0);

		// Reset to top right corner
		if (y_pos == 7 & x_pos == 8){
			img_moving.move(- 800, - 700);
			y_pos = 0;
			x_pos = 0;
		}

		// Move to line below
		if (x_pos == 8){
			img_moving.move(- 800, 100);
			x_pos = 0;
			y_pos++;
		}

		if (counter == 100) break;

		win.set_label("Drill 13");
		win.wait_for_button();
	}
	

	return 0;
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cout << "Something went wrong" << endl;
	return 2;
}