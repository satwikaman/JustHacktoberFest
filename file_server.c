#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <arpa/inet.h> 


char error_msg[] = "E";
char yes_msg[] = "L";

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[]){
	int socket_id, new_socket_id, msg_len;
	struct sockaddr_in server, client; 										//details of server and client
	socklen_t client_len;
	int portno = 8001;
	int b = 20;
	char buffer[100];														//buffer to store client message and word array reads word from the file

	socket_id = socket(AF_INET, SOCK_STREAM, 0); 							//opening a socket corresponding the the UDP protocol

	if(socket_id < 0){
		error("socket()");
	}

	bzero(&server, sizeof(server)); 										//initializing with 0s in the memory

	server.sin_family = AF_INET; 											//going to communicate over the internt
	server.sin_addr.s_addr = INADDR_ANY; 									//open to all network
	server.sin_port = htons(portno); 										//converting the port to network byte order format

	if(bind(socket_id, (struct sockaddr*) &server, sizeof(server)) < 0){
		error("bind()");
	}


	int n;
	listen(socket_id, 5);
	while(1)
	{

		new_socket_id = accept(socket_id, (struct sockaddr *) &client, &client_len);

		if(new_socket_id < 0)
			error("accept()");
		// else
		// printf("connection established\n\n");

		bzero(buffer,100);
		msg_len = recv(new_socket_id, buffer, 99, MSG_WAITALL);

		if(msg_len < 0)
			error("read");	

		// buffer[strlen(buffer)-1] = '\0';	 												//removing the newline character (\n)
		int file_fd = open(buffer, O_RDONLY); 												//opening the file in read only mode

		// if the file doesn't exist
		// send 'E'
		if(file_fd == -1)
		{
			n = send(new_socket_id, error_msg, strlen(error_msg), 0 );
			close(new_socket_id);
			close(socket_id);
			exit(0);
			return 0;
		}
		// else send 'L'
		// also send file_size
		n = send(new_socket_id, yes_msg, strlen(yes_msg), 0 );

		struct stat st;
		stat(buffer, &st);
		int file_size = st.st_size;
		// printf("\tt:%d\n", file_size );


		int tot = 100;
		char i_to_s[tot];
		sprintf(i_to_s, "%d", file_size);
		// printf("\t:%s\n", i_to_s );
		n = send(new_socket_id, i_to_s, strlen(i_to_s), 0 );

		int q,r;
		q = file_size/(b);
		r = file_size%(b);
		
		bzero(buffer, sizeof(buffer));
		while(q--)
		{
			n = read(file_fd, buffer, b);
			// buffer[b-1]='\0';
			printf("%d ",n );
			n = send(new_socket_id, buffer, b, 0 );

			printf("T:%d   %d\n", (file_size/b)-q , n );
			bzero(buffer, sizeof(buffer));
		}
		// last block
		// if(r!=0)
		// {
			n = read(file_fd, buffer, r);
			printf("%d ",n );
			n = send(new_socket_id, buffer, r, 0 );

			printf("T:%d   %d\n", (file_size/b)-q , n );
			bzero(buffer, sizeof(buffer));
			close(new_socket_id);
			close(file_fd);
		// }

	}
	close(socket_id);
	exit(0);
	return 0;
}