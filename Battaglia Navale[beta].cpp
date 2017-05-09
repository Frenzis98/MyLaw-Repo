#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;
///////////////////// CAMPO //////////////////
#define N 10
short int campo [N] [N] {{0},{0}};
short int navi [5];
short int miocampo [N] [N] {{0},{0}};
short int mienavi [5];
///////////////////// RESET CAMPO ////////////////////////////
void Reset (void)
{
    for (int x=0; x<N; x++) // un caricamento di 0 'reset'
    {
        for (int y=0; y<10; y++)
        {
            campo [x] [y] =0;
        }
    }
    for (int i=0; i<6; i++)
    {
        navi[i]=0;
    }
    cout << "Reset Completato" << endl;
    system("PAUSE");
}
/*
Punto casuale x-y
controlla se ha colpito
FALSO Ritorna su genera x-y
VERO
    VERO
*/
////////////////////////// VERSO DESTRA ////////////////////////
void DirezioneRight(int num)
{
    int x, y, ck,tempY=0;
    do
    {
        ck =0;
        x = rand() %10;
        y = rand() %10;
        for (int k=0; k<num; k++)
        {
            tempY = y;
            if ((tempY+num)<10)
            {
                if (campo [x][tempY]!=0)
                {
                    ck-=10;
                    cout << "Destra -=10 " << ck << endl;
                    break;
                }
                else
                {
                    ck+=1;
                    tempY+=1;
                    cout << ck << " of " << num <<endl;
                }
            }
            else ck-=10;
        }
    }
    while(ck!=num);
    int val = num + y;
    cout << "Ship of " << num <<endl;
    for (int i=y; i<val; i++)
    {
        campo[x][i]=num;
        cout << "LogRight: PosX= "<< x <<" PosY= " << i << endl;
    }
    cout << "Posizionata! Right"<<endl;
}
/////////////////////// VERSO SINISTRA //////////////////////////
void DirezioneLeft(int num)
{
    int x, y, ck,tempY=0;;
    do
    {
        ck =0;
        x = rand() %10;
        y = rand() %10;
        for (int k=0; k<num; k++)
        {
            tempY = y;
            if ((tempY-num)>=0)
            {
                if (campo [x][tempY]!=0)
                {
                    ck-=10;
                    cout << "Sinistra -=10 " << ck << endl;
                    break;
                }
                else
                {
                    ck+=1;
                    tempY-=1;
                    cout << ck << " of " << num <<endl;
                }

            }
            else ck-=10;
        }
    }
    while(ck!=num);
    int val = (y - num)*+1;
    cout << "Ship of " << num <<endl;
    for (int i=y; i>val; i--)
    {
        campo[x][i]=num;
        cout << "LogLeft: PosX= "<< x <<" PosY= " << i << endl;
    }
    cout << "Posizionata! Left"<<endl;
}
///////////////////// VERSO GIU ////////////////////////////
void DirezioneDown(int num)
{
    int x, y, ck,tempX=0;
    do
    {
        ck =0;
        x = rand() %10;
        y = rand() %10;
        for (int k=0; k<num; k++)
        {
            tempX = x;
            if ((tempX+num)<10)
            {
                if (campo [tempX][y]!=0)
                {
                    ck-=10;
                    cout << "Giu -=10 " << ck << endl;
                    break;
                }
                else
                {
                    ck+=1;
                    tempX+=1; // va avanti nella matrice
                    cout << ck << " of " << num <<endl;
                }
            }
            else ck-=10;
        }
    }
    while(ck!=num);
    int val = num + x;
    cout << "Ship of " << num <<endl;
    for (int i=x; i<val; i++)
    {
        campo[i][y]=num;
        cout << "LogDown: PosX= "<< i <<" PosY= " << x << endl;
    }
    cout << "Posizionata! Down"<<endl;
}
/////////////////////// VERSO SU //////////////////////////// --Spiegazione
void DirezioneUp(int num) // 'num' numero della nave
{
    int x, y, ck,tempX=0;
    do
    {
        ck =0; //resetta il check
        x = rand() %10; //genera un punto di parteza
        y = rand() %10;
        for (int k=0; k<num; k++)
        {
            tempX = x;// Fa una copia
            if ((tempX-num)>=0) //controlla se e libero '0'
            {
                if (campo [tempX][y]!=0)
                {
                    ck-=10;
                    cout << "Su -=10 " << ck << endl;
                    break;
                }
                else
                {
                    ck+=1; //Aggiunge +1 per il check finale
                    tempX-=1; //Va indietro nella matrice.
                    cout << ck << " of " << num <<endl;
                }
            }
            else ck-=10;
        }
    }
    while(ck!=num);
    int val = (x - num)*+1; //una condizione per il ciclo for
    cout << "Ship of " << num <<endl;
    for (int i=x; i>val; i--) //Salva il valore nella matrice
    {
        campo[i][y]=num;
        cout << "LogUp: PosX= "<< i <<" PosY= " << y << endl;
    }
    cout << "Posizionata! UP"<<endl;
}
//////////////////////// ARRAY LOAD NAVI ////////////////////////////
void NumeroNavi (void)
{
    for (int i=0; i<4; i++) //un semplice caricamento di un array
    {
        cout << "How many ships do " << (i+1) << " : ";
        cin >> navi[i];
        //navi[i]=mienavi[i];
    }
    cout << "Loaded..."<<endl;
    system("PAUSE");
}
//////////////////// SMISTATORE DIREZIONALE ///////////////////////
void DirezioneNavi(void) //(i+1) diventa la variabile "num"
{
    for (int i=3; i>=0; i--)
    {
        for (int j=0; j<navi[i]; j++)
        {
            int direzione = rand()%4;
            if (direzione == 0)
            {
                cout << "Down" << endl;
                DirezioneDown(i+1); //verso giu
            }
            else if (direzione == 1)
            {
                cout << "UP" << endl;
                DirezioneUp(i+1);  //Verso su
            }
            else if (direzione == 2)
            {
                cout << "Left" << endl;
                DirezioneLeft(i+1); //Verso sinistra
            }
            else if (direzione ==3)
            {
                cout << "Right" << endl;
                DirezioneRight(i+1); //Verso destra
            }
        }
    }
    cout << "Smistati" << endl;
    system("PAUSE");
}
///////////////// GRAFICA CAMPO ///////////////////////
void Stampa(void)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            cout<<" | "<<campo[i][j];
        }
        cout<<endl;
    }
    system("PAUSE");
}
/////////////////// HUMAN //////////////////
void HumanShips(void)
{
    for (int i=3; i=0; i--)
    {
        //Label
        if(mienavi[i]!=0)
        {
            cout << "Posizione nave da : " << (i+1) << endl
                 << "Inserisci riga ";
        }
    }
}
//////////////// NON TOCCARE /////////////////
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
    {
        sforzo=sforzo+1;
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
    }
    while (codice!=psw);
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
   // Password(flag);
    //Ceck(flag);
   // if (flag == 0) return 0;
    do
    {
        system("cls");
        indietro = false;
/////////////////////// MENU //////////////////////////
        cout << "Battaglia Navale || Vers: 1.5 ||" << endl
             << "1. Reset" << endl
             << "2. Number Ship CPU DESK" << endl
             << "3. Auto Place CPU DESK" << endl
             << "4. Manual Place HUMAN DESK" << endl
             << "5. Label CPU (Cheat)" << endl
             << "Select Option : ";
        cin >> sel;
//////////////////////// SWITCH /////////////////////
        switch (sel)
        {
        case (1) :
            Reset();
            indietro = true;
            break;
        case (2) :
            NumeroNavi();
            indietro = true;
            break;
        case (3) :
            DirezioneNavi();
            indietro = true;
            break;
        case (4) :
            HumanShips();
            indietro = true;
            break;
        case (5) :
            Stampa();
            indietro = true;
            break;
        default :
            cout << "Error(Funzione non trovata)"<<endl;
            indietro = true;
            system("PAUSE");
            break;
        }
    }
    while(indietro == true);
    return 0;
}
