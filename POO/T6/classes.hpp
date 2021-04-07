#ifndef CLASSES_HPP
#define CLASSES_HPP
#include <iostream>

using namespace std;


class Items{
    protected:
        float i_price;
        int i_amount;
        string i_type;
        string i_name;
    public:
        Items(){i_price = 0; i_amount = 0; i_type = "";};
        Items(float value, int qtd, string name){i_price = value; i_amount = qtd; i_type = name;};

        void setPrice(float value){i_price = value;};
        void setAmount(int qtd){i_amount = qtd;};
        void setType(string type){i_type = type;};
        void setName(string name){i_name = name;};

        float getPrice(){return i_price;};
        int getAmount(){return i_amount;};
        string getType(){return i_type;};
        string getName(){return i_name;};

        void operator - (float price){setPrice(price);};
        void operator * (int amount){setAmount(amount);};

        ~Items(){};
};

class Games: public Items{
    private:
        int g_age;
    public:
        Games(){g_age = 0; i_price = 0; i_amount = 0; i_name = ""; i_type = "game";};
        Games(int age, float price, float amount, string name, string type = "game"){g_age = age; i_price = price; i_amount = amount; i_name = name; i_type = type;};
        void setAge(int age){g_age = age;};
        int getAge(){return g_age;};
        string toString();

        string operator + (int opt){return toString();};

        ~Games(){};
};

class Accessories: public Items{
    private:
        string a_console;
    public:
        Accessories(){i_price = 0; i_amount = 0; i_type = "accessory"; a_console = "";};
        Accessories(int price, float amount, string console, string name, string type = "accessory"){i_price = price; i_amount = amount; i_type = type; a_console = console; i_name = name;};
        void setConsole(string console){a_console = console;};
        string getConsole(){return a_console;};
        string toString();

        void operator + (int opt){toString();}

        ~Accessories(){};
};


#endif//CLASSES_HPP