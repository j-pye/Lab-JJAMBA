#ifndef ASSET_CONTROLLER_H
#define ASSET_CONTROLLER_H

#include <map>
#include <string>
#include <GL/glew.h>
#include "Texture.h"
#include "Shader.h"

class AssetController
{
public:
   // Resource storage
   static std::map<std::string, Shader> Shaders;
   static std::map<std::string, Texture> Textures;
   static Shader   LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);
   static Shader   GetShader(std::string name);
   static Texture LoadTexture(const GLchar *file, GLboolean alpha, std::string name);
   static Texture GetTexture(std::string name);
private:
   AssetController() { }
   // Loads and generates a shader from file
   static Shader loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);
   // Loads a single texture from file (SOIL)
   static Texture loadTextureFromFile(const GLchar *file, GLboolean alpha);
};

#endif
