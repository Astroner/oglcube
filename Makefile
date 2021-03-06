GLEW_INCLUDE = /opt/local/include
GLEW_LIB = /opt/local/lib

SOURCES = main.c cube/cube.c utils/utils.c shader/shader.c program/program.c

OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = ./start

build: $(OBJECTS)
	gcc -o $(EXECUTABLE) $^ -framework GLUT -w -framework OpenGL -L$(GLEW_LIB) -lGLEW

start: build
	$(EXECUTABLE)

.c.o:
	gcc -c -o $@ $< -I$(GLEW_INCLUDE)

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)