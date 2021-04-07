#include "func.hpp"
#include <sstream>
#include <iomanip>

bool ContaCorrente::sacar(float qtd){
    if(qtd>saldo) return false;
    saldo-=qtd;
    return true;
}

bool ContaCorrente::transferir(float qtd){
    if(qtd>saldo) return false;
    saldo-=qtd;
    return true;
}

string ContaCorrente::toString(){
    stringstream sst;
    sst << " tem saldo de " << setprecision(2) << fixed << saldo << " reais";
    return sst.str();
}

bool ContaEspecial::sacar(float qtd){
    if(qtd>saldo+limite) return false;
    saldo-=qtd;
    return true;
}   

string ContaEspecial::toString(){
    stringstream sst;
    sst << " tem saldo de " << setprecision(2) << fixed << saldo << " reais e limite de " << setprecision(2) << fixed << limite;
    return sst.str();
}

string Cliente::toString(){
    string str = "cliente " + name;
    return str;
}

void Cliente::contas(int aux){
    //1 = Conta Corrente
    //2 = Ambas
    //3 = Conta Especial
    if(aux == 1|| aux == 2){
        if(correntes.size()>0){
            cout << "Contas Correntes" << endl << endl;
            for(int i=0; i<correntes.size(); i++){
                cout << "Conta Corrente " << i << correntes.at(i).toString() << endl;
            }
            cout << endl << endl;
        }
    }
    if(aux == 2|| aux == 3){
        if(especiais.size()>0){
            cout << "Contas Especiais" << endl << endl;
            for(int j=0; j<especiais.size(); j++){
                cout << "Conta Especial " << j << especiais.at(j).toString() << endl;
            }
        }
    }
}

bool Cliente::salvarCC(ContaCorrente conta){
    int aux = correntes.size();
    correntes.push_back(conta);
    if(correntes.size()>aux) return true;
    return false;
}

bool Cliente::salvarCE(ContaEspecial conta){
    int aux = especiais.size();
    especiais.push_back(conta);
    if(especiais.size()>aux) return true;
    return false;
}