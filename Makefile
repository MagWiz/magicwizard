CPP=g++
SFMLLIB="-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio"
INCLUDEDIR=SFML-2.0/include/
LIBDIR=SFML-2.0/lib/
CPPFLAGS= -std=c++0x -Wall
SRC=src
SFMLFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SFML_LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
CUSTOMFLAGS=-O4

BUILDS=${SRC}/magicsprite.o ${SRC}/helpers.o  ${SRC}/audio.o ${SRC}/tile.o ${SRC}/home.o ${SRC}/hud.o ${SRC}/character.o ${SRC}/background.o ${SRC}/videoeffect.o ${SRC}/bloomeffect.o  ${SRC}/game.o  ${SRC}/main.o 
SOURCES=${SRT}/magicsprite.cpp ${SRC}/helpers.cpp ${SRC}/audio.cpp ${SRC}/tile.cpp ${SRC}/home.cpp ${SRC}/hud.cpp ${SRC}/character.cpp ${SRC}/background.cpp ${SRC}/videoeffect.o  ${SRC}/bloomeffect.o  ${SRC}/game.cpp ${SRC}/main.cpp

all: mw

src/magicsprite.o: src/magicsprite.cpp src/magicsprite.h src/enums.h
	${CPP} ${CPPFLAGS} ${CUSTOMFLAGS} -c ${SRC}/magicsprite.cpp -o ${SRC}/magicsprite.o ${SFML_LIBS}

src/helpers.o: src/helpers.cpp src/helpers.h
	${CPP} ${CPPFLAGS} ${CUSTOMFLAGS} -c ${SRC}/helpers.cpp -o ${SRC}/helpers.o ${SFML_LIBS}
	
src/audio.o: src/audio.cpp src/audio.h
	${CPP} ${CPPFLAGS} ${CUSTOMFLAGS} -c ${SRC}/audio.cpp -o ${SRC}/audio.o ${SFML_LIBS}

src/home.o: src/home.cpp src/home.h
	${CPP} ${CPPFLAGS} ${CUSTOMFLAGS} -c ${SRC}/home.cpp -o ${SRC}/home.o ${SFML_LIBS}

src/hud.o: src/hud.cpp src/hud.h src/enums.h
	${CPP} ${CPPFLAGS} ${CUSTOMFLAGS} -c ${SRC}/hud.cpp -o ${SRC}/hud.o ${SFML_LIBS}

src/tile.o: src/tile.cpp src/tile.h src/enums.h
	${CPP} ${CPPFLAGS} ${CUSTOMFLAGS} -c ${SRC}/tile.cpp -o ${SRC}/tile.o ${SFML_LIBS}

src/background.o: src/background.cpp src/background.h src/enums.h
	${CPP} ${CPPFLAGS} ${CUSTOMFLAGS} -c ${SRC}/background.cpp -o ${SRC}/background.o ${SFML_LIBS}

src/videoeffect.o: src/videoeffect.cpp src/videoeffect.h
	${CPP} ${CPPFLAGS} ${CUSTOMFLAGS} -c ${SRC}/videoeffect.cpp -o ${SRC}/videoeffect.o ${SFML_LIBS}
	

src/bloomeffect.o: src/bloomeffect.cpp src/bloomeffect.h
	${CPP} ${CPPFLAGS} ${CUSTOMFLAGS} -c ${SRC}/bloomeffect.cpp -o ${SRC}/bloomeffect.o ${SFML_LIBS}
	
src/character.o: src/character.cpp src/character.h src/enums.h
	${CPP} ${CPPFLAGS} ${CUSTOMFLAGS} -c ${SRC}/character.cpp -o ${SRC}/character.o ${SFML_LIBS}

src/game.o: src/game.cpp src/game.h src/enums.h
	${CPP} ${CPPFLAGS} ${CUSTOMFLAGS} -c ${SRC}/game.cpp -o ${SRC}/game.o ${SFML_LIBS}


src/main.o: src/main.cpp src/game.o
	${CPP} ${CPPFLAGS} ${CUSTOMFLAGS} -c ${SRC}/main.cpp -o ${SRC}/main.o ${SFML_LIBS}

a.out:
	${CPP}  ${SRC}/audio.cpp ${SRC}/tile.cpp ${SRC}/home.cpp ${SRC}/hud.cpp ${SRC}/character.cpp ${SRC}/background.cpp ${SRC}/main.cpp  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -O4  ${CPPFLAGS} 

mw: ${BUILDS}
	${CPP} ${CPPFLAGS} ${CUSTOMFLAGS} ${BUILDS} ${SFML_LIBS} -o mw

clean:
	rm -rf mw  src/*.o
