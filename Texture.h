#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

class Texture
{
public:
   // ID used by all texture functions to id the texture being used / manipulated.
   GLuint ID;
   GLuint Width, Height; // Width and height of loaded image in pixels
   GLuint Internal_Format; // Format of texture object
   GLuint Image_Format; // Format of loaded image -Supports any SOIL format.
   // Texture configuration - Wrapping on S and T axis
   GLuint Wrap_S;
   GLuint Wrap_T;
   GLuint Filter_Min; // Filtering mode if texture pixels < screen pixels
   GLuint Filter_Max; // Filtering mode if texture pixels > screen pixels
   // Constructor (sets default texture modes)
   Texture();
   // Generates texture from image data
   void Generate(GLuint width, GLuint height, unsigned char* data);
   // Binds the texture as the current active GL_TEXTURE_2D texture object
   void Bind() const;
};

#endif
