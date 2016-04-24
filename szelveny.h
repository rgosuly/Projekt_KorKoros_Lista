#ifndef SZELVENY_H
# define SZELVENY_H

#include "head.h"

void    szelveny::kiir()
{
    cout << endl;
    cout << nev;
    cout << endl;
    cout << "Tet: " << tet;
    for (int i = 0; i < 6; i++)
        cout << szamok[i] << " ";
    cout << endl;
}

szelveny::szelveny()
{
    kov = NULL;
}

void szelveny::beolvas(int felso_hat)
{
    bool     jo = true;
    cout << "Adja meg a nevet: ";
    cin >> nev;
    cout << "Mekkora tetet szeretne berakni ?";
    cin >> tet;
    cout << "Adja meg a 6 szamot amit be szeretne olvasni: ";
    for (int i = 0; i < HAT; i++)
    {
        do{ 
            cin >> szamok[i];
            jo = true;
            for (int j = 0; j < i; j++)
                if (szamok[i] == szamok[j])
                    jo = false;
            if (szamok[i] > felso_hat || szamok[i] < 1)
                jo = false;
            if (!jo)
                cout << "Nem megfelelo szam, adj meg egy ujat helyette.\n";
        }while(!jo);
    }
    rendez();
}


void    szelveny::rendez()
{
	int csere = 0;
	for (int i=0 ; i<HAT - 1 ; i++)
		for (int j=i+1 ; j<HAT ; j++)
			if (szamok[i] > szamok[j])
				{
                    csere = szamok[i];
				    szamok[i] = szamok[j];
				    szamok[j] = csere;
				}
}

void    szelveny::kiir_gy(int szorzo)
{
    cout << nev << " nyert " << 2 * szorzo * tet << " RON-t a kovetkezo szamokkal: ";
    for (int i = 0; i < 6; i++)
        cout << szamok[i]<<" ";
    cout <<endl;
}

void    szelveny::ellenorzes(int *nyert, int hossz)
{
	int     i = 0;
    int     talalt = 0;
    for (int i = 0; i < hossz; i++)
        for (int j = 0; j < 6 && szamok[j] <= nyert[i]; j++)
            if (szamok[j] == nyert[i])
            {
                talalt++;
                break;
            }
    if (talalt == 6)
        kiir_gy(hossz - i);
}
#endif
