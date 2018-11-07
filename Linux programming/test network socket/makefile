all: server1.exe client1.exe

server1.exe: server1.o
	 gcc -o server1.exe server1.o

client1.exe: client1.o
	gcc -o client1.exe client1.o

server1.o: server1.c
	gcc -c  server1.c
client1.o: client1.c
	gcc -c client1.c
clean:
	 rm server1.exe server1.o client1.exe client1.o