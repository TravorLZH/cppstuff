#include <string.h>
#include <genfunc.h>

void swap(void* ap,void* bp,size_t sz)
{
	char buf[sz];
	memcpy(buf,ap,sz);
	memcpy(ap,bp,sz);
	memcpy(bp,buf,sz);
}

