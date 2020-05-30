#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <library.h>

class Scene;

class System {
    public:
        System();
        ~System();

        //initialize system
        void init();
        //manage system
        void run();
        //quit application
        void quit();
        //deallocate memory, close subsystems
        void clear();

        //change screen
        void changeScene(Scene* s);
        //start temporary scene
        void pushScene(Scene* s);
        //quit temporary scene
        void popScene();

        //send commands to current scene
        void handleEvents();
        void update();
        void render();

        //initialize graphics library and its subsystems
        bool initSDL();
        bool initSDL_Image();
        bool initSDL_TTF();

        //create window and renderer
        bool createWindow();
        bool createRenderer();

    private:
        //stack of scenes
        std::vector<Scene*> sceneStack;
        bool isQuit;

};


#endif // _SYSTEM_H_
