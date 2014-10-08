OBJS = mountain_retained.o flight.o missile.o target.o util.o
EXENAME = mp2

COMPILER = g++
WARNINGS = 
COMPILER_OPTS = -Wno-deprecated -c -g -O0 $(WARNINGS)
LINKER = g++
LDFLAGS = -framework OpenGL -framework GLUT

UNAME := $(shell uname)

all: $(EXENAME)

$(EXENAME): mountain_retained.o flight.o missile.o target.o util.o
	$(LINKER) $(OBJS) $(LDFLAGS) -o $(EXENAME)

mountain_retained.o: mountain_retained.cpp
	$(COMPILER) $(COMPILER_OPTS) mountain_retained.cpp

flight.o: flight.cpp flight.h
	$(COMPILER) $(COMPILER_OPTS) $(@:.o=.cpp)

missile.o: missile.cpp missile.h
	$(COMPILER) $(COMPILER_OPTS) $(@:.o=.cpp)

target.o: target.cpp target.h
	$(COMPILER) $(COMPILER_OPTS) $(@:.o=.cpp)

util.o: util.cpp util.h
	$(COMPILER) $(COMPILER_OPTS) $(@:.o=.cpp)

clean:
	rm -rf *.o $(EXENAME) 

