#include <genfunc.h>
#include <string.h>

void* lsearch(void* key,void* base,size_t n,size_t each){
	int i=0;
	void* addr=NULL;
	for(;i<n;i++){
		addr=(char*)base+i*each;
		if(memcmp(key,addr,each)==0)return addr;
	}
	return NULL;
}

void* lsearchx(void* key,void* base,size_t n,size_t each,cmpfunc cmp){
	int i=0;
	void* addr=NULL;
	for(;i<n;i++){
		addr=(char*)base+i*each;
		if(cmp(key,addr)==0)return addr;
	}
	return NULL;
}
