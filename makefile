all: server client 

server:
	gcc file_server.c -o ser
client:
	gcc file_client.c -o cli
clean:
	rm received.txt ser cli


