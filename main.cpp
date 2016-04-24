#include "head.h"
#include "klista.h"
#include "szelveny.h"
#include "Lista.h"

void    kiir(int *p, int n)
{
    for (int i = 1; i <= n ; i++)
    {
        if (p[i - 1] <= 10)
            cout << " ";
        cout << p[i - 1] << " ";
        if (i % 10 == 0)
            cout << endl;
    }
    cout << endl;
}



void    print(char a, int n)
{   
    for (int i = 0; i < n; i++)
        cout << a;
}

void    kiir_bingo()
{
    print('*', 31);
    cout << endl << "*";
    print(' ', 12);
    cout << "BINGO";
    print(' ', 12);
    cout << "*" << endl;
    print('*', 31);
    cout << "\n";
}


void    jatek_indit(int szam, Lista *fogado)
{
    int     rn = 2 + (rand() % 5);
    int     *tab;
    klista a(szam);

    tab = new int[szam * 3 / 4];
    for (int k = 0; k < szam * 3 / 4;)
        {
            if (!rn--)
            {
                rn = 10 + (rand() % 20);
                tab[k++] = a.get();
                a.torol();
                cout << "Kihuzott szam: "<< tab[k - 1] << endl;
                system("sleep 0.7");
            }
            system("clear");
            kiir_bingo();
            cout << endl << endl;
            cout << "Maradando szamok:";
            cout << endl;
            a.f_kiir(10);
            cout << "\nKihuzott szamok:";
            cout << endl;
            kiir(tab, k);
            cout << endl << endl;
            a.lep();
            system("sleep 0.1");
        }
    cout << "\nJatek vege\n";
    fogado->kiir_gy(tab, szam * 3 /4);
}

void    megrak_szel(Lista *fogadok, int szam)
{
    fogadok->megrak(szam);
}

int     main()
{
    srand(time(NULL));
    int     szam = 49; 
    int     valasz = 0;
    bool    meg = true;
    Lista   *fogadok;
    
    fogadok = new Lista;
    while (meg)
    {
        system("clear");
        kiir_bingo();
        cout << "1.Szelveny megrakasa\n";
        cout << "2.Jatek inditasa\n";
        cout << "3.Maximalis intervallum\n";
        cout << "4.Szelvenyek megvizsgalasa\n";
        cout << "5.Kilepes\n";

        cin >> valasz;
        switch (valasz)
        {
            case 1:
                system("clear");
                megrak_szel(fogadok, szam);
                break;
            case 2:
                jatek_indit(szam, fogadok);
                delete fogadok;
                fogadok = new Lista;
                cout << "Nyomd meg a SPACE+ENTER-t hogy lepj tovabb";
                while (cin.get() == '\n');
                break;
            case 3:
                system("clear");
                cout << "Hany szammal szeretne jatszani?\n";
                cin >> szam;
                while (szam > FELSO_KORLAT || szam < ALSO_KORLAT)
                {
                    system("clear");
                    cout << "A szam " << ALSO_KORLAT << " es " << FELSO_KORLAT << " kozott kell legyen\n";
                    cout << "Hany szammal szeretne jatszani?\n";
                    cin >> szam;
                }
                break;
            case 4:
                system("clear");
                cout << "Szelvenyek:\n";
                fogadok->kiir();
                cout << "Nyomd meg a SPACE+ENTER-t hogy lepj tovabb";
                while (cin.get() != ' ');
                break;
            case 5:
                meg = false;
                break;
            default :
                cout << "!!!Nem letezik ilyen opcio!!!\n";
                break;
        }
    }
    system("clear");
    cout << "Koszonjuk szepen, hogy jatszott :)\n";
    return (0);
}
