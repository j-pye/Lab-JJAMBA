#ifndef RENDER_SPRITE_H
#define RENDER_SPRITE_H

#define GLFW_INCLUDE_GLCOREARB
#include <GL/glew.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Texture.h"
#include "Shader.h"


class RenderSprite
{
public:
   RenderSprite(Shader &shader);
   ~RenderSprite();
   void DrawSprite(Texture &texture, glm::vec2 position,
      glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f,
      glm::vec3 color = glm::vec3(1.0f));
private:
   Shader shader;
   GLuint quadVAO;
   void initRenderData();
};

#endif
