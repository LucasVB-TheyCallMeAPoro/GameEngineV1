#pragma once
#include <vector>

#include <SDL.h>

class Engine
{
public:
	static Engine* Instance();
	~Engine();

	void Init();
	void Start();
	void set_WindowSize(int width, int height);
	
private:
	Engine();
	static Engine* _instance;

	const void Draw();
	void Update();
	void LateUpdate();
	void Debug();
	void Loop();\



	//SDL
	SDL_Window* _window = NULL;
	int _screenWidth = 0;
	int _screenHeight = 0;

};