#ifndef FUNC_HPP
#define FUNC_HPP
#include <iostream>
#include <vector>
#include "classes.hpp"

using namespace std;

bool loadDB(vector<Games> &games, vector<Accessories> &accessories);
void saveDB(vector<Games> &games, vector<Accessories> &accessories);
void stockMenu(vector<Games> &games, vector<Accessories> &accessories);
void print(vector<Games> &games, vector<Accessories> &accessories);

#endif//FUNC_HPP