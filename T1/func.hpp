#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct estru{
    vector<vector<string> > lista;
    vector<string> paths;
};

estru loadDic(string path, vector<string> paths, vector<vector<string> > lista);
vector<string> deletar(string path, vector<string> palavras, string deleta);
void procurar(vector<string> palavras, string procura);