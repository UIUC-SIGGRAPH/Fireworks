OFILES= Camera.o GL_Utils.o Fireworks.o Utils.o GL_Utils.o

all: main

main: main.cpp $(OFILES)
	g++ main.cpp $(OFILES) -o main -lGL -lGLU -lglut -Wall

Camera.o: Camera.cpp
	g++ -c Camera.cpp -o Camera.o -lGL -lGLU -lglut -Wall

Fireworks.o: Fireworks.cpp
	g++ -c Fireworks.cpp -o Fireworks.o -lGL -lGLU -lglut -Wall

GL_Utils.o: GL_Utils.cpp
	g++ -c GL_Utils.cpp -o GL_Utils.o -lGL -lGLU -lglut -Wall

Utils.o: Utils.cpp
	g++ -c Utils.cpp -o Utils.o -lGL -lGLU -lglut -Wall

clean:
	rm -rf *o *gch main