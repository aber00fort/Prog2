#include "person.hpp"

int main(){
    vector<personPF> pessoas;
    vector<personPJ> empresas;
    loadDb("database.dat", pessoas, empresas);
    string opt;
    int indice;
    if(NCOUT) cout << "My Papa's Company - SIG" << endl;
    if(NCOUT) cout << "1 - Add PF" << endl;
    if(NCOUT) cout << "2 - Add PJ" << endl;
    if(NCOUT) cout << "3 - Remove PF Index" << endl;
    if(NCOUT) cout << "4 - Remove PJ Index" << endl;
    if(NCOUT) cout << "5 - Print Names in Ascendig Order" << endl;
    if(NCOUT) cout << "6 - Quit" << endl;
    while(true){
        saveDb("database.dat", pessoas, empresas);
        if(NCOUT) cout << "Enter an option: ";
        cin >> opt;
        cin.ignore();
        if(opt == "1"){
            addPF(pessoas);
            continue;
        }
        if(opt == "2"){
            addPJ(empresas);
            continue;
        }
        if(opt == "3"){
            if(NCOUT) cout << "Insira o indice";
            cin >> indice;
            cin.ignore();
            if(indice < 0 || indice > (pessoas.size() - 1)){
                cout << "Index could not be removed" << endl;
                continue;
            }
            removePF(pessoas, indice);
            continue;
        }
        if(opt == "4"){
             if(NCOUT) cout << "Insira o indice";
            cin >> indice;
            cin.ignore();
            if(indice < 0 || indice > (empresas.size() - 1)){
                cout << "Index could not be removed" << endl;
                continue;
            }
            removePJ(empresas, indice);
            continue;
        }
        if(opt == "5"){
            names(pessoas, empresas);
            continue;
        }
        if(opt == "6") break;
        else continue;
    }
}