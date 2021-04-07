#ifndef FUNC_HPP
#define FUNC_HPP

using namespace std;

#include <iostream>
#include <string>

class Ingresso{
    protected:
        float m_valor;
    public:
        Ingresso(){m_valor = 0;};
        Ingresso(float valor){m_valor = valor;};
        string toString();
        ~Ingresso(){cout << "Bye Bye " << this << endl;};

};

class IngressoVIP: public Ingresso{
    private:
        float m_valor_add;
    public:
        IngressoVIP(){m_valor_add=0;};
        IngressoVIP(float valor1, float valor2){m_valor = valor2; m_valor_add = valor1;};
        string toString();
};

#endif//FUNC_HPP