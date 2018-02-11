CC=gcc

default:
	$(CC) main.c -o main -I/usr/local/include -L/usr/local/lib -lcurl

clean:
	rm -f chkspeed main

exec:
	./main 
