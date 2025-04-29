#include "box_collider.h"

BoxCollider::~BoxCollider() {}

CollisionResult* BoxCollider::checkCollision(GameObject* other, Vec2 movement)
{
   auto result = new CollisionResult();
   result->hit = false;
   result->normal = Vec2(0, 0);
   result->point = Vec2(0, 0);
   result->distance = 0;
   result->object = other;

   if (other->getCollider == nullptr ){
       return result;
   }
   BoxCollide* otherBox = dynamic_cast<BoxCollider*> other->getCollider();
   if (otherBox){
      if (movement.x > 1){
         //namiesto usecky ako strany spravim ray cast
         float ax = position.x + width + movement.x;
         float ay = position.y + movement.y; 
         float bx = position.x + width + movement.x;
         float by = position.y + height + movement.y;

         float cx = otherBox->position.x;
         float cy = otherBox->position.y;
         float dx = otherBox->position.x;
         float dy = otherBox->position.y + otherBox->height;
         
  






      }else if (movement.x < -1){

      }

      if (movement.y > 1){

      }else if (movement.y < -1){
         
      }
      

   }

   return result;
}
