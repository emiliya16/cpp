#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <cstddef>
 
class Figure
{
public:
	Figure(int _x, int _y);
	virtual ~Figure() = default;
	virtual void print() {};
	virtual void zoom(int factor) {};
	virtual bool is_inside(int x, int y) {return true;}
	void move(int new_x, int new_y);
protected:
    int m_id;
    static int total_;
    int m_x;
    int m_y;
};
 
#endif
