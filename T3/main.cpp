#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

bool mysort(const pair<int, int> &p1, const pair<int, int> &p2){
    return (p1.second > p2.second);
}

int main(){
    ifstream mensagem("interceptada.txt");
    string texto;
    char letra;
    while(mensagem.get(letra)) texto.push_back(letra);
    vector<pair<int, int> >frequencia;
    for(int i =0; i< 256; i++){
        pair<int, int> p;
        p.first = i;
        p.second = 0;
        frequencia.push_back(p);
    }
    for(int i=0; i<texto.size(); i++){
        char ch = texto.at(i);
        frequencia.at(ch).second++; 
    }
    stable_sort(frequencia.begin(), frequencia.end(), mysort);
    for(int i=0; i<frequencia.size(); i++) if(frequencia.at(i).second == 0) frequencia.erase(frequencia.begin()+i, frequencia.end());
    vector<int> conversao = {32, 97, 101, 111, 105, 115, 114, 110, 116, 109, 100, 99, 108, 117, 103, 112, 44, 102, 104, 118, 46, 107, 113, 67, 122, 43, 65, 98, 10, 77};
    for(int i=0; i<frequencia.size(); i++) frequencia.at(i).second = conversao.at(i);
    for(int i=0; i<30; i++) cout << (char) frequencia.at(i).first << " -> " << (char) frequencia.at(i).second << endl;
    for(int j=0; j<texto.size(); j++){
        letra = texto.at(j);
        for(int i=0; i<30; i++) if(letra == frequencia.at(i).first) cout << (char) frequencia.at(i).second;
    }
}