all: dl main

dl:
	gcc -c -fpic returnHelloworld.c
	gcc -shared -lc -o returnHelloworld.so returnHelloworld.o

main:
	gcc -o printHelloworld printHelloworld.c -ldl
	./printHelloworld
