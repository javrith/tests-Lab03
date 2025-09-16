//
// Created by Sanjay on 7/19/2025.
//

#pragma once
class Actor;
class Component
{
	friend class Actor;

public:
	Actor* GetOwner() const;
	void Update(float deltaTime);

	void Input(const bool keys[]);

protected:
	Actor* mOwner = nullptr;
	Component(Actor* owner) { mOwner = owner; }
	//Clang-tidy added = default
	virtual ~Component() = default;
	virtual void HandleUpdate(float deltaTime);

	virtual void HandleInput(const bool keys[]);
};
