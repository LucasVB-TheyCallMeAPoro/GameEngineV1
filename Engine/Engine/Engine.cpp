#include "Engine.h"


Engine* Engine::_instance;
Engine* Engine::Instance()
{
	if (_instance == nullptr)
	{
		_instance = new Engine();
		return _instance;
	}
	else
		return _instance;
}

Engine::~Engine()
{
	//Destroy window
	SDL_DestroyWindow(_window);

	//Quit SDL subsystems
	SDL_Quit();
}

void Engine::Start()
{
	Loop();
}

void Engine::set_WindowSize(int width, int height)
{
	_screenWidth = width;
	_screenHeight = height;
}

void Engine::Init()
{
	

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		_window = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
		if (_window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(_window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0, 0, 0));

			//Update the surface
			SDL_UpdateWindowSurface(_window);

			//Hack to get window to stay up
			SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
		}
	}

}

Engine::Engine()
{
}

const void Engine::Draw()
{
	
}

void Engine::Update()
{
}

void Engine::LateUpdate()
{
}

void Engine::Debug()
{

}

void Engine::Loop()
{
	SDL_Event e;
	bool quit = false;

	while (!quit) {
		SDL_PollEvent(&e);
#if DEBUG
		Debug();
#endif
		Update();
		Draw();
		LateUpdate();
		if (e.type == SDL_QUIT)
		{
			quit = true;
		}
	}
}
