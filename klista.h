
#ifndef KLISTA_H
# define KLISTA_H

# include "head.h"

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

void klista::kiir()
{
	elem *seged = poz;
	while ( seged->kov != poz  )
		{
		    cout << seged->ert << " ";
		    seged = seged->kov;
		}
    cout << seged->ert << endl;
}

void klista::f_kiir(int k)
{
	int db = 0;
	elem *seged = poz;

	while (seged->kov != poz)
	{
        if (seged->ert < 10)
            cout << " ";
		cout << seged->kov->kov->ert << " ";
		db++;
		if (db == k)
			{
			    cout<<endl;
			    db = 0;
			}
        seged = seged->kov;
	}
    cout << endl;
}

int klista::torol()
{
	int ertek = 0;

	ertek = poz->kov->ert;
  	poz->kov = poz->kov->kov;
	return ertek;
}
#endif
