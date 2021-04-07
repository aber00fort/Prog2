#ifndef FUNC_HPP
#define FUNC_HPP
#include <iostream>
#include <vector>

using namespace std;

class ContaCorrente{
    protected:
        float saldo;
    public:
        ContaCorrente():saldo(0){};
        ContaCorrente(float qtd): saldo(qtd){};
        void depositar(float qtd){saldo+=qtd;};
        float getSaldo(){return saldo;};
        bool sacar(float qtd);
        bool transferir(float qtd);
        string toString();
        ~ContaCorrente(){};
};

class ContaEspecial: public ContaCorrente{
    private:
        float limite;
    public:
        ContaEspecial(): limite(0){saldo = 0;};
        ContaEspecial(float qtd, float extra):limite(extra){saldo = qtd;};
        float getLimite(){return limite;};
        bool sacar(float qtd);
        string toString();
        ~ContaEspecial(){};
};

class Cliente{
    private:
        string name;
        vector<ContaCorrente> correntes;
        vector<ContaEspecial> especiais;
    public:
        size_t nCC(){return correntes.size();};
        size_t nCE(){return especiais.size();};
        Cliente(): name(""){};
        Cliente(string words): name(words){};
        string getNome(){return name;};
        bool salvarCC(ContaCorrente conta);
        bool salvarCE(ContaEspecial conta);
        ~Cliente(){};
        void contas(int i);
        string toString();
};

#endif //FUNC_HPP