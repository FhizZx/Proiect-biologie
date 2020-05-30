#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <texture.h>

class Scene;

enum ButtonSprite {
    BUTTON_SPRITE_MOUSE_OUT = 0,
    BUTTON_SPRITE_MOUSE_OVER = 1,
    BUTTON_SPRITE_MOUSE_DOWN = 2,
    BUTTON_SPRITE_MOUSE_UP = 3,
    BUTTON_SPRITE_TOTAL = 4
};

class Button {
    public:
        Button();
        ~Button();
        void load(std::string imgPath);
        void setPosition(int x, int y);
        void setSize(int w, int h);
        bool handleEvents(SDL_Event* e);
        void render();
        void clear();

    private:
        SDL_Rect box;
        Texture buttonTexture;
        ButtonSprite currentSprite;
};
#endif // _BUTTON_H_

