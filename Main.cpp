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
   glewExperimental = GL_TRUE;
   glewInit();
   glGetError();
   glfwSetKeyCallback(window, key_callback);

   // OpenGL configuration
   glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
   glEnable(GL_CULL_FACE);
   glEnable(GL_BLEND);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


   // Initialize game
   Game::getInstance(SCREEN_WIDTH, SCREEN_HEIGHT).Init(window);

   glfwTerminate();
   return 0;
}

/*###########################################################
 * TODO: 
 * Algorithm for key_callback routine we will use to
 *   pass control to the game singleton:
 *   Check if int key is in range (0-1024)
 *   If action is GLFW_PRESS,
 *      then set Keys[key] using Game.KeyPressed(key)
 *   else if action is GLFW_RELEASE,
 *     then set Keys[key] using Game.KeyReleased(key)
 *
 * After control is set in the Game singleton,
 *   you can use the currently pressed key data in the
 *   processInput function.
 *##########################################################*/
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
      glfwSetWindowShouldClose(window, GL_TRUE);
}

void error_callback(int error, const char* description)
{
   fputs(description, stderr);
}
