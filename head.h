//Kiss Alpar
//512

#ifndef HEAD_H
# define HEAD_H

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
        int     get(){return (poz->ert);};
};

#endif
