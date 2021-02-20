#include "func.hpp"
#include <fstream>

estru loadDic(string path, vector<string> paths, vector<vector<string> > lista{
    ifstream filereader;
    filereader.open(path);
    if(filereader.is_open()){
        vector<string> palavras;
        string palavra;
        paths.push_back(path);
        filereader >> palavra;
        while(filereader >> palavra) palavras.push_back(palavra);
        lista.push_back(palavras);
    }
    filereader.close(); 
    estru retorno;
    retorno.lista = lista;
    retorno.paths = paths;
    return retorno;
}

vector<string> deletar(string path, vector<string> palavras, string deleta){
    ifstream filereader(path);
    string palavra;
    int cont(0);
    ofstream temp;
    char tempc[9] = "temp.txt";
    temp.open(tempc);
    vector<int> indice;
    while(filereader >> palavra){
        if(palavra.find(deleta) != -1){
            indice.push_back(cont-1);
            cont++;
            continue;
        }
        cont++;
        temp << palavra << "\n";
    }
    temp.close();
    filereader.close();
    int aux(0);
    vector<string> newPalavras;
    for(int i = 0; i < palavras.size(); i++){
        if(i == indice[aux]) aux++;
        else newPalavras.push_back(palavras[i]);
    }
    indice.clear();
    remove(path.c_str());
    rename(tempc, path.c_str());
    return newPalavras;
}

void procurar(vector<string> palavras, string procura){
    for(int i = 0; i < palavras.size(); i++){
        if(palavras[i].find(procura) != -1){
            cout << palavras[i];
            cout << endl;
        }
    }
}