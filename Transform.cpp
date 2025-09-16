//
// Created by Sanjay on 7/19/2025.
//

#include "Transform.h"

const Vector2& Transform::GetPosition() const
{
	return mPosition;
}
float Transform::GetRotation() const
{
	return mRotation;
}
float Transform::GetScale() const
{
	return mScale;
}

void Transform::SetPosition(const Vector2& position)
{
	mPosition = position;
}
void Transform::SetRotation(float rotation)
{
	mRotation = rotation;
}
void Transform::SetScale(float scale)
{
	mScale = scale;
}
Vector2 Transform::GetForward() const
{
	//Braced from ClangTidy
	//If doesn't work, convert to radians But I think mRotation is already radians?
	return {Math::Cos(mRotation), -Math::Sin(mRotation)};
}
