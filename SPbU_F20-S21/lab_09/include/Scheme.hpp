#ifndef SCHEME_HPP
#define SCHEME_HPP

#include "Figure.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

#include <vector>
 
class Scheme
{
private:
    std::vector<Figure*> m_figures;
 
public:
    Scheme();
    ~Scheme();
        
    void add_circle(int _x, int _y, std::string _label);
    void add_rect(int _x, int _y);
    
    void print_figures();
    void move_figure(int _id, int _x, int _y);
};
 
#endif
