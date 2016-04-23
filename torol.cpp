#include "head.h"


int klista::torol()
{
	int ertek = 0;

	ertek = poz->kov->ert;
  	poz->kov = poz->kov->kov;
	return ertek;
}
