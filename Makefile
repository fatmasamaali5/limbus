prog:main.o minimap.o
	gcc main.o minimap.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer
main.o:main.c
	gcc main.c -c
minimap.o:minimap.c
	gcc minimap.c -c
