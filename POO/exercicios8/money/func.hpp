#include <iostream>

using namespace std;

class Empregado{
    protected:
        float salary;
        string name;
    public:
        Empregado(){salary = 0; name = "";};
        Empregado(float quant, string name_var) {salary = quant; name = name_var;};
        ~Empregado(){cout << this << " is dead";};
        string toString();
};

class Gerente: public Empregado{
    private:
        string dpt;
    public:
        Gerente(){salary = 0; name = ""; dpt = "";};
        Gerente(float quant, string name_var, string place){salary = quant; name = name_var; dpt = place;};
        string toString();
};

class Vendedor: public Empregado{
    private:
        float percentualComission;
    public:
        Vendedor(){salary = 0; name = ""; percentualComission = 0;};
        Vendedor(float quant, string name_var, float percent){salary = quant; name = name_var; percentualComission = percent;};
        float calcularSalario(){return (salary*(100+percentualComission)/100);};
        string toString();
};