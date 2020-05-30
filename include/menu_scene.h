#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include <button.h>
#include <scene.h>
#include <individ.h>
#include <zoom.h>

class Menu: public Scene {
    public:

        void init();
        void clear();

        void pause();
        void resume();

        void handleEvents(System* s);
        void update(System* s);
        void render(System* s);

        void loadBackground(std::string imgPath);
        void loadOption(int id, std::string imgPath, SDL_Rect box);
        void setOptionsNumber(int t);
        void generareArbore();
        int getOptionsNumber();

    private:
        Individ in[10];
        Texture backgroundImage;
        int optionsNumber;
        Button option[10];
};
#endif // _MENU_SCENE_H_
