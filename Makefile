all: ./bin/suikacons ./bin/suikasdl

doc: doc/doxyfile
	doxygen doc/doxyfile

./bin/suikacons: ./obj/mainConsole.o ./obj/Fruit.o ./obj/Plateau.o ./obj/Vec2.o ./obj/Jeu.o ./obj/JeuModeConsole.o
	g++ -g -Wall ./obj/mainConsole.o ./obj/Fruit.o ./obj/Plateau.o ./obj/Vec2.o ./obj/Jeu.o ./obj/JeuModeConsole.o -o ./bin/suikacons 

./bin/suikasdl: ./obj/mainSDL.o ./obj/Fruit.o ./obj/Plateau.o ./obj/Vec2.o ./obj/Jeu.o ./obj/JeuSDL.o ./obj/Sprite.o ./obj/MenuSDL.o
	g++ -g -Wall ./obj/mainSDL.o ./obj/Fruit.o ./obj/Plateau.o ./obj/Vec2.o ./obj/Jeu.o ./obj/JeuSDL.o ./obj/Sprite.o ./obj/MenuSDL.o -o ./bin/suikasdl -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
		
./obj/mainSDL.o: ./src/sdl/mainSDL.cpp ./src/sdl/JeuSDL.h ./src/core/Fruit.h ./src/core/Plateau.h ./src/core/Jeu.h ./src/core/Vec2.h ./src/sdl/Sprite.h ./src/sdl/MenuSDL.h
	g++ -g -Wall -c ./src/sdl/mainSDL.cpp -o ./obj/mainSDL.o -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
		
./obj/mainConsole.o: ./src/console/mainConsole.cpp ./src/console/JeuModeConsole.h ./src/core/Jeu.h ./src/core/Fruit.h ./src/core/Plateau.h ./src/core/Vec2.h
	g++ -g -Wall -c ./src/console/mainConsole.cpp -o ./obj/mainConsole.o
	
./obj/JeuSDL.o: ./src/sdl/JeuSDL.cpp ./src/sdl/JeuSDL.h ./src/core/Fruit.h ./src/core/Plateau.h ./src/core/Jeu.h ./src/core/Vec2.h ./src/sdl/Sprite.h ./src/sdl/MenuSDL.h
	g++ -g -Wall -c ./src/sdl/JeuSDL.cpp -o ./obj/JeuSDL.o -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

./obj/MenuSDL.o: ./src/sdl/MenuSDL.h ./src/sdl/MenuSDL.cpp 
	g++ -g -Wall -c ./src/sdl/MenuSDL.cpp -o ./obj/MenuSDL.o -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

./obj/Sprite.o: ./src/sdl/Sprite.h ./src/sdl/Sprite.cpp
	g++ -g -Wall -c ./src/sdl/Sprite.cpp -o ./obj/Sprite.o -lSDL2 -lSDL2_ttf -lSDL2_image

./obj/JeuModeConsole.o: ./src/console/JeuModeConsole.cpp ./src/console/JeuModeConsole.h ./src/core/Jeu.h ./src/core/Fruit.h ./src/core/Plateau.h ./src/core/Vec2.h
	g++ -g -Wall -c ./src/console/JeuModeConsole.cpp -o ./obj/JeuModeConsole.o

./obj/Jeu.o: ./src/core/Jeu.cpp ./src/core/Jeu.h ./src/core/Fruit.h ./src/core/Plateau.h ./src/core/Vec2.h
	g++ -g -Wall -c src/core/Jeu.cpp -o ./obj/Jeu.o

./obj/Plateau.o: ./src/core/Plateau.cpp ./src/core/Plateau.h ./src/core/Fruit.h ./src/core/Vec2.h
	g++ -g -Wall -c src/core/Plateau.cpp -o ./obj/Plateau.o
		
./obj/Fruit.o: ./src/core/Fruit.cpp ./src/core/Fruit.h ./src/core/Vec2.h
	g++ -g -Wall -c src/core/Fruit.cpp -o ./obj/Fruit.o

./obj/Vec2.o: ./src/core/Vec2.cpp ./src/core/Vec2.h
	g++ -g -Wall -c ./src/core/Vec2.cpp -o ./obj/Vec2.o 

clean:
	rm obj/*.o
veryclean:
	rm ./bin/suika*
