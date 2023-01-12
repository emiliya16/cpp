#include "../include/Figure.hpp"

#include <cstdio>
 
Figure::Figure(int _x, int _y):
	m_x(_x), m_y(_y)
{
	m_id = total_++;
    printf("Add figure ");
}

void Figure::move(int new_x, int new_y)
{
	m_x = new_x;
	m_y = new_y;
	printf("move figure id %d\n", m_id);
}
