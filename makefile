CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -MMD
EXEC = chess
CCFILES = $(wildcard *.cc) $(wildcard */*.cc)
OBJECTS = ${CCFILES:.cc=.o}
DEPENDS = ${CCFILES:.cc=.d}
X11FLAGS = -I/opt/X11/include
X11LIBS = -L/opt/X11/lib -lX11

${EXEC}: ${OBJECTS}
	${CXX} ${X11FLAGS} ${OBJECTS} ${X11LIBS} -o ${EXEC}

-include ${DEPENDS}

# Extra recipe that allows us to delete temporary files by saying
# make clean

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
