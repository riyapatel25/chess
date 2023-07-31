CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -MMD 
EXEC = chess
CCFILES = $(wildcard *.cc)
OBJECTS = ${CCFILES:.cc=.o}
DEPENDS = ${CCFILES:.cc=.d}
LIBX11_PATH = -I/opt/homebrew/Cellar/libx11/1.8.6/include -I/opt/homebrew/Cellar/libxcb/1.15_1/include -I/opt/homebrew/Cellar/libxau/1.0.11/include -I/opt/homebrew/Cellar/libxdmcp/1.1.4/include -I/opt/homebrew/Cellar/xorgproto/2023.2/include -L/opt/homebrew/Cellar/libx11/1.8.6/lib -lX11

# Set the correct path to libx11 headers and libraries
LIBX11_INCLUDE = -I${LIBX11_PATH}/include
LIBX11_LIBS = -L${LIBX11_PATH}/lib -lX11

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${LIBX11_INCLUDE} ${OBJECTS} -o ${EXEC} ${LIBX11_LIBS}

-include ${DEPENDS}

# Extra recipe that allows us to delete temporary files by saying
# make clean

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}