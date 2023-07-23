CXX = g++
CXXFLAGS = -std=c++20 -Wall -Werror=vla -MMD
EXEC = cc3k
OBJECTS = main.o Blank.o Cell.o Door.o HorizontalWall.o Map.o Passage.o Room.o Stair.o VerticalWall.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
