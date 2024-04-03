all:
	g++ -Isrc/include -Lsrc/lib -o main *.cpp main/*.cpp entity/*.cpp math/*.cpp ui/*.cpp -lmingw32 -lSDL2main -lSDL2_ttf -lSDL2_image -lSDL2