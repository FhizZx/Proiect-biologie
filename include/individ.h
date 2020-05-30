#ifndef _INDIVID_H_
#define _INDIVID_H_

#include <library.h>
#include <texture.h>
#include <time.h>

class Individ {
    public:
        Individ();
        void random();
        void reproducere(Individ A, Individ B);
        void render(int x, int y, bool isFlipped);
        void renderMini(int x, int y, bool isFlipped);
        bool getGender();
        void setGender(bool gender);
    private:
        int pistrui[2];
        int barbie[2];
        int nas[2];
        int sprancene[2];
        int gene[2];
        int ureche[2];
        int piele[6];
        int ochi[2];
        int gender[2];
        int sange[2];

};

#endif // _INDIVID_H_

