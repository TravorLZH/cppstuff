#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>

#define	NONSENSE_ADDR	"2.3.3.3"
#define	NONSENSE_PORT	13131

char buf[BUFSIZ];

int main(void)
{
	struct sockaddr_in addr;
	socklen_t size=sizeof(addr);
	int sock=socket(AF_INET,SOCK_DGRAM,0);
	memset(&addr,0,sizeof(addr));
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=inet_addr(NONSENSE_ADDR);
	addr.sin_port=NONSENSE_PORT;
	connect(sock,(struct sockaddr*)&addr,size);
	/* NOTE: I am recycling `addr' */
	getsockname(sock,(struct sockaddr*)&addr,&size);
	close(sock);
	puts(inet_ntoa(addr.sin_addr));
	return 0;
}
