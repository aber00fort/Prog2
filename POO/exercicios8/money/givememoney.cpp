#include "func.hpp"

int main(){
    Empregado Joao(1000, "João");
    Gerente Josias(2500, "Josias", "RH");
    Vendedor Jesiel(1750, "Jesiel", 4);
    cout << Joao.toString() << endl;
    cout << Josias.toString() << endl;
    cout << Jesiel.toString() << endl;
    return 0;
}