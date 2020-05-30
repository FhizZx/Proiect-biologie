#ifndef _ZOOM_H_
#define _ZOOM_H_

#include <button.h>
#include <scene.h>
#include <individ.h>

class Zoom: public Scene {
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
        void setIndivid(Individ k);
        int getOptionsNumber();

    private:
        Individ x;
        Texture backgroundImage;
        int optionsNumber;
        Button option[10];
};
#endif // _MENU_SCENE_H_

