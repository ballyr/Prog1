#include "GUI.h"

using namespace Graph_lib;
struct Lines_window : Graph_lib::Window{
	Lines_window(Point xy, int w, int h, const string& title);
private:
	Open_polyline lines;

	// Widgets
	// Buttons
	Button next_button;
	Button quit_button;
	Button cmenu_button;
	Button smenu_button;

	// In/Out box
	In_box next_x;
	In_box next_y;
	Out_box xy_out;

	// Menu
	Menu color_menu;
	Menu style_menu;

	// Functions
	// Change functions
	void change_color(Color c){lines.set_color(c);}
	void change_style(Line_style s){lines.set_style(s);}

	// Hide functions
	void hide_cmenu(){color_menu.hide(); cmenu_button.show();}
	void hide_smenu(){style_menu.hide(); smenu_button.show();}

	// Button functions
	void red_pressed() {change_color(Color::red); hide_cmenu();}
	void blue_pressed() {change_color(Color::blue); hide_cmenu();}
	void black_pressed() {change_color(Color::black); hide_cmenu();}
	void cmenu_pressed() {cmenu_button.hide(); color_menu.show();}

	void dot_pressed() {change_style(Line_style::dot); hide_smenu();}
	void dash_pressed() {change_style(Line_style::dash); hide_smenu();}
	void solid_pressed() {change_style(Line_style::solid); hide_smenu();}
	void smenu_pressed() {smenu_button.hide(); style_menu.show();}

	void next();
	void quit();

};