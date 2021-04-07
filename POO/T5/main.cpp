#include "shapes.hpp"
#include <fstream>
#include <string>
#include <iomanip>

#define NCOUT true;

int main(){
    string path;
    cin >> path;
    fstream filereader(path);
    string temp;
    size_t i = 0;
    vector<GenericShape*> list;
    while(filereader >> temp){
        if(temp == "circle"){
            float aux;
            filereader >> temp;
            if(temp.find('.') == -1) aux = stof(temp);
            else aux = side(temp);
            Circle circ(aux);
            list.push_back(new GenericShape(circ));
        }
        else if(temp == "square"){
            float aux;
            filereader >> temp;
            if(temp.find('.') == -1) aux = stof(temp);
            else aux = side(temp);
            Square square(aux);
            list.push_back(new GenericShape(square));
        }
        else if(temp == "triangle"){
            filereader >> temp;
            Triangle var;
            if(temp.find(",") != -1){
                pair<float, float> pa, pb, pc;
                pa = point(temp);
                filereader >> temp;
                pb = point(temp);
                filereader >> temp;
                pc = point(temp);
                Triangle triangle(pa, pb, pc);
                triangle.setEdges();
                var = triangle;
            }
            else{
                float a, b, c;
                if(temp.find(".")==-1) a = atof(temp.c_str());
                else a = side(temp);
                filereader >> temp;
                if(temp.find(".")==-1) b = atof(temp.c_str());
                else b = side(temp);
                filereader >> temp;
                if(temp.find(".")==-1) c = atof(temp.c_str());
                else c = side(temp);
                Triangle triangle(a, b, c);
                var = triangle;
            }
            list.push_back(new GenericShape(var));
        }
        else if(temp == "sphere"){
            float aux;
            filereader >> temp;
            if(temp.find('.') == -1) aux = stof(temp);
            else aux = side(temp);
            Sphere sphere(aux);
            list.push_back(new GenericShape(sphere));
        }
        else if(temp == "tetrahedron"){
            filereader >> temp;
            vector<float> pa, pb, pc, pd;
            pa = point3d(temp);
            filereader >> temp;
            pb = point3d(temp);
            filereader >> temp;
            pc = point3d(temp);
            filereader >> temp;
            pd = point3d(temp);
            Tetrahedron tetra(pa, pb, pc, pd);
            list.push_back(new GenericShape(tetra));
        }
        else if(temp == "cube"){
            float aux;
            filereader >> temp;
            if(temp.find('.') == -1) aux = stof(temp);
            else aux = side(temp);
            Cube cube(aux);
            list.push_back(new GenericShape(cube));
        }
    }
    for(int i=0; i<list.size(); i++){
        cout << "Object #" << i << list.at(i)->ShowInfo() << endl;
        delete(list.at(i));
    }
}