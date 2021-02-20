#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <vector>

#define NCOUT 1

using namespace std;

struct personPF{
    string name;
    string nameMae;
    string cpf;
    string endereco;
    string telefone;
};

struct personPJ{
    string razaoSocial;
    string cnpj;
    string endereco;
    string telefone;
    size_t capitalSocial;
};

void loadDb(string path, vector<personPF> &pessoas, vector<personPJ> &empresas);
void saveDb(string path, const vector<personPF> &pessoas, const vector<personPJ> &empresas);
void addPF(vector<personPF> &pessoas);
void addPJ(vector<personPJ> &empresas);
void removePF(vector<personPF> &pessoas, int indice);
void removePJ(vector<personPJ> &empresas, int indice);
void names(const vector<personPF> &pessoas, const vector<personPJ> &empresas);

#endif //PERSON_HPP