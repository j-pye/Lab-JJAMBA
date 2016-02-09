CC=g++
CFLAGS=-c -O3 -std=c++11
LDFLAGS= -lglut -lGL -lGLU -lGLEW -lglfw -lX11 -lm -lSOIL
SOURCES= Main.cpp Game.cpp GameObject.cpp Shader.cpp AssetController.cpp RenderSprite.cpp Texture.cpp
SRCOBJ= Main.cpp Game.cpp GameObject.cpp
OBJDIR=objects
OBJECTS=$(SRCOBJ:.cpp=.o)
OBJCOMP=$(addprefix objects/,$(SOURCES:.cpp=.o))
EXECUTABLE=game

all: $(SRCOBJ) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJCOMP) -o $@

.cpp.o:
	 $(CC) $(CFLAGS) $< -o $(OBJDIR)/$@

clean:
	-@rm objects/Main.o objects/Game.o objects/GameObject.o game 2>/dev/null || true
