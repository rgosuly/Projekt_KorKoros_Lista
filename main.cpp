#include "head.h"

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
    print('*', 21);
    cout << endl << "*";
    print(' ', 7);
    cout << "BINGO";
    print(' ', 7);
    cout << "*" << endl;
    print('*', 21);
    cout << "\n\n";
}

#define FELSO_KORLAT 80
#define ALSO_KORLAT 30

void    jatek_indit(int szam)
{
    int     rn = 2 + (rand() % 5);
    int     *tab;
    klista a(szam);

    tab = new int[szam * 3 / 4];
    for (int k = 0; k < szam * 3 / 4;)
        {
            if (!rn--)
            {
                rn = 2 + (rand() % 5);
                tab[k++] = a.get();
                a.torol();
                cout << "Kihuzott szam:" << "*" << tab[k - 1] << "*" << endl;
                system("sleep 1.5");
            }
            system("clear");
            kiir_bingo();
            cout << endl << endl;
            cout << "Maradando szamok:\n";
            cout << endl;
            a.f_kiir(10);
            a.lep();
            cout << "Kihuzott szamok:";
            cout << endl;
            kiir(tab, k);
            system("sleep 0.2");
        }
}

int     main()
{
    srand(time(NULL));
    int     k = 0;
    int     val;
    int     szam = 49; 
    int     valasz = 0;
    bool    meg = true;
    char    aux;
    while (meg)
    {
        system("clear");
        kiir_bingo();
        cout << "1.Szelveny megrakasa\n";
        cout << "2.Jatek inditasa\n";
        cout << "3.Maximalis intervallum\n";
        cout << "4.Kilepes\n";

        cin >> valasz;
        switch (valasz)
        {
            case 1:
                //insert_ppl();
                break;
            case 2:
                jatek_indit(szam);
                cin >> aux;
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
                meg = false;
                break;
            default :
                cout << "!!!Nem letezik ilyen opcio!!!\n";
                system("sleep 2");
                break;
        }
    }
    system("clear");
    cout << "Koszonjuk szepen, hogy jatszott :)\n";
    return (0);
}
