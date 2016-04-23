#include "head.h"


void klista::kiir()
{
	elem *seged = poz;
	while ( seged->kov != poz  )
		{
		cout<<seged->ert;
		seged = seged->kov;
		}
}
