#include <iotream>
#include <fstream>
#include <graphics.h>
#include <cmath>
#include <ctime>
#include <string.h>
using namespace std;
int main()
{
    int zoom_rectangle(int a, int b, int n)
    {
    	return a * n, b * n;
    }
    int zoom_circle(int r, int n)
    {
    	return r * n;
    }
    class Students {
    ofstream sircle, digure, rectangle, scheme;
    sircle.open("Circle.hpp");
    digure.open("Figure.hpp");
    rectangle.open("Rectangle.hpp");
    scheme.open("Scheme.hpp");
    
    n = 2;
    circle_id >> Sircle; 
    circle_x >> sircle;
    circle_y >> sircle;
    r >> sircle;
    sircle_s >> sircle;
   
    rectangle_id >> rectangle;
    rectangle_x >> rectangle;
    rectangle_y >> rectangle;
    a >> rectangle;
    b >> rectangle;
    rectangle_s >> rectangle;
    
    a, b = zoom_rectangle(a, b, n);
    r = zoom_sircle(r, n);
    
    setcolor (RGB(255,100,100));
    rectangle(rectangle_x - a/2, rectangle_y - b/2, rectangle_x + a/2, rectangle_y + b/2);
    circle(circle_x, cercle_y, r);
    outtextxy(rectangle_x, rectangle_y, rectangle_s);
    outtextxy(circle_x, circle_y, circle_s);

    sircle.close();
    digure.close();
    rectangle.close();
    scheme.close();
    system("pause");
};
    printf(circle_id, circle_x, circle_y, circle_r, sircle_s)
    printf(rectangle_id, rectangle_x, rectangle_y, )
    return 0;
}
