/*
Jimenez Romo Jose Antonio
Andrea Candelario
Angel Ramirez
Luis Humberto
BVV-UAA
*/

#include <iostream>
#include "CClient.h"
#include "CAcctions.h"

using namespace std;

void MainMenu();

int main() 
{
	int op;
    int n = 5;
    CClient reg[n];
    CAcctions actions;
	do
	{
        for(int i=0; i <= n; i++)
        {
            system("cls");
            cout << "---------> BVV-UAA [CAJERO] <---------" << endl;
            cout << "[1] --> Registrarse" << endl;
            cout << "[2] --> Cuenta ya existente" << endl;
            cout << "[3] --> Salir" << endl;
            cout << "Inserte la opcion deseada: ";
            cin >> op;
            
            switch(op)
            {
                case 1:
                {
                    cout << "Inserte un nombre para su nueva cuenta: " << endl;
                    char name[30];
                    fflush(stdin);
                    cin >> name;
                    reg[i].set_name(name);
                    reg[i].generate_ID();
                    actions.register_client(reg[i]);
                    break;
                }
                case 2:
                {
                    actions.print_actions();
                    cout << "Inserta tu ID: " << endl;
                    int id;
                    cin >> id;
                    if(actions.already_account(id) >= 0)
                    {
                        //actions.print_actions();
                        cout << "Sus datos son correctos? s / n" << endl;
                        char res;
                        fflush(stdin);
                        cin >> res;
                        if(res == 's' || res == 'S')
                        {
                            do
                            {
                                system("cls");
                                MainMenu();
                                int mainOp;
                                cin >> mainOp;

                                switch(mainOp)
                                {
                                    case 1:
                                    {
                                        cout << "Inserte el monto a depostiar: ";
                                        float deposit;
                                        cin >> deposit;
                                        actions.balance_account(deposit);
                                        break;
                                    }
                                    case 2:
                                    {
                                        cout << "Inserte el monto a retirar: ";
                                        float remove;
                                        cin >> remove;
                                        actions.remove_balance_account(remove);
                                        break;
                                    }
                                    case 3:
                                    {
                                        break;
                                    }
                                    case 4:
                                    {
                                        break;
                                    }
                                    case 5:
                                    {
                                        break;
                                    }
                                }
                                system("pause");
                            }while(op != 5);
                        }else
                        {
                            cout << "Documento .txt con posibles soluciones" << endl;
                        }
                    }else
                    {
                        cout << "ID no registrada!" << endl;
                    }
                    break;
                }
            }
            system("pause");
        }

	}while(op != 3);

	return 0;
}

void MainMenu()
{
    cout << "---------> BVV-UAA <---------" << endl;
	cout << "[1] --> Depositar Dinero a su cuenta" << endl;
	cout << "[2] --> Retirar Dinero de su cuenta" << endl;
	cout << "[3] --> Tranferir a otra cuenta" << endl;
    cout << "[4] --> Estado de cuenta" << endl;
    cout << "[5] --> Historiales" << endl;
	cout << "[6] --> Salir" << endl;
	cout << "Inserte la opcion deseada: ";
}

void menuHist()
{
    cout << "---------> HISTORIALES <---------" << endl;
	cout << "[1] --> Historial de depositos" << endl;
	cout << "[2] --> Hisotrial de retiros" << endl;
	cout << "[3] --> Historial de transferencias" << endl;
	cout << "[4] --> Regresar" << endl;
	cout << "Inserte la opcion deseada: ";
}