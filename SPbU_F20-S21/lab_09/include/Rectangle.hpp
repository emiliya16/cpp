#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
 
#include "Figure.hpp"

class Rectangle : public Figure
{
	int width = 1;
	int height = 1;
	
public:
	Rectangle(int _x, int _y);
	~Rectangle();
	
	void print() override;
	void zoom(int factor) override;
	bool is_inside(int x, int y) override;
};
 
#endif
