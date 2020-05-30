#include <menu_scene.h>



void Menu::loadBackground(std::string imgPath) {
    backgroundImage.load(imgPath);
}

void Menu::loadOption(int id, std::string imgPath, SDL_Rect box) {
    option[id].load(imgPath);
    option[id].setPosition(box.x, box.y);
    option[id].setSize(box.w, box.h);

}

void Menu::init() {
    loadBackground("res/background.png");
    generareArbore();

}

void Menu::clear() {
    SDL_RenderClear(Renderer);
    backgroundImage.free();
    for (int i = 1; i <= optionsNumber; i++)
        option[i].clear();
}

void Menu::setOptionsNumber(int t) {
    optionsNumber = t;
}
int Menu::getOptionsNumber() {
    return optionsNumber;
}

void Menu::pause() {

}

void Menu::resume() {

}

void Menu::generareArbore() {
    in[2].random();
    in[3].random();
    in[3].setGender(1 - in[2].getGender());
    in[4].random();
    in[5].random();
    in[5].setGender(1 - in[4].getGender());
    in[6].reproducere(in[2], in[3]);
    in[7].reproducere(in[4], in[5]);
    in[7].setGender(1 - in[6].getGender());
    in[8].reproducere(in[6], in[7]);
    in[9].reproducere(in[6], in[7]);
}

void Menu::handleEvents(System* s) {
    SDL_Event e;
	if (SDL_PollEvent(&e)) {
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            quitSystem(s);
        if (option[1].handleEvents(&e) == 1)
            generareArbore();
	}
}


void Menu::update(System* s) {

}

void Menu::render(System* s) {
    backgroundImage.render(0,0);
    for (int i = 1; i <= optionsNumber; i++)
        option[i].render();
    in[2].renderMini(100, 20, 1);
    in[3].renderMini(400, 20, 0);
    in[4].renderMini(766, 20, 1);
    in[5].renderMini(1066, 20, 0);
    in[6].renderMini(250, 270, 1);
    in[7].renderMini(916, 270, 0);
    in[8].renderMini(433, 520, 0);
    in[9].renderMini(733, 520, 1);
    SDL_RenderPresent(Renderer);

}


