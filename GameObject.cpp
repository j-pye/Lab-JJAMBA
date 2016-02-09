#include "GameObject.h"


GameObject::GameObject(){}

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture sprite,
                        glm::vec3 color, glm::vec2 velocity)
                           : Position(pos), Size(size), Velocity(velocity),
                           Color(color), Rotation(0.0f), Sprite(sprite),
                           IsSolid(false) { }

void GameObject::Draw(RenderSprite &renderer)
{
   renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color);
}
