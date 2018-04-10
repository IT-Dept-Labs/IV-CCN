#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERV_PORT 5576

int main(int argc, char const *argv[])
{
	int i,j;
	ssize_t n;
	char filename[80],rcvline[80];
	struct sockaddr_in servaddr;

	int sockfd;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family=AF_INET;
	servaddr.sin_port=htons(SERV_PORT);
	inet_pton(AF_INET,argv[1], &servaddr.sin_addr);
	connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

	printf("Enter the  filename: \n");
	scanf("%s",filename);
	write(sockfd,filename,sizeof(filename));
	printf("Data from server: \n");

	while (read(sockfd,rcvline,80)!=0)
		fputs(rcvline,stdout);
	close(sockfd);

	return 0;
}