#pragma once
#include <vector>
class AGameObject
{
public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void LateUpdate() = 0;
protected:
	//Sprite* _sprite;
	//std::vector<Component> _components;
	//Transform* _transform;
};