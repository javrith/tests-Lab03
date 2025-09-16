//
// Created by Sanjay on 7/19/2025.
//

#pragma once
#include "Transform.h"
#include "Component.h"
#include <vector>

class Actor
{
	friend class Game;

public:
	// This version allows us to modify the transform
	Transform& GetTransform();
	// This version is for cases where we don't need to modify
	const Transform& GetTransform() const;
	//Template Create Component
	template <typename T>
	T* CreateComponent()
	{
		// Create a new instance of type T, which should inherit from Component
		// It takes in "this" because every component takes an Actor* in its constructor
		T* component = new T(this);

		// Add this component to our component vector
		mComponents.emplace_back(component);

		return component;
	}
	// Returns component of type T, or nullptr if it doesn't exist
	template <typename T>
	T* GetComponent() const
	{
		// Loop over all components
		for (auto c : mComponents)
		{
			// dynamic_cast will return nullptr if c is not type T*
			T* t = dynamic_cast<T*>(c);
			if (t)
			{
				return t;
			}
		}

		return nullptr;
	}

	void Update(float deltaTime);

	void Input(const bool keys[]);

	bool IsActive();

	void SetIsActive(bool active);

	void Destroy();

protected:
	Actor() = default;
	virtual ~Actor() // Made virtual for clangtidy
	{
		for (Component* c : mComponents)
		{
			delete c;
		}
		mComponents.clear();
	}
	Transform mTransform = Transform();

	virtual void HandleUpdate(float deltaTime);

	virtual void HandleInput(const bool keys[]);

private:
	std::vector<Component*> mComponents;
	bool mIsActive = true;
};
