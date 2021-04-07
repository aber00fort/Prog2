#include "func.hpp"
#include <fstream>
#include <vector>
#include <string>

int main(){
    vector<Games> games;
    vector<Accessories> accessories;
    pair< vector<Games>, vector<Accessories> > auxiliar;
    auxiliar = loadVec();
    games = auxiliar.first;
    accessories = auxiliar.second;
    int opt = 0;
    while(opt<3){
        system("clear");
        cout << "Welcome to Baubles's Stock" << endl;
        cout << "" << endl;
    }
    return 0;
}