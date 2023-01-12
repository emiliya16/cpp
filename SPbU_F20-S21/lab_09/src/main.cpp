#include "../include/Scheme.hpp"

#include <iostream>

int Figure::total_ = 0;

int main()
{	
	Scheme *schem = new Scheme();
	schem->add_rect(3, 3);
	schem->add_rect(2, 2);
	schem->add_circle(1, 1, "circle1");
	
	schem->move_figure(1, 5, 5);
	
	schem->print_figures();
	
	delete schem;
	
	return 0;
}
