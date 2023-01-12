#include "../include/Circle.hpp"

#include <cstdio>
 
Circle::Circle(int _x, int _y, std::string _label):
	m_label(_label), Figure(_x, _y)
{
    printf("circle\n");
}

Circle::~Circle()
{
    printf("Delete circle id %d label %s\n", m_id, m_label.c_str());
}

void Circle::print()
{
	printf("Circle %d: x = %d y = %d radius = %d label = %s\n", m_id, m_x, m_y, radius, m_label.c_str());
}

void Circle::zoom(int factor)
{
	radius += factor;
	printf("zoom circle name %s\n", m_label.c_str());
}

bool Circle::is_inside(int x, int y)
{
    if (((x - m_x) * (x - m_x) + (y - m_y) * (y - m_y)) < radius * radius) {
		return true;
    } else if (((x - m_x) * (x - m_x) + (y - m_y) * (y - m_y)) == radius * radius) {
        return true;
    } else {
        return false;
    }	
}
