#include "shapes.hpp"
#include <sstream>
#include <iomanip>

void split(const string& text, char div, vector<string> &partes){
    string aux;
    size_t start = 0, end = 0;
    while((end = text.find(div, start)) != -1){
        aux = text.substr(start, end - start);
        partes.push_back(aux);
        start = end + 1;
    }
    partes.push_back(text.substr(start));
}

size_t potencia(size_t decimais){
    size_t i=0;
    while(decimais>=1){
        decimais = decimais/10;
        i++;
    }
    return i;
}

float side(const string& temp){
    vector<string> partes;
    split(temp, '.', partes);
    float aux = atof(partes.at(0).c_str()) + (atof(partes.at(1).c_str())/pow(10, potencia(atof(partes.at(1).c_str()))));
    return aux;
}

pair<float, float> point(const string& temp){
    vector<string> partes;
    split(temp, ',', partes);
    pair<float, float> aux;
    aux.first = atof(partes.at(0).c_str());
    aux.second = atof(partes.at(1).c_str());
    return aux;
}

vector<float> point3d(const string& temp){
    vector<float> ret;
    char c;
    size_t i = 0;
    string s = "";
    for(size_t i = 0; i < (temp.length()); i++){
        c = temp.at(i);
        if(c == ','){
            if(s.find(".") != -1) ret.push_back(side(s));
            else ret.push_back(atof(s.c_str()));
            s = "";
        }
        else s = s + c;
        if(i == (temp.length() - 1)) ret.push_back(atof(s.c_str()));
    }
    return ret;
}

void Triangle::setEdges(){
    m_e1 = sqrt(pow((m_p1.first-m_p2.first),2)+pow((m_p1.second-m_p2.second),2));
    m_e2 = sqrt(pow((m_p2.first-m_p3.first),2)+pow((m_p2.second-m_p3.second),2));
    m_e3 = sqrt(pow((m_p3.first-m_p1.first),2)+pow((m_p3.second-m_p1.second),2));
}

float Triangle::getArea(){
    float p = (m_e1+m_e2+m_e3)/2;
    float area = sqrt(p*(p-m_e1)*(p-m_e2)*(p-m_e3));
    return area;
}

Triangle::Triangle(float e1, float e2, float e3){
    m_e1 = e1;
    m_e2 = e2;
    m_e3 = e3;
}

Triangle::Triangle(pair<float,float> p1, pair<float,float> p2, pair<float,float> p3){
    m_p1 = p1;
    m_p2 = p2;
    m_p3 = p3;
}

Tetrahedron::Tetrahedron(vector<float> p1, vector<float> p2, vector<float> p3, vector<float> p4){
    m_p1 = p1;
    m_p2 = p2;
    m_p3 = p3;
    m_p4 = p4;
}

float Tetrahedron::getArea(){
    //0=1->2; 1=1->3; 2=1->4; 3=2->3; 4=2->4; 5=3->4
    vector<float> l;
    float edge = sqrt(pow((m_p1.at(0)-m_p2.at(0)),2)+pow((m_p1.at(1)-m_p2.at(1)),2)+pow(m_p1.at(2)-m_p2.at(2),2));
    l.push_back(edge);
    edge = sqrt(pow((m_p1.at(0)-m_p3.at(0)),2)+pow((m_p1.at(1)-m_p3.at(1)),2)+pow(m_p1.at(2)-m_p3.at(2),2));
    l.push_back(edge);
    edge = sqrt(pow((m_p1.at(0)-m_p4.at(0)),2)+pow((m_p1.at(1)-m_p4.at(1)),2)+pow(m_p1.at(2)-m_p4.at(2),2));
    l.push_back(edge);
    edge = sqrt(pow((m_p2.at(0)-m_p3.at(0)),2)+pow((m_p2.at(1)-m_p3.at(1)),2)+pow(m_p2.at(2)-m_p3.at(2),2));
    l.push_back(edge);
    edge = sqrt(pow((m_p2.at(0)-m_p4.at(0)),2)+pow((m_p2.at(1)-m_p4.at(1)),2)+pow(m_p2.at(2)-m_p4.at(2),2));
    l.push_back(edge);
    edge = sqrt(pow((m_p3.at(0)-m_p4.at(0)),2)+pow((m_p3.at(1)-m_p4.at(1)),2)+pow(m_p3.at(2)-m_p4.at(2),2));
    l.push_back(edge);
    float p, area = 0;
    p = (l.at(0)+l.at(1)+l.at(3))/2;
    area += sqrt(p*(p-l.at(0))*(p-l.at(1))*(p-l.at(3)));
    p = (l.at(1)+l.at(2)+l.at(5))/2;
    area += sqrt(p*(p-l.at(1))*(p-l.at(2))*(p-l.at(5)));
    p = (l.at(0)+l.at(2)+l.at(4))/2;
    area += sqrt(p*(p-l.at(0))*(p-l.at(2))*(p-l.at(4)));
    p = (l.at(3)+l.at(4)+l.at(5))/2;
    area += sqrt(p*(p-l.at(3))*(p-l.at(4))*(p-l.at(5)));
    return area;
}

string GenericShape::ShowInfo(){
    stringstream sst;
    if(m_dataType == tnone)   sst << " is none -> NULL";
    if(m_dataType == tcircle) sst << " is circle -> " << setprecision(2) << fixed << (((Circle*) m_data)->getArea());
    if(m_dataType == tsquare) sst << " is square -> " << setprecision(2) << fixed << (((Square*) m_data)->getArea());
    if(m_dataType == ttriangle) sst << " is triangle -> " << setprecision(2) << fixed << (((Triangle*) m_data)->getArea());
    if(m_dataType == tsphere)  sst << " is sphere -> " << setprecision(2) << fixed << (((Sphere*) m_data)->getArea());
    if(m_dataType == ttetrahedron) sst << " is tetrahedron -> " << setprecision(2) << fixed << (((Tetrahedron*) m_data)->getArea());
    if(m_dataType == tcube) sst << " is cube -> " << setprecision(2) << fixed << (((Cube*) m_data)->getArea());
    return sst.str();
}

GenericShape::~GenericShape(){
    if(m_dataType == tcircle) (delete(Circle*) m_data);
    if(m_dataType == tsquare) (delete(Square*) m_data);
    if(m_dataType == ttriangle) (delete(Triangle*) m_data);
    if(m_dataType == tsphere)  (delete(Sphere*) m_data);
    if(m_dataType == ttetrahedron) (delete(Tetrahedron*) m_data);
    if(m_dataType == tcube) (delete(Cube*) m_data);
}
