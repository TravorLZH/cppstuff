#include <genfunc.h>
#include <stdio.h>

int main(void){
	char key[]="cat";
	char arr[][4]={"abc","def","car","xyz","cat","uno","dad"};
	char* addr=lsearch(key,arr,7,sizeof(key));
	printf("Seached value: %s\n",addr);
}
