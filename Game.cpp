#include "Game.h"
#include "GameObject.h"
#include "AssetController.h"
#include "RenderSprite.h"

RenderSprite *Renderer;
GameObject *Obj1;

Game::Game(GLuint width, GLuint height): Keys(), Width(width), Height(height)
{

}

/*###############################################/
 * Add code to Load a Texture for Background image.
 *###############################################*/
void Game::Init(GLFWwindow* window)
{

   // Load shaders
   AssetController::LoadShader("shaders/sprite.vs", "shaders/sprite.frag", nullptr, "sprite");
   // Configure shaders
   glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width), static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
   AssetController::GetShader("sprite").Use().SetInteger("image", 0);
   AssetController::GetShader("sprite").SetMatrix4("projection", projection);

   // Load textures
   AssetController::LoadTexture("textures/ship.png", GL_TRUE, "ship");
    // Set render-specific controls
   Shader myShader = AssetController::GetShader("sprite");
   Renderer = new RenderSprite(myShader);

   glm::vec2 objectPos = glm::vec2(
         this->Width / 2 - OBJECT_SIZE.x / 2, // Middle
         this->Height - OBJECT_SIZE.y); // Bottom
   Obj1 = new GameObject(objectPos, OBJECT_SIZE, AssetController::GetTexture("ship"));


   // Initialize Frames and deltaTime before main loop
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

/*###############################################/
 * Add code to Move ship / object up,
 *    down, left and right.
 *###############################################*/
void Game::ProcessInput(GLfloat delta)
{
   GLfloat velocity = OBJECT_VELOCITY * delta;
   if (this->Keys[GLFW_KEY_A])
   {
      // Did not get the chance to change game objects to have getter/setter for this
      // Press A to move Left.
      if (Obj1->Position.x >= 0) Obj1->Position.x -= velocity;
   }
}

/*###############################################/
 * Add Code to Render a Background image
 *###############################################*/
void Game::Render()
{
   Obj1->Draw(*Renderer);
}

void Game::KeyPressed(int key)
{
   Keys[key] = GL_TRUE;
   printf("Key Pressed\n");
}

void Game::KeyReleased(int key)
{
   Keys[key] = GL_FALSE;
   KeysProcessed[key] = GL_FALSE;
   printf("Key Released\n");
}
