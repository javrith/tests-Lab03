#pragma once

class Component
{
public:
	Component(class Actor* a)
		:mOwner(a)
	{ }
	class Actor* GetOwner() { return mOwner; }
protected:
	class Actor* mOwner;
};
