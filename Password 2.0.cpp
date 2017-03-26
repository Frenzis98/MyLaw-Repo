#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
///////////////////////////////////////////
void Password(int &flag)
{
    int sforzo=0;
    flag = 1;
    string codice, psw = "bocciato"; //Password
    cout << "######################\n"
         << "## Password in C++  ##\n"
         << "## By Frenzis-MyLaw ##\n"
         << "##     Vers: 2.0    ##\n"
         << "######################\n";
    do
    {sforzo=sforzo+1;
      cout << "Inserisci la password : ";
      cin >> codice;
      if (codice == psw) break;
      cout << "Errori : " << sforzo << endl;
      if (sforzo==3)
      {
          flag = 0;
          cout << "Hai superato il massimo di errori. "<<sforzo<<endl;
          for (int i=0; i<100; i++)
          {
              cout << " ACCESSO NEGATO! ";
          }
          break;
      }
    }while (codice!=psw);
}
////////////////////////////////////////////
int Ceck (int &flag)
{
    if (flag == 0)
    {
        system("PAUSE");
        return flag;
    }
    flag = 1;
    cout << "\n\n\t\tcomplimenti !\n\n";
    system("PAUSE");
    return flag;
}
/////////////////////////////////////
int main()
{
    int flag=0;
    Password(flag);
    Ceck(flag);
    if (flag == 0) return 0;

    return 0;
}

