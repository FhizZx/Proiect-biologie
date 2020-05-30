#include <individ.h>

Individ::Individ() {
    random();
}

void Individ::random() {
    int nr;
    for (int i = 0; i <= 1; i++) {
        nr = rand() % 100;
        if (nr > 6)
            pistrui[i] = 0;
        else
            pistrui[i] = 1;
        barbie[i] = rand() % 2;
        nas[i] = rand() % 2;
        gene[i] = rand() % 2;
        sprancene[i] = rand() % 2;
        ochi[i] = rand() % 3;
        sange[i] = rand() % 3;
    }
    for (int i = 0; i <= 5; i++) {
        nr = rand() % 100;
        if (nr > 30)
            piele[i] = 0;
        else
            piele[i] = 1;
    }
    setGender(rand() % 2);
}

void Individ::reproducere(Individ A, Individ B) {
    int nr = rand() % 2;
    pistrui[0] = A.pistrui[nr];
    nr = rand() % 2;
    pistrui[1] = B.pistrui[nr];
    nr = rand() % 2;
    nas[0] = A.nas[nr];
    nr = rand() % 2;
    nas[1] = B.nas[nr];
    nr = rand() % 2;
    barbie[0] = A.barbie[nr];
    nr = rand() % 2;
    barbie[1] = B.barbie[nr];
    nr = rand() % 2;
    gene[0] = A.gene[nr];
    nr = rand() % 2;
    gene[1] = B.gene[nr];
    for (int i = 0; i <= 4; i += 2) {
        nr = rand() % 2;
        piele[i] = A.piele[nr + i];
    }
    for (int i = 0; i <= 4; i += 2) {
        nr = rand() % 2;
        piele[i + 1] = B.piele[nr + i];
    }
    nr = rand() % 2;
    ochi[0] = A.ochi[nr];
    nr = rand() % 2;
    ochi[1] = B.ochi[nr];
    nr = rand() % 2;
    sange[0] = A.sange[nr];
    nr = rand() % 2;
    sange[1] = B.sange[nr];
    nr = rand() % 2;
    gender[0] =  A.gender[nr];
    nr = rand() % 2;
    gender[1] = B.gender[nr];
}

void Individ::setGender(bool gender) {
    Individ::gender[0] = 0;
    Individ::gender[1] = gender;
}

bool Individ::getGender() {
    return gender[0] + gender[1];
}

void Individ::renderMini(int x, int y, bool isFlipped) {
    Uint8 p = 0;
    for (int i = 0; i <= 5; i++)
        p = p + piele[i];
    p = 6 - p;
    p = p * 255 / 6;
    Texture image;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if (isFlipped == 1)
        flip = SDL_FLIP_HORIZONTAL;
    image.load("res/individbg_mini.png");
    image.render(x, y, NULL, 0.0, NULL, flip);
    SDL_Colour black = {0, 0, 0, 255};
    if (sange[0] == 0) {
        if (sange[1] == 0)
            image.loadText("0 I", globalFont_mini, black);
        else if(sange[1] == 1)
            image.loadText("A II", globalFont_mini, black);
        else if(sange[1] == 2)
            image.loadText("B III", globalFont_mini, black);
    }
    else if (sange[0] == 1) {
        if (sange[1] == 0)
            image.loadText("A II", globalFont_mini, black);
        else if(sange[1] == 1)
            image.loadText("A II", globalFont_mini, black);
        else if(sange[1] == 2)
            image.loadText("AB IV", globalFont_mini, black);
    }
    else if (sange[0] == 2) {
        if (sange[1] == 0)
           image.loadText("B III", globalFont_mini, black);
        else if(sange[1] == 1)
        image.loadText("AB IV", globalFont_mini, black);
        else if(sange[1] == 2)
           image.loadText("B III", globalFont_mini, black);
    }
    image.render(x + 192 - image.getWidth(), y + 7);
    if (gender[0] + gender[1] == 0)
        image.load("res/female_symbol_mini.png");
    else
        image.load("res/male_symbol_mini.png");
    image.render(x, y + 5);

    image.load("res/eyecolour.png");
    if (ochi[0] == 0) {
        if (ochi[1] == 0)
            image.setColor(10, 10, 10);
        else if(ochi[1] == 1)
            image.setColor(36, 17, 10);
        else if(ochi[1] == 2)
            image.setColor(155, 101, 39);
    }
    else if (ochi[0] == 1) {
        if (ochi[1] == 0)
            image.setColor(36, 17, 10);
        else if(ochi[1] == 1)
            image.setColor(100, 69, 33);
        else if(ochi[1] == 2)
            image.setColor(141, 160, 51);
    }
    else if (ochi[0] == 2) {
        if (ochi[1] == 0)
            image.setColor(155, 101, 39);
        else if(ochi[1] == 1)
            image.setColor(141, 160, 51);
        else if(ochi[1] == 2)
            image.setColor(121, 153, 175);
    }
    image.render(x + 84, y + 5);
    image.load("res/eyesymbol.png");
    image.render(x + 84, y + 5);
    image.load("res/fata_baza_mini.png");
    image.setColor(p, p, p);
    image.render(x, y, NULL, 0.0, NULL, flip);
    if (barbie[0] + barbie[1] == 0) {
        image.load("res/barbie_tesita_filling_mini.png");
        image.setColor(p, p, p);
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (barbie[0] + barbie[1] == 1) {
        image.load("res/barbie_dreapta_filling_mini.png");
        image.setColor(p, p, p);
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (barbie[0] + barbie[1] == 2) {
        image.load("res/barbie_proeminenta_filling_mini.png");
        image.setColor(p, p, p);
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    if (nas[0] + nas[1] == 0) {
        image.load("res/nas_carn_filling_mini.png");
        image.setColor(p, p, p);
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (nas[0] + nas[1] == 1) {
        image.load("res/nas_grec_filling_mini.png");
        image.setColor(p, p, p);
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (nas[0] + nas[1] == 2) {
        image.load("res/nas_roman_filling_mini.png");
        image.setColor(p, p, p);
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    image.load("res/culoare_ochi_mini.png");
    if (ochi[0] == 0) {
        if (ochi[1] == 0)
            image.setColor(10, 10, 10);
        else if(ochi[1] == 1)
            image.setColor(36, 17, 10);
        else if(ochi[1] == 2)
            image.setColor(155, 101, 39);
    }
    else if (ochi[0] == 1) {
        if (ochi[1] == 0)
            image.setColor(36, 17, 10);
        else if(ochi[1] == 1)
            image.setColor(100, 69, 33);
        else if(ochi[1] == 2)
            image.setColor(141, 160, 51);
    }
    else if (ochi[0] == 2) {
        if (ochi[1] == 0)
            image.setColor(155, 101, 39);
        else if(ochi[1] == 1)
            image.setColor(141, 160, 51);
        else if(ochi[1] == 2)
            image.setColor(121, 153, 175);
    }
    image.render(x, y, NULL, 0.0, NULL, flip);
    image.load("res/fata_mini.png");
    image.render(x, y, NULL, 0.0, NULL, flip);
    if (barbie[0] + barbie[1] == 0) {
        image.load("res/barbie_tesita_mini.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (barbie[0] + barbie[1] == 1) {
        image.load("res/barbie_dreapta_mini.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (barbie[0] + barbie[1] == 2) {
        image.load("res/barbie_proeminenta_mini.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    if (nas[0] + nas[1] == 0) {
        image.load("res/nas_carn_mini.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (nas[0] + nas[1] == 1) {
        image.load("res/nas_grec_mini.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (nas[0] + nas[1] == 2) {
        image.load("res/nas_roman_mini.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    if (gene[0] + gene[1] >= 1) {
        image.load("res/gene_groase_mini.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else {
        image.load("res/gene_subtiri_mini.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    if (sprancene[0] + sprancene[1] >= 1) {
        image.load("res/sprancene_groase_mini.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else {
        image.load("res/sprancene_subtiri_mini.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    if (pistrui[0] + pistrui[1] >= 1) {
        image.load("res/pistrui_mini.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    image.load("res/border_mini.png");
    image.render(x, y, NULL, 0.0, NULL, flip);
}

void Individ::render(int x, int y, bool isFlipped) {
    Uint8 p = 0;
    for (int i = 0; i <= 5; i++)
        p = p + piele[i];
    p = 6 - p;
    p = p * 255 / 6;
    Texture image;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    if (isFlipped == 1)
        flip = SDL_FLIP_HORIZONTAL;
    image.load("res/individbg.png");
    image.render(x, y, NULL, 0.0, NULL, flip);
    SDL_Colour black = {0, 0, 0, 255};
    if (sange[0] == 0) {
        if (sange[1] == 0)
            image.loadText("0 I", globalFont, black);
        else if(sange[1] == 1)
            image.loadText("A II", globalFont, black);
        else if(sange[1] == 2)
            image.loadText("B III", globalFont, black);
    }
    else if (sange[0] == 1) {
        if (sange[1] == 0)
            image.loadText("A II", globalFont, black);
        else if(sange[1] == 1)
            image.loadText("A II", globalFont, black);
        else if(sange[1] == 2)
            image.loadText("AB IV", globalFont, black);
    }
    else if (sange[0] == 2) {
        if (sange[1] == 0)
           image.loadText("B III", globalFont, black);
        else if(sange[1] == 1)
        image.loadText("AB IV", globalFont, black);
        else if(sange[1] == 2)
           image.loadText("B III", globalFont, black);
    }
    image.render(x + 580 - image.getWidth(), y + 20);
    if (gender[0] + gender[1] == 0)
        image.load("res/female_symbol.png");
    else
        image.load("res/male_symbol.png");
    image.render(x, y + 5);
    image.load("res/fata_baza.png");
    image.setColor(p, p, p);
    image.render(x, y, NULL, 0.0, NULL, flip);
    if (barbie[0] + barbie[1] == 0) {
        image.load("res/barbie_tesita_filling.png");
        image.setColor(p, p, p);
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (barbie[0] + barbie[1] == 1) {
        image.load("res/barbie_dreapta_filling.png");
        image.setColor(p, p, p);
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (barbie[0] + barbie[1] == 2) {
        image.load("res/barbie_proeminenta_filling.png");
        image.setColor(p, p, p);
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    if (nas[0] + nas[1] == 0) {
        image.load("res/nas_carn_filling.png");
        image.setColor(p, p, p);
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (nas[0] + nas[1] == 1) {
        image.load("res/nas_grec_filling.png");
        image.setColor(p, p, p);
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (nas[0] + nas[1] == 2) {
        image.load("res/nas_roman_filling.png");
        image.setColor(p, p, p);
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    image.load("res/culoare_ochi.png");
    if (ochi[0] == 0) {
        if (ochi[1] == 0)
            image.setColor(10, 10, 10);
        else if(ochi[1] == 1)
            image.setColor(36, 17, 10);
        else if(ochi[1] == 2)
            image.setColor(155, 101, 39);
    }
    else if (ochi[0] == 1) {
        if (ochi[1] == 0)
            image.setColor(36, 17, 10);
        else if(ochi[1] == 1)
            image.setColor(100, 69, 33);
        else if(ochi[1] == 2)
            image.setColor(141, 160, 51);
    }
    else if (ochi[0] == 2) {
        if (ochi[1] == 0)
            image.setColor(155, 101, 39);
        else if(ochi[1] == 1)
            image.setColor(141, 160, 51);
        else if(ochi[1] == 2)
            image.setColor(121, 153, 175);
    }
    image.render(x, y, NULL, 0.0, NULL, flip);
    image.load("res/fata.png");
    image.render(x, y, NULL, 0.0, NULL, flip);
    if (barbie[0] + barbie[1] == 0) {
        image.load("res/barbie_tesita.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (barbie[0] + barbie[1] == 1) {
        image.load("res/barbie_dreapta.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (barbie[0] + barbie[1] == 2) {
        image.load("res/barbie_proeminenta.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    if (nas[0] + nas[1] == 0) {
        image.load("res/nas_carn.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (nas[0] + nas[1] == 1) {
        image.load("res/nas_grec.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else if (nas[0] + nas[1] == 2) {
        image.load("res/nas_roman.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    if (gene[0] + gene[1] >= 1) {
        image.load("res/gene_groase.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else {
        image.load("res/gene_subtiri.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    if (sprancene[0] + sprancene[1] >= 1) {
        image.load("res/sprancene_groase.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    else {
        image.load("res/sprancene_subtiri.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    if (pistrui[0] + pistrui[1] >= 1) {
        image.load("res/pistrui.png");
        image.render(x, y, NULL, 0.0, NULL, flip);
    }
    image.load("res/border.png");
    image.render(x, y, NULL, 0.0, NULL, flip);
}
