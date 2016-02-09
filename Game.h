#ifndef GAME_H
#define GAME_H

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

const glm::vec2 OBJECT_SIZE(99, 87);
const GLfloat OBJECT_VELOCITY(500.0f);

class Game {
   private:
      GLboolean Keys[1024];
      GLboolean KeysProcessed[1024];
      GLuint Width, Height;
      Game() {}
      Game(GLuint width, GLuint height);
   public:
      static Game& getInstance(GLuint width, GLuint height) {
         static Game instance = Game(width, height);

         return instance;
      }
      void Init(GLFWwindow* window);
      void ProcessInput(GLfloat delta);
      void Update(GLfloat delta);
      void Render();
      void KeyPressed(int key);
      void KeyReleased(int key);
};

#endif
