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

char buf[BUFSIZ];

int main(void)
{
	struct hostent *hptr=NULL;
	char **ptr=NULL;
	gethostname(buf,BUFSIZ);
	hptr=gethostbyname(buf);
	assert(hptr!=NULL);
	switch(hptr->h_addrtype)
	{
	case AF_INET:
		ptr=hptr->h_addr_list;
		for(;*ptr!=NULL;ptr++){
			printf("%s\n",inet_ntop(hptr->h_addrtype,*ptr,buf,
						sizeof(buf)));
		}
		printf("Preferred: %s\n",inet_ntop(hptr->h_addrtype,
					hptr->h_addr,buf,sizeof(buf)));
		break;
	default:
		printf("Unknown address type\n");
		break;
	}
	return 0;
}
