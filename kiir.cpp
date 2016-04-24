#include "head.h"


void klista::kiir()
{
	elem *seged = poz;
    int i = 1;
	while ( seged->kov != poz  )
		{
		    cout << seged->ert << " ";
		    seged = seged->kov;
		}
    cout << seged->ert << endl;
}
