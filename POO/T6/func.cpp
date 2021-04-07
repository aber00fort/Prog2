#include "func.hpp"
#include <fstream>
#include <string>

void saveDB(vector<Games> &games, vector<Accessories> &accessories){
    ofstream arquivo("db.txt");
    if(arquivo.is_open()){
        for(int i = 0; i < games.size(); i++){
            arquivo << games.at(i).getType() << endl;
            arquivo << games.at(i).getName() << endl;
            arquivo << games.at(i).getAmount() << endl;
            arquivo << games.at(i).getPrice() << endl;
            arquivo << games.at(i).getAge() << endl;
        }
        for(int i = 0; i < games.size(); i++){
            arquivo << accessories.at(i).getType() << endl;
            arquivo << accessories.at(i).getName() << endl;
            arquivo << accessories.at(i).getAmount() << endl;
            arquivo << accessories.at(i).getPrice() << endl;
            arquivo << accessories.at(i).getConsole() << endl;
        }
    }
    arquivo.close();
}

bool loadDB(vector<Games> &games, vector<Accessories> &accessories){
    ifstream filereader("db.txt");
    if(!filereader.is_open()){
        cout << "Could not find a database; creating a new one" << endl;
        ofstream novo;
        novo.open("db.txt");
        novo.close();
        return true;
    }
    string tmp;
    while(filereader >> tmp){
        cout << tmp << endl;
        if(tmp == "game"){
            Games game;
            game.setType("game");
            getline(filereader, tmp);
            game.setName(tmp);
            cout << tmp << endl;
            int aux = stoi(tmp);
            game.setAmount(aux);
            getline(filereader, tmp);
            float price = stof(tmp);
            game.setPrice(price);
            getline(filereader, tmp);
            age = stoi(tmp);
            game.setAge(age);
            //filereader >> qtd;
            //filereader >> price;
            //filereader >> age;
            //Games game(age, price, qtd, name, "game");
            cout << game.getName() << " " << game.getAmount() << " " << game.getPrice() << " " << game.getAge() << endl;
            games.push_back(game);
        }
        else if(tmp == "accessories"){
            getline(filereader, tmp);
            string name = tmp;
            getline(filereader, tmp);
            int qtd = stoi(tmp.c_str());
            getline(filereader, tmp);
            float price = stof(tmp.c_str());
            getline(filereader, tmp);
            string console = tmp;
            Accessories accessory(price, qtd, "accessory", console, name);
            accessories.push_back(accessory);
        }
    }
    cout << games.at(0).toString() << endl;
    filereader.close();
    return true;
}

void print(vector<Games> &games, vector<Accessories> &accessories){
    cout << "-------------------- List of Games --------------------" << endl;
    cout << "Name" << "\t" << "Minimum Age" << "\t" << "In Stock" << "\t" << "Price" << endl;
    for(int i = 0; i<games.size(); i++) games.at(i) + (0);
    cout << "----------------- List of Accessories -----------------" << endl;
    cout << "Name" << "\t" << "Console" << "\t" << "In Stock" << "\t" << "Price" << endl; 
    for(int i = 0; i<accessories.size(); i++) accessories.at(i) + (0);
}

void changePrice(vector<Games> &games, vector<Accessories> &accessories){
    cout << "Is it a game[G] or an accessory[A]?: ";
    char ans;
    cin >> ans;
    cout << endl;
    if(ans == 'G'||ans == 'g'){
        if(games.size() == 0){
            cout << "It seems you have no game registered yet" << endl;
            system("sleep 1");
            return;
        }
        cout << "-------------------- List of Games --------------------" << endl;
        cout << "ID" << "\t" << "Name" << "\t" << "Minimum Age" << "\t" << "In Stock" << "\t" << "Price" << endl;
        for(int i=0; i<games.size(); i++){
            cout << i+1 << "\t";
            games.at(i) + (0);
        }
        cout << "Please select the desired game's ID:";
        int id;
        cin >> id;
        cout << endl;
        cout << "Please input the new price: ";
        float price;
        cin >> price;
        games.at(id-1) - (price);
        system("clear");
        cout << "Info updated" << endl;
        games.at(id-1) - (0);
    }
    else if(ans == 'A'||ans == 'a'){
        if(accessories.size() == 0){
            cout << "It seems you have no game registered yet" << endl;
            system("sleep 1");
            return;
        }
        cout << "----------------- List of Accessories -----------------" << endl;
        cout << "ID" << "\t" << "Name" << "\t" << "Console" << "\t" << "In Stock" << "\t" << "Price" << endl; 
        for(int i = 0; i<accessories.size(); i++){
            cout << i+1 << "\t";
            accessories.at(i) + (0);
        }
        cout << "Please select the desired accessory's ID:";
        int id;
        cin >> id;
        cout << endl;
        cout << "Please input the new price: ";
        float price;
        cin >> price;
        accessories.at(id-1) - (price);
        system("clear");
        cout << "Info updated" << endl;
        accessories.at(id-1) + (0);
    }
}

void changeAmount(vector<Games> &games, vector<Accessories> &accessories){
    cout << "Is it a game[G] or an accessory[A]?: ";
    char ans;
    cin >> ans;
    cout << endl;
    if(ans == 'G'||ans == 'g'){
        if(games.size() == 0){
            cout << "It seems you have no game registered yet" << endl;
            system("sleep 1");
            return;
        }
        cout << "-------------------- List of Games --------------------" << endl;
        cout << "ID" << "\t" << "Name" << "\t" << "Minimum Age" << "\t" << "In Stock" << "\t" << "Price" << endl;
        for(int i=0; i<games.size(); i++){
            cout << i+1 << "\t";
            games.at(i) + (0);
        }
        cout << "Please select the desired game's ID:";
        int id, amount;
        cin >> id;
        cout << endl;
        cout << "Please input the new amount: ";
        cin >> amount;
        games.at(id-1) * (amount);
        system("clear");
        cout << "Info updated" << endl;
        games.at(id-1) + (0);
    }
    else if(ans == 'A'||ans == 'a'){
        if(accessories.size() == 0){
            cout << "It seems you have no game registered yet" << endl;
            system("sleep 1");
            return;
        }
        cout << "----------------- List of Accessories -----------------" << endl;
        cout << "ID" << "\t" << "Name" << "\t" << "Console" << "\t" << "In Stock" << "\t" << "Price" << endl; 
        for(int i = 0; i<accessories.size(); i++){
            cout << i+1 << "\t";
            accessories.at(i) + (0);
        }
        cout << "Please select the desired accessory's ID:";
        int id, amount;
        cin >> id;
        cout << endl;
        cout << "Please input the new amount: ";
        cin >> amount;
        accessories.at(id-1) * (amount);
        system("clear");
        cout << "Info updated" << endl;
        accessories.at(id-1) + (0);
    }
}

void addItem(vector<Games> &games, vector<Accessories> &accessories){
    char tmp;
    cout << "Is it a Game [G] or an Accessory[A]? "; 
    cin >> tmp;
    if(tmp == 'G'){
        int top = games.size();
        string name, aux;
        int amount, age;
        float price;
        cout << "What's the game's name? ";
        cin.ignore();
        getline(cin, name);
        cout << "How many are there? ";
        cin >> amount;
        //amount = stoi(aux);
        cout << "How much does it cost? ";
        cin >> price;
        //price = stof(aux);
        cout << "What's the recommended age? ";
        cin >> age;
        //age = stoi(aux);
        Games newGame(age, price, amount, name);
        games.push_back(newGame);
        system("clear");
        if(top<games.size()){
            cout << "Game successfully stoked" << endl;
            newGame+(0);
        }
    }
    else cout << "wait till later" << endl;
    cout << games.size();
}

void stockMenu(vector<Games> &games, vector<Accessories> &accessories){
    int aux = 0;
    while(aux<5){
        system("clear");
        cout << "What you need today?" << endl;
        cout << "1 - Change the amount of an item" << endl;
        cout << "2 - Change the price of an item" << endl;
        cout << "3 - Add an item" << endl;
        cout << "4 - Delete an item" << endl;
        cout << "5 - Return to the previous menu" << endl;
        cin >> aux;
        system("clear");
        switch (aux){
            case 1:{
                changeAmount(games, accessories);
                system("sleep 2");
                break;
            }
            case 2:{
                changePrice(games, accessories);
                system("sleep 2");
                break;
            }
            case 3:{
                addItem(games, accessories);
                system("sleep 1");
                break;
            }
            case 4:{
                cout << "Not done yet. Stay tuned" << endl;
                system("sleep 1");
                break;
            }
            default:{
                aux = 5;
                break;
            }
        }
    }
    system("clear");
}
