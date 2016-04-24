#include "head.h"

klista::~klista()
{   
    elem    *kezd, *kov;
    kezd = poz;
    while (poz->kov != kezd)
    {
        kov = poz->kov;
        delete poz;
        poz = kov;
    }
    delete poz;
}

klista::klista()
{
    int     i = 49;

    poz = new elem;
    poz->ert = i--;
    poz->kov = poz;
    for ( ; i > 0; i--)
            beszur(i);
    lep();
}

klista::klista(int i)
{
    poz = new elem;
    poz->ert = i--;
    poz->kov = poz;
    for ( ; i > 0; i--)
            beszur(i);
    lep();
}

void    klista::beszur(int n)
{
    elem    *uj;

    uj = new elem;
    uj->ert = n;
    uj->kov = poz->kov;
    poz->kov = uj;
}


