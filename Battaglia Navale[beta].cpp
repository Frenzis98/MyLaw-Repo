#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;
/////// CAMPO ////////
#define N 10
short int campo [N] [N] {{0},{0}};
short int navi [5];

void Reset (void)
{
    for (int x=0; x<10; x++)
    {
        for (int y=0;y<10;y++)
        {
            campo [x] [y] =0;
        }
    }
    cout << "Reset Completato" << endl;
    system("PAUSE");
}
void DirezioneRight(int num)
{
    int x, y, ck;
    do
    {
        ck =0;
        x = rand() %10;
        y = rand() %10;
        for (int k=0;k<num;k++)
        {
            int tempY = y;
            if ((tempY+num)<10 && campo [x][tempY]==0)
                {
                    ck+=1;
                    tempY+=1;
                }
        }
    }while(ck!=num);
    int val = num + y;
    for (int i=y;i<val;i++)
        {
            campo[x][i]=num;
            cout << "LogRight: PosX= "<< x <<" PosY= " << i << endl;
        }
        cout << "Posizionata! Right"<<endl;
}
void DirezioneLeft(int num)
{
    int x, y, ck;
    do
    {
        ck =0;
        x = rand() %10;
        y = rand() %10;
        for (int k=0;k<num;k++)
        {
            int tempY = y;
            if ((tempY-num)>-1 && campo [x][tempY]==0)
                {
                    ck+=1;
                    tempY-=1;
                }
        }
    }while(ck!=num);
    int val = y - num;
    for (int i=y;i>val;i--)
        {
            campo[x][i]=num;
            cout << "LogLeft: PosX= "<< x <<" PosY= " << i << endl;
        }
        cout << "Posizionata! Left"<<endl;
}
void DirezioneDown(int num)
{
    int x, y, ck;
    do
    {
        ck =0;
        x = rand() %10;
        y = rand() %10;
        for (int k=0;k<num;k++)
        {
            int tempX = x;
            if ((tempX+num)<10 && campo [tempX][y]==0)
                {
                    ck+=1;
                    tempX+=1;
                }
        }
    }while(ck!=num);
    int val = num + x;
    for (int i=x;i<val;i++)
        {
            campo[i][y]=num;
            cout << "LogDown: PosX= "<< i <<" PosY= " << x << endl;
        }
        cout << "Posizionata! Right"<<endl;
}
void DirezioneUp(int num)
{
    int x, y, ck;
    do
    {
        ck =0;
        x = rand() %10;
        y = rand() %10;
        for (int k=0;k<num;k++)
        {
            int tempX = x;
            if ((tempX-num)>-1 && campo [tempX][y]==0)
                {
                    ck+=1;
                    tempX-=1;
                }
        }
    }while(ck!=num);
    int val = x - num;
    for (int i=x;i>val;i--)
        {
            campo[i][y]=num;
            cout << "LogUp: PosX= "<< i <<" PosY= " << y << endl;
        }
        cout << "Posizionata! UP"<<endl;
}
/////////////////////////////////////////////////////////////
void NumeroNavi (void)
{
    for (int i=0;i<4;i++)
    {
        cout << "How many ships do " << (i+1) << " : ";
        cin >> navi[i];
    }
    cout << "Loaded..."<<endl;
    system("PAUSE");
}
void DirezioneNavi(void)
{
    for (int i=4;i>-1;i--)
    {
        for(int k=0;k<navi[i];k++)
        {
            int direzione = rand() % 4;
            if (direzione == 0)
            {
                DirezioneDown(i+1);
            }else if (direzione == 1)
            {
                DirezioneUp(i+1);
            }else if (direzione == 2)
            {
                DirezioneLeft(i+1);
            }else if (direzione ==3)
            {
                DirezioneRight(i+1);
            }
        }
    }cout << "Completato" << endl;
    system("PAUSE");
}
void Stampa(void)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<" | "<<campo[i][j];
        }
        cout<<endl;
    }
    system("PAUSE");
}
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
    srand(time(0));
    bool indietro = false;
    short int sel = 0;
    int flag=0;
    Password(flag);
    Ceck(flag);
    if (flag == 0) return 0;
    do{
    system("cls"); indietro = false;
///////// MENU ////////
    cout << "Battaglia Navale || Vers: 1.5 ||" << endl
         << "1. Reset" << endl
         << "2. Number Ship" << endl
         << "3. Auto Place" << endl
         << "4. Label" << endl
         << "Select Option : ";
    cin >> sel;
///////// SWITCH /////////
    switch (sel)
    {
        case (1) : Reset();indietro = true; break;
        case (2) : NumeroNavi(); indietro = true; break;
        case (3) : DirezioneNavi();indietro = true; break;
        case (4) : Stampa();indietro = true;break;
        default : cout << "Error(Funzione non trovata)"<<endl; indietro = true;system("PAUSE"); break;
    }
    }while(indietro == true);




    return 0;
}