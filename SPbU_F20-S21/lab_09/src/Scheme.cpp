#include "../include/Scheme.hpp"

#include <cstdio>
 
Scheme::Scheme()
{
    printf("Add scheme\n");
}

Scheme::~Scheme()
{
    printf("Delete scheme\n");
    for( int i = 0; i < m_figures.size(); ++i )
		delete m_figures[i];
    m_figures.clear();
}

void Scheme::add_circle(int _x, int _y, std::string _label)
{
	m_figures.push_back( new Circle(_x, _y, _label) );
}

void Scheme::add_rect(int _x, int _y)
{
	m_figures.push_back( new Rectangle(_x, _y) );
}

void Scheme::print_figures()
{
	for(Figure* figure : m_figures)
		figure->print();
}

void Scheme::move_figure(int _id, int _x, int _y)
{
	if( _id <= m_figures.size() )
		m_figures.at(_id)->move(_x, _y);
}
