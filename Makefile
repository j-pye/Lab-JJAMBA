CC = g++
LDLIBS = -lglut -lGL -lGLU -lGLEW -lglfw -lX11 -lm -lSOIL -lfreetype -lz -lpng12
OBJ = Main.cpp \
      Game.cpp \
      GameObject.cpp \

All: $(OBJ)
	$(CC) -std=c++11 -I/usr/include/freetype2 $(OBJ)  $(LDLIBS) -o game
