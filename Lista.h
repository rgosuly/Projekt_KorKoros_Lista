#ifndef LISTA_H
# define LISTA_H
#include "head.h"

Lista::Lista()
{
    elso = NULL;
}

Lista::~Lista()
{
    szelveny    *seged = elso;

    while(seged != NULL)
    {
        cout << "alma";
       elso = elso->kov;
       delete seged;
       seged = elso;
    }
}

void    Lista::kiir_gy(int *nyer, int n)
{
    szelveny    *seged = elso;
    while (seged != NULL)
    {
        seged->ellenorzes(nyer, n);
        seged = seged->kov;
    }
}

void    Lista::kiir()
{
    szelveny    *seged = elso;
    while (seged != NULL)
    {
        seged->kiir();
        seged = seged->kov;
    }
}

void    Lista::megrak(int szam)
{
    szelveny *uj;
    
    uj = new szelveny;
    uj->kov = elso;
    elso = uj;
    uj->beolvas(szam);
}
#endif
