#include "func.cpp"

using namespace std;

#define NCOUT  0

int main(){
    string opt;
    string path = "";
    string palavra;
    vector<string> paths;
    vector<vector<string> > lista;
    if(NCOUT) cout << "DICTIONARY MANIPULATION HACK" << endl;
    if(NCOUT) cout << "Select an option " << endl;
    if(NCOUT) cout << "1 - Open Dictionary" << endl;
    if(NCOUT) cout << "2 - Search Substring" << endl;
    if(NCOUT) cout << "3 - Remove Words Containing Substring" << endl;
    if(NCOUT) cout << "4 - Show Statistics " << endl;
    if(NCOUT) cout << "5 - Exit" << endl;
    while(true){        
        if(NCOUT) cout << "Option: ";
        cin >> opt;
        if(NCOUT) cout << endl;
        if(opt == "1"){
            if(NCOUT) cout << "Enter a dictionary file: " << endl;
            cin >> path;
            estru aux = loadDic(path, paths, lista);
            lista = aux.lista;
            paths = aux.paths;
            continue;
        }
        else if(opt == "2"){
            if(NCOUT) cout << "Insira a palavra a ser pesquisada" << endl;
            string procura;
            cin >> procura;
            for(int i = 0; i < lista.size(); i++) if(paths[i] != "") procurar(lista[i], procura);
            continue;
        }
        else if(opt == "3"){
            if(NCOUT) cout << "Insira a palavra a ser deletada" << endl;
            string deleta;
            cin >> deleta;
            for(int i = 0; i < paths.size(); i++){
                lista[i] = deletar(paths[i], lista[i], deleta);
            }
            continue;
        }
        else if(opt == "4"){
            cout << "Statistics:" << endl;
            for(int i = 0; i < lista.size(); i++) cout << paths[i] << " -> " << lista[i].size() << " words" << endl;
            continue;
        }
        else if(opt == "5") break;
        else continue;
    }
    return 0;
}