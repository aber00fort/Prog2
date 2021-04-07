#include "func.hpp"
#include <string>
#include <iomanip>
#include <sstream>

string Ingresso::toString(){
    stringstream sst;
    sst << setprecision(2) << fixed << m_valor;
    return sst.str();
}

string IngressoVIP::toString(){
    stringstream sst;
    sst << setprecision(2) << fixed << m_valor+m_valor_add;
    return sst.str();
}