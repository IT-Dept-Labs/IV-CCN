#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#define PORT 8080
int main(int argc, char **argv)
{
	char buffer[1024],f[1024]="test";
	FILE *fp;
	fp=fopen(f,"r");
	struct sockaddr_in servAddr;
	int sockfd=socket(AF_INET,SOCK_DGRAM,0);
	servAddr.sin_family=AF_INET;
	servAddr.sin_port=htons(PORT);
	socklen_t servSize=sizeof(servAddr);
	
	int len;
	while(fgets(buffer,1024,fp)!=NULL){
		len=strlen(buffer)+1;

	sendto(sockfd,buffer,len,0,(struct sockaddr *)&servAddr,servSize);
}
fclose(fp);

}