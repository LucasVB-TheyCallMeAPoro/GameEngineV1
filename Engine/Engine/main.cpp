#include <iostream>
#include "Engine.h"
int main(int argc, char** argv)
{

	Engine* eng = Engine::Instance();
	eng->Instance()->set_WindowSize(640, 480);
	eng->Instance()->Init();
	return 0;
}