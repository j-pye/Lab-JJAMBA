#define GLEW_STATIC
#define GLFW_INCLUDE_GLCOREARB
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "Game.h"

void error_callback(int error, const char* description);
// GLFW function declerations
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

const GLuint SCREEN_WIDTH = 800;
const GLuint SCREEN_HEIGHT = 600;

int main(int argc, char *argv[])
{
   glfwSetErrorCallback(error_callback);
   glfwInit();
   glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
   GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT,
                        "JJAMBA Lab", nullptr, nullptr);

   glfwMakeContextCurrent(window);
   glewInit();
   glGetError();
   glfwSetKeyCallback(window, key_callback);

   // OpenGL configuration
   glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

   // Initialize game
   Game::getInstance(SCREEN_WIDTH, SCREEN_HEIGHT).Init(window);

   glfwTerminate();
   return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GL_TRUE);
   if (key >= 0 && key < 1024)
   {
      if (action == GLFW_PRESS)
         Game::getInstance(SCREEN_WIDTH, SCREEN_HEIGHT).KeyPressed(key);
      else if (action == GLFW_RELEASE)
         Game::getInstance(SCREEN_WIDTH, SCREEN_HEIGHT).KeyReleased(key);
   }
}

void error_callback(int error, const char* description)
{
   fputs(description, stderr);
}
