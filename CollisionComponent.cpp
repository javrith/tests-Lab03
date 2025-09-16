#include "CollisionComponent.h"
#include "Actor.h"

CollisionComponent::CollisionComponent(class Actor* owner)
: Component(owner)
{
}

bool CollisionComponent::Intersect(const CollisionComponent* other) const
{

	//Not Left, not right, not lower than, not above
	bool noIntersection = GetMax().x < other->GetMin().x || other->GetMax().x < GetMin().x ||
						  GetMax().y < other->GetMin().y || other->GetMax().y < GetMin().y;

	//If all above is true, it will return false, which means there is no intersection
	//Therefore, negate what is returned:
	return !noIntersection;
}

Vector2 CollisionComponent::GetMin() const
{
	//Min: Top left corner
	Vector2 min;
	Vector2 ownerPosition = mOwner->GetTransform().GetPosition();
	float ownerScale = mOwner->GetTransform().GetScale();
	min.x = ownerPosition.x - (mSize.x * ownerScale) / 2.0f;
	min.y = ownerPosition.y - (mSize.y * ownerScale) / 2.0f;
	return min;
}

Vector2 CollisionComponent::GetMax() const
{
	//Max: Bottom right corner
	Vector2 max;
	Vector2 ownerPosition = mOwner->GetTransform().GetPosition();
	float ownerScale = mOwner->GetTransform().GetScale();
	max.x = ownerPosition.x + (mSize.x * ownerScale) / 2.0f;
	max.y = ownerPosition.y + (mSize.y * ownerScale) / 2.0f;
	return max;
}

const Vector2& CollisionComponent::GetCenter() const
{
	return mOwner->GetTransform().GetPosition();
}

CollSide CollisionComponent::GetMinOverlap(const CollisionComponent* other, Vector2& offset) const
{
	offset = Vector2::Zero;
	//Other = Block
	//This = Frog
	//Return none if does not intersect
	if (!Intersect(other))
	{
		return CollSide::None;
	}
	else // Does intersect
	{
		// Top Dist: Top of block minus bottom of player
		float topDist = other->GetMin().y - GetMax().y;
		// Bottom Dist
		float bottomDist = other->GetMax().y - GetMin().y;
		// Right Dist
		float rightDist = other->GetMax().x - GetMin().x;
		// Left Dist
		float leftDist = other->GetMin().x - GetMax().x;

		// Find Minimum
		float minimumDist =
			Math::Abs(Math::Min(Math::Min(topDist, bottomDist), Math::Min(rightDist, leftDist)));
		//Would do switch case here but I don't think you can with floats
		//Possibly todo: test if NearlyEqual is necessary?
		if (Math::NearlyEqual(minimumDist, topDist))
		{
			offset.y = minimumDist;
			return CollSide::Top;
		}
		else if (Math::NearlyEqual(minimumDist, bottomDist))
		{
			offset.y = minimumDist;
			return CollSide::Bottom;
		}
		else if (Math::NearlyEqual(minimumDist, rightDist))
		{
			offset.x = minimumDist;
			return CollSide::Right;
		}
		else // Left
		{
			offset.x = minimumDist;
			return CollSide::Left;
		}
	}
}
