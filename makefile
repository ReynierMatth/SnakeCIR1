CFLAGS = -Wall
CLIBS = -lglut -lGL -lGLU  -lm -lX11

all: exemple 

exemple: exempleGfxLib.c fonctions.c libisentlib.a
	gcc $(CFLAGS) exempleGfxLib.c fonctions.c libisentlib.a -o exemple  $(CLIBS)


fonctions.o:	fonctions.c fonctions.h
	gcc $(CFLAGS) -c fonctions.c


clean:
	rm -f exemple
	rm -f *.o
