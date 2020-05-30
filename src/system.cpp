#include <system.h>
#include <scene.h>

System::System() {
}

System::~System() {
}

void System::init() {
    if(!initSDL()) return;
    if(!initSDL_Image()) return;
    if(!initSDL_TTF()) return;
    if(!createWindow()) return;
    if(!createRenderer()) return;
    isQuit = 0;
}

void System::run() {
    while (!isQuit) {
        System::handleEvents();
        System::update();
        System::render();
    }
    clear();
}

void System::quit() {
    isQuit = 1;
}

void System::clear() {

    //clear scene stack
    while (!sceneStack.empty()) {
        sceneStack.back()->clear();
        sceneStack.pop_back();
    }

    //destroy window
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window );
	Window = NULL;
	Renderer = NULL;

	//quit SDL subsystems
	IMG_Quit();
    TTF_Quit();
	SDL_Quit();

}


void System::changeScene(Scene* s) {
    // cleanup the current state
	if ( !sceneStack.empty() ) {
		sceneStack.back()->clear();
		sceneStack.pop_back();
	}

	// store and init the new state
	sceneStack.push_back(s);
	sceneStack.back()->init();
}

void System::pushScene(Scene* s) {
    // pause current state
	if ( !sceneStack.empty() ) {
		sceneStack.back()->pause();
	}

	// store and init the new state
	sceneStack.push_back(s);
	sceneStack.back()->init();
}

void System::popScene() {
    // cleanup the current state
	if ( !sceneStack.empty() ) {
		sceneStack.back()->clear();
		sceneStack.pop_back();
	}

	// resume previous state
	if ( !sceneStack.empty() ) {
		sceneStack.back()->resume();
	}
}

void System::handleEvents()
{
	// let the state handle events
	sceneStack.back()->handleEvents(this);
}

void System::update()
{
	// let the state update the game
	sceneStack.back()->update(this);
}

void System::render()
{
	// let the state render the screen
	sceneStack.back()->render(this);
}

bool System::createWindow(std::string name) {
    Window = SDL_CreateWindow("Arbore genealogic", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
		if (Window == NULL ) {
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			return 0;
		}
    return 1;
}

bool System::createRenderer() {
    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (Renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return 0;
    }
    else {
        //initialize renderer color
        SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    return 1;
}

bool System::initSDL() {
	//initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		return 0;
	}
	return 1;
}
bool System::initSDL_Image() {
    int imgFlags = IMG_INIT_PNG;
    if (!( IMG_Init( imgFlags ) & imgFlags )) {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return 0;
    }
    return 1;
}

bool System::initSDL_TTF() {
    if (TTF_Init() == -1) {
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        return 0;
    }
    return 1;
}
