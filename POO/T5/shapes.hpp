#ifndef SHAPES_HPP
#define SHAPES_HPP
#define PI           3.14159265358979323846  /* pi */
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

enum DataType {tnone, tcircle, tsquare, ttriangle, tsphere, ttetrahedron, tcube};

class Circle{
private:
    float m_ratio;
public:
    Circle(){m_ratio = 0;};
    Circle(float r){m_ratio = r;};
    float getArea() const {return (PI*pow(m_ratio,2));}
    ~Circle(){};
};

class Square{
private:
    float m_edge;
public:
    Square(){m_edge = 0;};
    Square(float e){m_edge = e;};
    float getArea() const {return pow(m_edge,2);}
    ~Square(){};
};

class Triangle{
private:
    pair<float, float> m_p1, m_p2, m_p3;
    float m_e1, m_e2, m_e3;
public:
    Triangle(){m_e1=m_e2=m_e3=0; m_p1=m_p2=m_p3={0,0};};
    Triangle(float e1, float e2, float e3);
    Triangle(pair<float,float> p1, pair<float,float> p2, pair<float,float> p3);
    void setEdges();
    float getArea();
    ~Triangle(){};
};

class Sphere{
private:
    float m_ratio;
public:
    Sphere(){m_ratio = 0;};
    Sphere(float r) {m_ratio = r;};
    float getArea() {return (4*PI*pow(m_ratio,2));}
    ~Sphere(){};
};

class Tetrahedron{
private:
    vector<float> m_p1, m_p2, m_p3, m_p4;
public:
    Tetrahedron(){m_p1=m_p2=m_p3=m_p4={};};
    Tetrahedron(vector<float> p1, vector<float> p2, vector<float> p3, vector<float> p4);
    float getArea();
    ~Tetrahedron(){};
};

class Cube{
private:
    float m_edge;
public:
    Cube(){};
    Cube(float e) {m_edge = e;};
    float getArea() const {return (6*(pow(m_edge, 2)));}
    ~Cube(){};
};

class GenericShape{
private:
    void* m_data;
    DataType m_dataType;
    
public:
    GenericShape()                            { m_data = NULL;               m_dataType=tnone;        };
    GenericShape(Circle c)                    { m_data = new Circle(c);      m_dataType=tcircle;      };
    GenericShape(Square s)                    { m_data = new Square(s);      m_dataType=tsquare;      };
    GenericShape(Triangle t)                  { m_data = new Triangle(t);    m_dataType=ttriangle;    };
    GenericShape(Sphere s)                    { m_data = new Sphere(s);      m_dataType=tsphere;      };
    GenericShape(Tetrahedron t)               { m_data = new Tetrahedron(t); m_dataType=ttetrahedron; };
    GenericShape(Cube c)                      { m_data = new Cube(c);        m_dataType=tcube;        };

    string ShowInfo();
    string ShowArea();
    ~GenericShape();
};

vector<string> split(const string& text, char div);

size_t potencia(size_t decimais);

float side(const string& temp);

pair<float, float> point(const string& temp);

vector<float> point3d(const string& temp);

#endif //SHAPES_HPP