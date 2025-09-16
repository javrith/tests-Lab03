//
// Created by Sanjay on 7/19/2025.
//

#include "Actor.h"
#include "Game.h"
Transform& Actor::GetTransform()
{
	return mTransform;
}
const Transform& Actor::GetTransform() const
{
	return mTransform;
}
void Actor::Update(float deltaTime)
{
	if (IsActive())
	{
		for (Component* c : mComponents)
		{
			c->Update(deltaTime);
		}
		HandleUpdate(deltaTime);
	}
}
void Actor::Input(const bool keys[])
{
	if (IsActive())
	{
		for (Component* c : mComponents)
		{
			c->Input(keys);
		}
		HandleInput(keys);
	}
}
bool Actor::IsActive()
{
	return mIsActive;
}
void Actor::SetIsActive(bool active)
{
	mIsActive = active;
}
void Actor::Destroy()
{
	SetIsActive(false);
	gGame.AddPendingDestroy(this);
}
void Actor::HandleUpdate(float deltaTime)
{
}
void Actor::HandleInput(const bool keys[])
{
}
