#include "Graph.h"
#include "Lines_window.h"

int main()
try {
	using namespace Graph_lib;
	Lines_window win{Point{100, 100}, 1920, 1080, "Drill 16"};
	return gui_main();

} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 1;
} catch (...) {
	cout << "Something went wrong" << endl;
	return 2;
}