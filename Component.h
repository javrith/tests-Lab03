#pragma once

class Component
{
public:
	Component(class Actor* a)
		:mOwner(a)
	{ }
protected:
	class Actor* mOwner;
};
