#include "func.hpp"
#include <iomanip>

int main(){
    IngressoVIP avengers(10.0, 7.0);
    cout << "O ingresso VIP custa " << avengers.toString() << " reais." << endl;
    Ingresso coiso(15);
    cout << "O ingresso custa " << coiso.toString() << " reais." << endl;
    return 0;
}