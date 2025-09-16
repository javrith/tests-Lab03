//
// Created by Sanjay on 7/19/2025.
//

#pragma once
#include "Math.h"
#include "SDL3/SDL_rect.h"

class Transform
{
public:
	const Vector2& GetPosition() const;
	float GetRotation() const;
	float GetScale() const;

	void SetPosition(const Vector2& position);
	void SetRotation(float rotation);
	void SetScale(float scale);

	Vector2 GetForward() const;

private:
	Vector2 mPosition = Vector2();
	float mRotation = 0; // In Radians
	float mScale = 1;
};
