#include <texture.h>

Texture::Texture() {
    //generate empty texture
    image = NULL;
    width = 0;
    height = 0;
}

Texture::~Texture() {
    //deallocate
    free();
}

bool Texture::load(std::string path) {
    //remove preexisting image if it exists
    free();

    SDL_Texture* newTexture = NULL;

    //load image from specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(Renderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            width = loadedSurface->w;
            height = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //return success
    image = newTexture;
    return image != NULL;
}

bool Texture::loadText(std::string textureText, TTF_Font* textFont, SDL_Color textColor )
{
    //get rid of preexisting texture
    free();

    //render text surface
    SDL_Surface* textSurface = TTF_RenderText_Blended(textFont, textureText.c_str(), textColor);
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //create texture from surface pixels
        image = SDL_CreateTextureFromSurface(Renderer, textSurface);
        if( image == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            width = textSurface->w;
            height = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface(textSurface);
    }

    //Return success
    return image != NULL;
}

void Texture::free()
{
    //free texture if it exists
    if (image != NULL)
    {
        SDL_DestroyTexture(image);
        image = NULL;
        width = 0;
        height = 0;
    }
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
    //modulate texture
    SDL_SetTextureColorMod(image, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending)
{
    //set blending function
    SDL_SetTextureBlendMode(image, blending);
}

void Texture::setAlpha(Uint8 alpha)
{
    //modulate texture alpha
    SDL_SetTextureAlphaMod(image, alpha);
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
    SDL_Rect renderQuad = {x, y, width, height};

    if( clip != NULL )
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopyEx(Renderer, image, clip, &renderQuad, angle, center, flip);
}

int Texture::getWidth()
{
    return width;
}

int Texture::getHeight()
{
    return height;
}

