#pragma once
#include "Component.h"
#include "Math.h"

enum class CollSide
{
	None,
	Top,
	Bottom,
	Left,
	Right
};

class CollisionComponent : public Component
{
protected:
	CollisionComponent(class Actor* owner);
	friend class Actor;

public:
	// Set width/height of this box
	void SetSize(const Vector2& size) { mSize = size; }

	// Returns true if this box intersects with other
	bool Intersect(const CollisionComponent* other) const;

	// Get min and max points of box
	Vector2 GetMin() const;
	Vector2 GetMax() const;

	// Get center and size of box
	const Vector2& GetCenter() const;
	const Vector2& GetSize() const { return mSize; }

	// Returns side of minimum overlap against other or None if no overlap
	// Takes in by reference the offset to fix "this" so it no longer overlaps with "other"
	CollSide GetMinOverlap(const CollisionComponent* other, Vector2& offset) const;

private:
	// Size in each dimension
	Vector2 mSize;
};
