#include "classes.hpp"
#include <sstream>

string Games::toString(){
    stringstream sst;
    sst << i_name << "\t" << g_age << "\t" << i_amount << "\t" << i_price << endl;
    return sst.str();
}

string Accessories::toString(){
    stringstream sst;
    sst << i_name << "\t" << a_console << "\t" << i_amount << "\t" << i_price << endl;
    return sst.str();
}