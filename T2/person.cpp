#include "person.hpp"
#include <string>
#include <fstream>
#include <algorithm>

//Tá funfando
void loadDb(string path, vector<personPF> &pessoas, vector<personPJ> &empresas)
{
    ifstream filereader;
    filereader.open(path);
    if (!filereader.is_open())
    {
        cout << "Could not find a database; creating a new one" << endl;
        ofstream novo;
        novo.open(path);
        novo.close();
        return;
    }
    string tmp;
    personPF pessoa;
    personPJ empresa;
    while (getline(filereader, tmp))
    {
        if (tmp == "1")
        {
            getline(filereader, pessoa.name);
            getline(filereader, pessoa.nameMae);
            getline(filereader, pessoa.cpf);
            getline(filereader, pessoa.endereco);
            filereader >> pessoa.telefone;
            pessoas.push_back(pessoa);
        }
        if (tmp == "2") //só p ter ctz q n vai quebrar
        {
            getline(filereader, empresa.razaoSocial);
            getline(filereader, empresa.cnpj);
            getline(filereader, empresa.endereco);
            getline(filereader, empresa.telefone);
            filereader >> empresa.capitalSocial;
            empresas.push_back(empresa);
        }
    }
}
//Tá funfando? não tava n kkkk
void saveDb(string path, const vector<personPF> &pessoas, const vector<personPJ> &empresas)
{
    ofstream arquivo(path);
    int i;

    for (i = 0; i < pessoas.size(); i++)
    {
        arquivo << "1" << endl;
        arquivo << pessoas[i].name << endl;
        arquivo << pessoas[i].nameMae << endl;
        arquivo << pessoas[i].cpf << endl;
        arquivo << pessoas[i].endereco << endl;
        arquivo << pessoas[i].telefone << endl;
    }

    for (i = 0; i < empresas.size(); i++)
    {
        arquivo << "2" << endl;
        arquivo << empresas[i].razaoSocial << endl;
        arquivo << empresas[i].cnpj << endl;
        arquivo << empresas[i].endereco << endl;
        arquivo << empresas[i].telefone << endl;
        arquivo << empresas[i].capitalSocial << endl;
    }

    arquivo.close();
}
void addPF(vector<personPF> &pessoas)
{
    personPF individuo;
    if (NCOUT)
        cout << "Insira o nome: ";
    getline(cin, individuo.name);
    if (NCOUT)
        cout << "Insira o nome da mae: ";
    getline(cin, individuo.nameMae);
    if (NCOUT)
        cout << "Insira o cpf: ";
    getline(cin, individuo.cpf);
    if (NCOUT)
        cout << "Insira o endereco: ";
    getline(cin, individuo.endereco);
    if (NCOUT)
        cout << "Insira o telefone: ";
    cin >> individuo.telefone;
    pessoas.push_back(individuo);
}

void addPJ(vector<personPJ> &empresas)
{
    personPJ empresa;
    if (NCOUT)
        cout << "Insira a Razao Social";
    getline(cin, empresa.razaoSocial);
    if (NCOUT)
        cout << "Insira o cnpj";
    getline(cin, empresa.cnpj);
    if (NCOUT)
        cout << "Insira o endereco";
    getline(cin, empresa.endereco);
    if (NCOUT)
        cout << "Insira o telefone";
    getline(cin, empresa.telefone);
    if (NCOUT)
        cout << "Insira o capital social";
    cin >> empresa.capitalSocial;
    empresas.push_back(empresa);
    cin.ignore();
}

void removePF(vector<personPF> &pessoas, int indice)
{
    pessoas.erase(pessoas.begin() + indice);
}

void removePJ(vector<personPJ> &empresas, int indice)
{
    empresas.erase(empresas.begin() + indice);
}

void names(const vector<personPF> &pessoas, const vector<personPJ> &empresas)
{
    int i;
    cout << "Names in Ascendind Order:" << endl;
    vector<string> nomes;
    for (i = 0; i < pessoas.size(); i++)
        nomes.push_back(pessoas[i].name);
    for (i = 0; i < empresas.size(); i++)
        nomes.push_back(empresas[i].razaoSocial);
    stable_sort(nomes.begin(), nomes.end());
    for (auto it = nomes.begin(); it != nomes.end(); ++it)
        cout << *it << endl;
}