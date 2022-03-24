#include "Lines_window.h"

using namespace Graph_lib;

// Constructor
Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window{xy, w, h, title},
	next_button{Point{x_max()-300, 0}, 150, 40, "Next point",
		[](Address, Address pw) { reference_to<Lines_window>(pw).next(); }},
	quit_button{Point{x_max()-150, 0}, 150, 40, "Quit",
		[](Address, Address pw) { reference_to<Lines_window>(pw).quit(); }},
	next_x{Point{300, 0}, 50, 40, "Next X:"},
	next_y{Point{450, 0}, 50, 40, "Next Y:"},
	xy_out{Point{115, 0}, 100, 40, "Current (x, y):"},

	// Color Menu
	color_menu{Point{x_max()-90, 50}, 90, 30, Menu::vertical, "Color"},
	cmenu_button{Point{x_max()-100, 50}, 100, 30, "Color menu",
		[](Address, Address pw) { reference_to<Lines_window>(pw).cmenu_pressed();}},

	// Style Menu
	style_menu{Point{x_max()-90, 150}, 90, 30, Menu::vertical, "Style"},
	smenu_button{Point{x_max()-100, 150}, 100, 30, "Style menu",
		[](Address, Address pw) { reference_to<Lines_window>(pw).smenu_pressed();}}
{
	// Core Buttons, In/Out
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	xy_out.put("No point");

	// Color Menu Buttons
	color_menu.attach(new Button{Point{0, 0}, 0, 0, "Red",
		[](Address, Address pw) { reference_to<Lines_window>(pw).red_pressed(); }});
	color_menu.attach(new Button{Point{0, 0}, 0, 0, "Blue",
		[](Address, Address pw) { reference_to<Lines_window>(pw).blue_pressed(); }});
	color_menu.attach(new Button{Point{0, 0}, 0, 0, "black",
		[](Address, Address pw) { reference_to<Lines_window>(pw).black_pressed(); }});

	attach(color_menu);
	color_menu.hide();
	attach(cmenu_button);

	// Style Menu Buttons
	style_menu.attach(new Button{Point{0, 0}, 0, 0, "Dot",
		[](Address, Address pw) { reference_to<Lines_window>(pw).dot_pressed(); }});
	style_menu.attach(new Button{Point{0, 0}, 0, 0, "Dash",
		[](Address, Address pw) { reference_to<Lines_window>(pw).dash_pressed(); }});
	style_menu.attach(new Button{Point{0, 0}, 0, 0, "Solid",
		[](Address, Address pw) { reference_to<Lines_window>(pw).solid_pressed(); }});

	attach(style_menu);
	style_menu.hide();
	attach(smenu_button);

	attach(lines);
}

// Quit function
void Lines_window::quit(){
	hide();
}

// Next function
void Lines_window::next(){
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point{x, y});

	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());

	redraw();
}