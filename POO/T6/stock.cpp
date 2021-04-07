#include "func.hpp"
#include <fstream>
#include <vector>
#include <string>


int main(){
    vector<Games> games;
    vector<Accessories> accessories;
    //pair< vector<Games>, vector<Accessories> > auxiliar;
    loadDB(games, accessories);
    //auxiliar = loadVec();
    //games = auxiliar.first;
    int opt = 0;
    while(opt<3){
        system("clear");
        cout << "Welcome to Baubles's Stock" << endl;
        cout << "Please, select one of the following options" << endl;
        cout << "1 - View Stock" << endl;
        cout << "2 - Update Stock" << endl;
        cout << "3 - Close System" << endl;
        cin >> opt;
        system("clear");
        switch(opt){
            case 1:{
                print(games, accessories);
                system("sleep 5");
                break;
            }
            case 2:{
                stockMenu(games, accessories);
                break;
            }
            default:{
                opt = 3;
                break;
            }
        }
    }
    cout << "See you around" << endl;
    return 0;
}