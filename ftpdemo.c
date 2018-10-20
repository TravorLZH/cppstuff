/**
 * @file	ftpdemo.c
 * @brief	Demonstration of FTP
 * @author	Travor Liu
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#ifdef	VERBOSE
#define	dprintf	printf
#else
#define	dprintf(...)	while(0)
#endif

const char server[]="ftp.gnu.org";	/* GNU FTP Server */
struct sockaddr_in hostaddr;
struct sockaddr_in daddr;	// Data address
socklen_t addr_size=sizeof(struct sockaddr_in);
int sock_ctrl;
int sock_data;
char send_buf[BUFSIZ];
char recv_buf[BUFSIZ];
struct timeval timeout={5,0};	// Set up a time out for 5 seconds

/** This function is only used for removing the welcome messages */
char remains_data(int fd)
{
	fd_set set;
	FD_ZERO(&set);
	FD_SET(fd,&set);
	int ret=select(fd+1,&set,NULL,NULL,&timeout);
	if(ret<0){
		perror("select");
		exit(-1);
	}
	return FD_ISSET(fd,&set);
}

int check_status(void)
{
	int code=0;
	memset(recv_buf,0,BUFSIZ);
	read(sock_ctrl,recv_buf,BUFSIZ);
	dprintf("%s",recv_buf);
	sscanf(recv_buf,"%d",&code);
	return code;
}

int login_anonymous(void)
{
	sprintf(send_buf,"USER %s\r\n","anonymous");
	write(sock_ctrl,send_buf,strlen(send_buf));
	read(sock_ctrl,recv_buf,BUFSIZ);
	if(check_status()!=230){
		return -1;
	}
	while(remains_data(sock_ctrl)){
		memset(recv_buf,0,BUFSIZ);
		read(sock_ctrl,recv_buf,BUFSIZ);
		dprintf("%s",recv_buf);
	}
	return 0;
}

int enter_passive(void)
{
	sprintf(send_buf,"PASV\r\n");
	write(sock_ctrl,send_buf,strlen(send_buf));
	if(check_status()!=227){
		return -1;
	}
	return 0;
}

int goodbye(void)
{
	sprintf(send_buf,"QUIT\r\n");
	write(sock_ctrl,send_buf,strlen(send_buf));
	if(check_status()==221){
		return 0;
	}
	return -1;
}

int main(void)
{
	int ret=0;
	int status=0;
	printf("Resolving `%s'\n",server);
	struct hostent *host=gethostbyname(server);
	memset(&hostaddr,0,sizeof(hostaddr));
	hostaddr.sin_family=AF_INET;
	memcpy(&hostaddr.sin_addr,host->h_addr_list[0],sizeof(struct in_addr));
	hostaddr.sin_port=htons(21);
	sock_ctrl=socket(AF_INET,SOCK_STREAM,0);
	printf("Connecting to %s...\n",inet_ntoa(hostaddr.sin_addr));
	ret=connect(sock_ctrl,(struct sockaddr*)&hostaddr,addr_size);
	if(ret!=0){
		perror("connect() failed");
		exit(1);
	}
	puts("Logging in...");
	login_anonymous();
	puts("Logged in!");
	while(enter_passive());
	while(goodbye());
	close(sock_ctrl);
	return 0;
}
