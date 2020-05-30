#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <cstdio>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>

extern SDL_Renderer *Renderer;
extern SDL_Window *Window;

extern TTF_Font *globalFont;
extern TTF_Font *globalFont_mini;

const int WINDOW_WIDTH = 1366;
const int WINDOW_HEIGHT = 768;

const int MAINMENU_OPTIONS_NUMBER = 10;



#endif // _LIBRARY_H_
