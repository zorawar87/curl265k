CC=gcc
CFLAGS=$(shell curl-config --cflags)
LIBS=$(shell curl-config --libs)

default:
	$(CC) main.c -o main $(CFLAGS) $(LIBS)

clean:
	rm -f chkspeed main

exec:
	./main 
