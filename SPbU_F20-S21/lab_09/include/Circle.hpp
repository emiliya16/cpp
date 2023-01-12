#ifndef CIRCLE_HPP
#define CIRCLE_HPP
 
#include "Figure.hpp"

#include <string>

class Circle : public Figure
{
private:
	std::string m_label = "";
	int radius = 0;
	
public:
	Circle(int _x, int _y, std::string _label);
	~Circle();
	
	void print() override;
	void zoom(int factor) override;
	bool is_inside(int x, int y) override;
};
 
#endif
