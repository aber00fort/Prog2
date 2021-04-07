#include "func.hpp"
#include <iomanip>
#include <sstream>

string Empregado::toString(){
    stringstream sst;
    sst << "O empregado " << name << " recebe " << setprecision(2) << fixed << salary << " reais.";
    return sst.str();
}

string Gerente::toString(){
    stringstream sst;
    sst << "O empregado " << name << " é o gerente do departamento " << dpt << " e recebe "<< setprecision(2) << fixed << salary << " reais.";
    return sst.str();
}

string Vendedor::toString(){
    stringstream sst;
    sst << "O empregado " << name << " recebe " << setprecision(2) << fixed << salary << " reais, além de " << setprecision(2) << fixed << percentualComission << "% das vendas, o que totaliza " << setprecision(2) << fixed << calcularSalario();
    return sst.str();
}