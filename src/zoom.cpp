#include <zoom.h>



void Zoom::loadBackground(std::string imgPath) {
    backgroundImage.load(imgPath);
}

void Zoom::loadOption(int id, std::string imgPath, SDL_Rect box) {
    option[id].load(imgPath);
    option[id].setPosition(box.x, box.y);
    option[id].setSize(box.w, box.h);

}

void Zoom::handleEvents(System* s) {
    SDL_Event e;
	if (SDL_PollEvent(&e)) {
        if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)
            quitSystem(s);
        if (option[1].handleEvents(&e) == 1)
            generareArbore();
        for (int i = 2; i <= optionsNumber; i++)
            if (option[i].handleEvents(&e) == 1) {
                Zoom *z;
                z->setIndivid(in[i]);
                changeScene(s, z);
            }
	}
}

void Zoom::init() {
    loadBackground("res/background2.png");

}

void Zoom::clear() {
    SDL_RenderClear(Renderer);
    backgroundImage.free();
    for (int i = 1; i <= optionsNumber; i++)
        option[i].clear();
}

void Zoom::setOptionsNumber(int t) {
    optionsNumber = t;
}
int Zoom::getOptionsNumber() {
    return optionsNumber;
}

void Zoom::pause() {

}

void Zoom::resume() {

}



void Zoom::update(System* s) {

}

void Zoom::setIndivid(Individ k) {
    x = k;
}

void Zoom::render(System* s) {
    backgroundImage.render(0,0);
    for (int i = 1; i <= optionsNumber; i++)
        option[i].render();
    x.render(300, 300, 0);
    SDL_RenderPresent(Renderer);

}



