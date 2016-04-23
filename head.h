//Kiss Alpar
//512

#ifndef HEAD_H
# define HEAD_H

struct  elem{
    int     ert;
    elem    *kov;
}


class   klista
{
    private:
        elem    *poz;
    public:
                klista();
                klista(int f_hat);
                ~klista();
        void    betesz();
        void    lep(){poz = poz->kov};
        int     torol();
        void    kiir();
        void    f_kiir(int);
};

#endif
