#include "Game.h"
#include "GameObject.h"

GameObject *Player;

Game::Game(GLuint width, GLuint height): Keys(), Width(width), Height(height)
{

}

void Game::Init(GLFWwindow* window)
{
   // DeltaTime variables
   GLfloat deltaTime = 0.0f;
   GLfloat lastFrame = 0.0f;

   while (!glfwWindowShouldClose(window))
   {
      // TIME WARP - find delta time
      GLfloat currentFrame = glfwGetTime();
      deltaTime = currentFrame - lastFrame;
      lastFrame = currentFrame;
      glfwPollEvents();


      // NOT SO WIZARD LIKE WORLD MANIPULATION
      Game::ProcessInput(deltaTime);

      // SOMETHING MIGHT BE HAPPENING
      Game::Update(deltaTime);

      // ALL YOUR RENDER ARE BELONG TO US!
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      Game::Render();

      glfwSwapBuffers(window);
   }
}

void Game::Update(GLfloat delta)
{

}


void Game::ProcessInput(GLfloat delta)
{
   GLfloat velocity = PLAYER_VELOCITY * delta;
   if (this->Keys[GLFW_KEY_A])
   {
      // Needs to be coverted to use getters and setters
      //if (Player->Position.x >= 0) Player->Position.x -= velocity;
   }
}

void Game::Render()
{

}
