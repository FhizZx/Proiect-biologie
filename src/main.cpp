#include <system.h>
#include <menu_scene.h>

int main(int argc, char* args[]) {
    System gameSystem;
    srand(time(NULL));

    Menu arboreGenealogic, zoomIndivid;
    gameSystem.init();
    arboreGenealogic.setOptionsNumber(1);
    SDL_Rect box;
    box.h = 100;
    box.w = 300;
    box.x = 533;
    box.y = 320;
    arboreGenealogic.loadOption(1, "res/butonarbore.png", box);

    globalFont = TTF_OpenFont("res/segoeui.ttf", 48);
    globalFont_mini = TTF_OpenFont("res/segoeui.ttf", 16);

    gameSystem.changeScene(&arboreGenealogic);
    gameSystem.run();

    return 0;
}
