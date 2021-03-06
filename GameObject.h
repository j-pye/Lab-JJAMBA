#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <GL/glew.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include "Texture.h"
#include "RenderSprite.h"


class GameObject
{
public:
   // Object state
   glm::vec2   Position, Size, Velocity;
   glm::vec3   Color;
   GLfloat     Rotation;
   GLboolean   IsSolid;

   Texture Sprite;
   // Constructor(s)
   GameObject();
   GameObject(glm::vec2 pos, glm::vec2 size,
      Texture sprite, glm::vec3 color = glm::vec3(1.0f),
      glm::vec2 velocity = glm::vec2(0.0f, 0.0f));

   // Draw sprite
   virtual void Draw(RenderSprite &renderer);
};

#endif
