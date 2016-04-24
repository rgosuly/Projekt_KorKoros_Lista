#include "head.h"

void klista::f_kiir(int k)
{
	int db = 0;
	elem *seged = poz;

	while (seged->kov != poz)
	{
        if (seged->ert < 10)
            cout << " ";
		cout << seged->ert << " ";
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
