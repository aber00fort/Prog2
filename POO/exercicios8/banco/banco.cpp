#include "func.hpp"

int main(){
    char answer;
    string name;
    vector <Cliente> pf;
    bool sair = false, opt = false;
    int aux = 0, i;
    while(!opt){
        if(pf.size() == 0){
            cout << "PRIMEIRO CLIENTE" << endl;
            cout << "Insira seu nome: ";
            cin >> name;
            Cliente pessoa(name);
            pf.push_back(pessoa);
            i = 0;
        }
        else{
            int help = i;
            cout << "Insira seu nome: ";
            cin >> name;
            cout << "NOME" << endl;
            for(int j=0; j<pf.size(); j++){
                if(pf.at(j).getNome() == name){
                    i = j;
                    break;
                }
            }
            cout << "ID" << endl;
            if(i == help){
                cout << "NOVO CLIENTE" << endl;
                Cliente pessoa(name);
                pf.push_back(pessoa);
                i++;
            }
        }
        while(aux<10){
            system("clear");
            cout << "Seja bem-vinde ao menu do usuario, " << pf.at(i).toString() << endl;
            cout << "Escolha o que deseja fazer a seguir" << endl;
            cout << "1 - Criar um Conta Corrente" << endl;
            cout << "2 - Criar um Conta Especial" << endl;
            cout << "3 - Sacar da Conta Corrente" << endl;
            cout << "4 - Sacar da Conta Especial" << endl;
            cout << "5 - Depositar na Conta Corrente" << endl;
            cout << "6 - Depositar na Conta Especial" << endl;
            cout << "7 - Transferir para Conta Corrente" << endl;
            cout << "8 - Transferir para Conta Especial" << endl;
            cout << "9 - Verificar contas abertas" << endl;
            cout << "10 - Sair do Sistema" << endl;
            cin >> aux;
            system("clear");
            cout << aux << endl;
            switch (aux){
                case 1:{
                    ContaCorrente conta(10);
                    if(pf.at(i).salvarCC(conta)) cout << "Conta Corrente criada com sucesso" << endl;
                    else cout << "Erro desconhecido ao criar a conta corrente" << endl;
                    system("sleep 1");
                    break;
                }
                case 2:{
                    ContaEspecial conta(10,20);
                    if(pf.at(i).salvarCE(conta)) cout << "Conta Especial criada com sucesso" << endl;
                    else cout << "Erro desconhecido ao criar a conta especial" << endl;
                    system("sleep 1");
                    break;
                }
                case 3:{
                    cout << "De qual conta deseja sacar?" << endl;
                    pf.at(i).contas(1);
                    break;
                }
                case 4:{
                    cout << "De qual conta deseja sacar?" << endl;
                    pf.at(i).contas(3);
                    break;
                }
                case 5:{

                    break;
                }
                case 6:{

                    break;
                }
                case 7:{

                    break;
                }
                case 8:{

                    break;
                }
                case 9:{
                    pf.at(i).contas(2);
                    system("sleep 3");
                    break;
                }
                default:{sair = true;}
            }
            if(sair) break;
        }
        cout << "Deseja continuar(Y/N)?" << endl;
        cin >> answer;
        if(answer == 'Y'){
            sair = false;
            aux = 0;
        }
        else opt = true;
    }
    system("clear");
    cout << "Tenha um bom dia" << endl;
    return 0;
}