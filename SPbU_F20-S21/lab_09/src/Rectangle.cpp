#include "../include/Rectangle.hpp"

#include <cstdio>
 
Rectangle::Rectangle(int _x, int _y) : Figure(_x, _y)
{
    printf("rectangle\n");
}

Rectangle::~Rectangle()
{
    printf("Delete rectangle id %d\n", m_id);
}

void Rectangle::print()
{
	printf("Rectangle %d: x = %d y = %d width = %d height = %d\n", m_id, m_x, m_y, width, height);
}

void Rectangle::zoom(int factor)
{
	width 	+= factor;
	height	+= factor;
	printf("zoom rect id %d\n", m_id);
}

bool Rectangle::is_inside(int x, int y)
{
	int right	= m_x + width/2;
	int left	= m_x - width/2;
	int bottom	= m_y + height/2;
	int top		= m_y - height/2;
	return (x <= right && x>= left && y<= bottom && y >= top);
}
