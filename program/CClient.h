#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

class CClient
{
  public:
    char name[30];
    int ID;
  public:
    CClient(); // Buldier
    CClient(char *, int); // Copy Buldier
    //~CClient(); // Destroyer
    void set_name(char * n)
    {
      strcpy(name,n); 
    }
    char * get_name()
    {
      return name;
    }
    void generate_ID();
    void print_client()
    {
        cout << "Usuario: " << name << endl;
        cout << "ID: " << ID << endl;
    }
};

CClient :: CClient()
{
    strcpy(name,"Name");
    ID = 0;
}


CClient :: CClient(char *n, int idd)
{
    strcpy(name,n);
    ID = idd;
}

void CClient :: generate_ID()
{
    //srand(time(0));
    ID = 1000 + rand() % (9999);
    cout << "Su ID generada es: " << ID << endl;
}