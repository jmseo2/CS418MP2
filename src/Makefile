OBJS = mountain_retained.o flight.o
EXENAME = mp2

COMPILER = g++
WARNINGS =
COMPILER_OPTS = -Wno-deprecated -c -g -O0 $(WARNINGS)
LINKER = g++
LDFLAGS = -framework OpenGL -framework GLUT

UNAME := $(shell uname)

all: $(EXENAME)

$(EXENAME): mountain_retained.o flight.o
	$(LINKER) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o: mountain_retained.cpp
	$(COMPILER) $(COMPILER_OPTS) mountain_retained.cpp

flight.o: flight.cpp flight.h
	$(COMPILER) $(COMPILER_OPTS) $(@:.o=.cpp)

clean:
	rm -rf *.o $(EXENAME) 

