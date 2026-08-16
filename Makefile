my_Preprocessor: main.o comment.o include.o macro.o
	cc main.o comment.o include.o macro.o -o my_Preprocessor

main.o: main.c comment.h include.h macro.h
	cc -c main.c

comment.o: comment.c comment.h
	cc -c comment.c

include.o: include.c include.h
	cc -c include.c

macro.o: macro.c macro.h common.h
	cc -c macro.c

clean:
	rm -f *.o my_Preprocessor
