//
// Created by Sanjay on 7/19/2025.
//

#include "Component.h"

Actor* Component::GetOwner() const
{
	return mOwner;
}
void Component::Update(float deltaTime)
{
	HandleUpdate(deltaTime);
}
void Component::Input(const bool keys[])
{
	HandleInput(keys);
}
void Component::HandleUpdate(float deltaTime)
{
}
void Component::HandleInput(const bool keys[])
{
}