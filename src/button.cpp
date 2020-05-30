#include <button.h>


Button::Button() {
    box.x = 0;
    box.y = 0;
    box.h = 0;
    box.w = 0;
    currentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

Button::~Button() {
}

void Button::load(std::string imgPath) {
    buttonTexture.load(imgPath);
}

void Button::clear() {
    box.x = 0;
    box.y = 0;
    box.h = 0;
    box.w = 0;
    currentSprite = BUTTON_SPRITE_MOUSE_OUT;

    buttonTexture.free();
}

void Button::setPosition(int x, int y) {
    box.x = x;
    box.y = y;
}

void Button::setSize(int w, int h) {
    box.w = w;
    box.h = h;
}

bool Button::handleEvents(SDL_Event* e) {
     //if mouse event happened
     bool ok = 0;
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {
        //get mouse position
        int x, y;
        SDL_GetMouseState(&x, &y);

        //check if mouse is in button
        bool inside = true;

        //mouse is left of the button
        if (x < box.x)
        {
            inside = false;
        }
        //mouse is right of the button
        else if (x > box.x + box.w)
        {
            inside = false;
        }
        //mouse above the button
        else if (y < box.y)
        {
            inside = false;
        }
        //mouse below the button
        else if (y > box.y + box.h)
        {
            inside = false;
        }
        //Mouse is outside button
        if( !inside )
        {
            currentSprite = BUTTON_SPRITE_MOUSE_OUT;
        }
        //Mouse is inside button
        else
        {
            //Set mouse over sprite
            switch( e->type )
            {
                case SDL_MOUSEMOTION:
                currentSprite = BUTTON_SPRITE_MOUSE_OVER;
                break;

                case SDL_MOUSEBUTTONDOWN:
                currentSprite = BUTTON_SPRITE_MOUSE_DOWN;
                break;

                case SDL_MOUSEBUTTONUP:
                currentSprite = BUTTON_SPRITE_MOUSE_UP;
                ok = 1;
                break;
            }
        }
    }
    return ok;
}


void Button::render() {
    SDL_Rect spriteClip = {currentSprite * box.w, 0, box.w, box.h};
    buttonTexture.render(box.x, box.y, &spriteClip);
}
