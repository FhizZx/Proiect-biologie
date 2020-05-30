#ifndef _SCENE_H_
#define _SCENE_H_

#include <system.h>

class Scene {
    public:
        virtual void init() = 0;
        virtual void clear() = 0;

        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void handleEvents(System* s) = 0;
        virtual void update(System* s) = 0;
        virtual void render(System* s) = 0;

        void quitSystem(System *sys) {
            sys->quit();
        }

        void changeScene(System* sys, Scene* s) {
            sys->changeScene(s);
        }
};

#endif // _SCENE_H_
