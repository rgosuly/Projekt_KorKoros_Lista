#include "head.h"

void klista::f_kiir(int k)
{
	int db = 0;
	int *seged = poz;

	while (seged->kov != poz)
		{
		cout<<seged->ert;
		db++;
		if (db == k)
			{
			cout<<endl;
			db = 0;
			}
		}
}
