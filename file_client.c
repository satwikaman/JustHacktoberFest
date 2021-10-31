// Assignment 6
// Anmol Harsh
// Ayudh Saxnena

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <sys/stat.h>
#include <fcntl.h>

char err_msg[] = "ERR 01: File Not Found\n";
char prompt_msg[] = "Please enter the name of file: ";
char complete_msg[] = "The file transfer is successful. ";


void error(const char *msg)
{
	perror(msg);
	exit(0);
}

int main()
{
	int sockfd, msg_len;                                            // socket file descriptor and message length 
	int portno = 8001;
	struct sockaddr_in server; 										// details about the server
	socklen_t server_len;											// store the length of address of the server
	int b = 20;
	char buffer[100];												// buffer array to read received input

	//opening a socket corresponding the the UDP protocol 
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		perror("Failed to create socket"); 
		exit(EXIT_FAILURE); 
	}

	// initialize zero at the server
	bzero((char *) &server, sizeof(server));

	server.sin_family = AF_INET; 													//going to communicate over the internt
	server.sin_addr.s_addr = INADDR_ANY; 											//open to all network
	server.sin_port = htons(portno); 												//converting the port to network byte order format

	// establish connection with server 
	if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
		error("ERROR connecting");


	// print msg on terminal
	write(1, prompt_msg, strlen(prompt_msg));
	bzero(buffer,100);
	
	// read from terminal
	read(0, buffer, 100);
	// write(1, buffer, strlen(buffer));
	
	int n;
	// send filename to server
	n = send(sockfd, buffer, strlen(buffer), 0 );

	if (n < 0)
		error("ERROR writing to socket");

	bzero(buffer,100);
	n = recv(sockfd, buffer, 1, MSG_WAITALL);

	// if connection is closed
	if(buffer[0] == 'E')
	{
		// print error msg on terminal
		write(1, err_msg, strlen(err_msg));

		close(sockfd);
		exit(0);
		return 0;
	}
	printf("%s\n",buffer );
	int file_size;
	bzero(buffer, sizeof(buffer));
	n = recv(sockfd, buffer, sizeof(buffer), MSG_WAITALL );

	printf("\nt:%s\n", buffer);
	file_size = atoi(buffer);
	printf("tt:%d\n", file_size);
	int y = file_size%(b);

	int q = file_size/(b);
	int fd = open("received.txt", O_TRUNC|O_CREAT|O_WRONLY, 0777);
	
	while(q--)
	{
		bzero(buffer, sizeof(buffer));
		n = recv(sockfd, buffer, b, MSG_WAITALL);
		// buffer[b-1]='\0';

		// if(n<0)break;
		printf("\tT:%d  %d\n",file_size/b-q, n);
		write(fd, buffer, b);
	}
	
	// last block
	if(y!=0)
	{

		bzero(buffer, sizeof(buffer));
		n = recv(sockfd, buffer, y, MSG_WAITALL);

		// buffer[y-1]='\0';

		printf("\tT:%d\n", n);
		if(n>0)write(fd, buffer, y);

	}
	// write(1, complete_msg, strlen(complete_msg));
	printf("%s\nTotal number of blocks received = %d\nLast block size = %d\n", complete_msg, file_size/b, y );
	close(fd);
	close(sockfd);

	return 0;
}



