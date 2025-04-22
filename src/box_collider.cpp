#include "box_collider.h"

BoxCollider::~BoxCollider() {}

bool BoxCollider::checkCollision(Collider* other)
{
    if (dynamic_cast<BoxCollider*>(other))
    {
        auto otherBox = dynamic_cast<BoxCollider*>(other);
        if (position.x + width > otherBox->position.x &&
            position.x < otherBox->position.x + otherBox->width &&
            position.y + height > otherBox->position.y &&
            position.y < otherBox->position.y + otherBox->height)
        {
            return true;
        }
    }
    return false;
}

std::optional<Vec2> BoxCollider::getContactPoint(Vec2 movement, Collider* other)
{
    if (dynamic_cast<BoxCollider*>(other))
    {
        auto otherBox = dynamic_cast<BoxCollider*>(other);
        if (checkCollision(other))
        {
            float nextX = position.x + movement.x;
            float nextY = position.y + movement.y;
            Vec2 result = Vec2(nextX, nextY);

            if (movement.x > 0)
            {
                if (nextX + width > otherBox->position.x &&
                    position.x <= otherBox->position.x + otherBox->width)
                {
                    result.x = otherBox->position.x - width - 0.01f;
                }
            }
            else if (movement.x < 0)
            {
                if (nextX < otherBox->position.x + otherBox->width &&
                    position.x + width >= otherBox->position.x)
                {
                    result.x = otherBox->position.x + otherBox->width + 0.01f;
                }
            }

            if (movement.y > 0)
            {
                if (nextY + height > otherBox->position.y &&
                    position.y <= otherBox->position.y + otherBox->height)
                {
                    result.y = otherBox->position.y - height - 0.01f;
                }
            }
            else if (movement.y < 0)
            {
                if (nextY < otherBox->position.y + otherBox->height &&
                    position.y + height >= otherBox->position.y)
                {
                    result.y = otherBox->position.y + otherBox->height + 0.01f;
                }
            }

            return result;
        }
    }
    return std::nullopt;
}
