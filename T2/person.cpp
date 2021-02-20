#include "person.hpp"
#include <string>
#include <fstream>
#include <algorithm>

//Tá funfando
void loadDb(string path, vector<personPF> &pessoas, vector<personPJ> &empresas){
    ifstream filereader;
    filereader.open(path);
    if(!filereader.is_open()){
        cout << "Could not find a database; creating a new one" << endl;
        ofstream novo;
        novo.open(path);
        novo.close();
        return;
    }
    string tmp;
    personPF pessoa;
    personPJ empresa;
    while(getline(filereader,tmp)){
        cout << endl << "tmp" << tmp << endl;
        if(tmp == "1"){
            getline(filereader, pessoa.name);
            getline(filereader, pessoa.nameMae);
            getline(filereader, pessoa.cpf);
            getline(filereader, pessoa.endereco);
            getline(filereader, pessoa.telefone);
            pessoas.push_back(pessoa);
        }
        else{
            getline(filereader, empresa.razaoSocial);
            getline(filereader, empresa.cnpj);
            getline(filereader, empresa.endereco);
            getline(filereader, empresa.telefone);
            filereader >> empresa.capitalSocial;
            empresas.push_back(empresa);
        }
    }
}
//Tá funfando?
void saveDb(string path, const vector<personPF> &pessoas, const vector<personPJ> &empresas){
    ofstream write(path);
    //string coisas;
    int i;
    /*while(getline(reader, coisas)){
        if(coisas == "1"){
            temp << "1\n";
            for(i = 0; i < 5; i++){
                getline(reader, coisas);
                temp << coisas << "\n";
            }
            continue;
        }
        else{
            temp << "2\n";
            for(i = 0; i < 4; i++){
                getline(reader, coisas);
                temp << coisas << "\n";
            }
            reader >> i;
            temp << i << "\n";
        }
    }*/
    if(pessoas.size() > -1){
        for(i = 0; i < pessoas.size(); i++){
            write << "1" << endl;
            write << pessoas[i].name << endl;
            write << pessoas[i].nameMae << endl;
            write << pessoas[i].cpf << endl;
            write << pessoas[i].endereco << endl;
            write << pessoas[i].telefone << endl;
        }
    }
    if(empresas.size() > 0){
        for(i = 0; i < empresas.size(); i++){
            write << "2" << endl;
            write << empresas[i].razaoSocial << endl;
            write << empresas[i].cnpj << endl;
            write << empresas[i].endereco << endl;
            write << empresas[i].telefone << endl;
            write << empresas[i].capitalSocial << endl;
        }
    }
    write.close();
}
//Tá funfando?
void addPF(vector<personPF> &pessoas){
    personPF individuo;
    if(NCOUT) cout << "Insira o nome: ";
    getline(cin, individuo.name);
    if(NCOUT) cout << "Insira o nome da mae: ";
    getline(cin, individuo.nameMae);
    if(NCOUT) cout << "Insira o cpf: ";
    getline(cin, individuo.cpf);
    if(NCOUT) cout << "Insira o endereco: ";
    getline(cin, individuo.endereco);
    if(NCOUT) cout << "Insira o telefone: ";
    getline(cin, individuo.telefone);
    pessoas.push_back(individuo);
}

void addPJ(vector<personPJ> &empresas){
    personPJ empresa;
    if(NCOUT) cout << "Insira a Razao Social";
    getline(cin, empresa.razaoSocial);
    if(NCOUT) cout << "Insira o cnpj";
    getline(cin, empresa.cnpj);
    if(NCOUT) cout << "Insira o endereco";
    getline(cin, empresa.endereco);
    if(NCOUT) cout << "Insira o telefone";
    getline(cin, empresa.telefone);
    if(NCOUT) cout << "Insira o capital social";
    cin >> empresa.capitalSocial;
    empresas.push_back(empresa);
    cin.ignore();
}

void removePF(vector<personPF> &pessoas, int indice){
    pessoas.erase(pessoas.begin() + indice);
}

void removePJ(vector<personPJ> &empresas, int indice){
    empresas.erase(empresas.begin() + indice);
}

void names(const vector<personPF> &pessoas, const vector<personPJ> &empresas){
    int i;
    cout << "Names in Ascendind Order:" << endl;
    vector<string> nomes;
    for(i = 0; i<pessoas.size(); i++) nomes.push_back(pessoas[i].name);
    for(i = 0; i<empresas.size(); i++) nomes.push_back(empresas[i].razaoSocial);
    stable_sort(nomes.begin(), nomes.end());
    for(vector<string>::iterator it=nomes.begin(); it!=nomes.end(); ++it) cout << *it << endl;
}