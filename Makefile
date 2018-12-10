LDLIBS=-lglut -lGL -lGLU
all: planets
clean: 
	rm -f *.o planets
	
.PHONY: all clean 