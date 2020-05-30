#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <library.h>

class Texture{
    public:
        //constructor
        Texture();

        //deconstructor
        ~Texture();

        //loads image into texture from the path specified
        bool load(std::string path);

        //renders texture at specified coordinates
        void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0,
                     SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

        //creates image from font string
        bool loadText(std::string textureText, TTF_Font* textFont, SDL_Color textColor);

        //sets color modulation
        void setColor( Uint8 red, Uint8 green, Uint8 blue );

         //Set blending
        void setBlendMode(SDL_BlendMode blending);

        //Set alpha modulation
        void setAlpha(Uint8 alpha);

        //removes image from texture
        void free();

        //gets image dimensions
        int getWidth();
        int getHeight();
    private:
        //hardware texture
        SDL_Texture* image;

        //image dimensions
        int width;
        int height;

};

#endif // _TEXTURE_H_

