#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

class CAcctions : public CClient
{
    private:
        CClient *actions;
        int index;
        int n;
        float client_balance;
        int interst;
    public:
        CAcctions();
        bool register_client(CClient);
        int already_account(int);
        void balance_account(float);
        void remove_balance_account(float);
        void account_stauts();
        void print_actions()
        {
            for(int i =0; i <= index; i++)
            {
                cout << "Usuario: " << actions[i].name << endl;
                cout << "ID: " << actions[i].ID << endl;
            }
        }
};

CAcctions :: CAcctions()
{
    n = 5;
    actions = new CClient[n];
    index = 0;
    client_balance = 0.0;
}

void CAcctions :: balance_account(float deposit)
{
    client_balance += deposit;
    cout << "Se a depositado: " << deposit << " a su cuenta " << endl;
}

void CAcctions :: remove_balance_account(float remove)
{
    interst = remove;
    client_balance -= interst;
    cout << "Se a retirado: " << remove << " de su cuenta" << endl;
}

bool CAcctions :: register_client(CClient client)
{
    actions[index] = client;
    index ++;
    return true;
}

int CAcctions :: already_account(int idd)
{
    //cout << idd << endl;
    //cout << ID[0] << endl;
    int aux = 0;
    for(int i=0; i < index; i++)
    {
        if(idd == actions[i].ID)
        {
            cout << "----> Confirmacion de Datos <----" << endl;
            cout << "Usuario: " << actions[i].name << endl;
            cout << "ID: " << actions[i].ID << endl;
            aux = 1;
        }
    }
    if(aux == 1)
    {
        return 0;
    }else
    {
        return -1;
    }
} 