#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

struct elem{
	int ert;
	elem *kov,*str1,*str2;
};

struct szelveny{
	string nev;
	szelveny *next;
	elem *szam;
};

class Lista
{
	private:
 		szelveny *poz, *elso,*utolso;
	public:
		Lista();
		void megrak(string , int*, int);
		szelveny* Dekl();
		int *rendez(int*, int);
		bool torles(int*, int);
};

Lista::Lista()
{
	elso = new szelveny;
	utolso = new szelveny;
	
	elso->next = utolso;
	utolso->next = NULL;
}

szelveny* Lista::Dekl()
{
	szelveny *seged;
	seged = new szelveny;
	seged->szam = new elem;
	seged->szam->str1 = new elem;
	seged->szam->str2 = new elem;
	return seged;

}

int* Lista::rendez(int* a, int n)
{
	int csere = 0;
	for (int i=0 ; i<n-1 ; i++)
		for (int j=i+1 ; j<n ; j++)
			if (a[i]<a[j])
				{
				csere = a[i];
				a[i] = a[j];
				a[j] = csere;
				}
	return a;
}

void Lista::megrak(string jatekos, int* szamok, int n)
{
	int *a = rendez(szamok,n);
	elem *uj_szam;
	poz = Dekl();
	poz->next = elso->next;
	elso->next = poz;
	poz->szam->str1 = poz->szam->str2; 

	poz->nev = jatekos;
	cout<<endl<<poz->nev<<endl;
	for (int i=0; i<n; i++)
 		{
		uj_szam = new elem;
		uj_szam->str1 = new elem;
		uj_szam->str2 = new elem;
		uj_szam->kov = poz->szam->str1->kov;
		poz->szam->str1->kov = uj_szam;
		uj_szam->ert = a[i];
		} 	
}

int Lista::torles(szelveny poz,int *nyert, int hossz)
{
	int db = 0;
	elem *seged;
	seged = poz->szam->str1->kov;;
	while ((seged !=str2)&&(db !=0))
	{
	if (seged->ert == nyert[db])
		seged = seged->kov;
	db++;
	}
	if (seged == poz->szam->str2)
		return db;
	else
		return -1;	
}

/*void Lista::kiir()
{
	
	elem* seged = new elem;
	poz = Dekl();
	poz = elso ->next;
	cout<<poz->szam->str1->kov->kov->ert;
	while ( poz != utolso  )
		{
		cout<<poz->nev<<" szelvenye: ";
		
		seged = poz->szam->str1->kov;
		
		while ( seged != poz->szam->str2 )
			{
			
			//cout<<seged->ert<<" ";
			seged = seged->kov;				
			}
		cout<<endl;
		poz = poz->next;	
		}

}*/

int main()
{
int *k;
k = new int [6];

cout<<"Hello world! :-)"<<endl;

for (int i =0 ; i<6 ; i++)
	k[i] = i+1;

Lista a;

string karakt;
karakt = "Pistike";


a.megrak(karakt,k,6);


for (int i=0 ; i<6 ; i++)
	k[i]+=10;

karakt = "Lacika";

a.megrak(karakt,k,6);

return 0;
}
