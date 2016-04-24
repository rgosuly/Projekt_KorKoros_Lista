//Kiss Alpar
//512

#ifndef HEAD_H
# define HEAD_H

#define FELSO_KORLAT 80
#define ALSO_KORLAT 30
#define HAT 6


#include <cstdlib>
#include <iostream>

using namespace std;

struct  elem{
    int     ert;
    elem    *kov;
};

class   klista
{
    private:
        elem    *poz;
    public:
                klista();
                klista(int f_hat);
                ~klista();
        void    beszur(int n);
        void    lep(){poz = poz->kov;};
        int     torol();
        void    kiir();
        void    f_kiir(int);
        bool    ures(){if (poz == NULL) return true; return false;};
        int     get(){return (poz->kov->ert);};
};

class szelveny
{
	private:
        string        nev;
        int         szamok[6];
        int         tet;
	public:
        szelveny    *kov;
		        szelveny();
        void    bekov(szelveny *elso){kov = elso;};
        void    beolvas(int);
		void    megrak(string , int*, int);
		void    rendez();
		void    ellenorzes(int*, int);
        void    kiir_gy(int);
        void    kiir();
};


class Lista
{
    szelveny     *elso;
    public:
    Lista();
    ~Lista();
    void    megrak(int);
    void    kiir_gy(int *, int);
    void    kiir();
};
#endif
