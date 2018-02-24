#include <genfunc.h>
#include <stdio.h>

#define LOGVAL	printf("\nValues\nstr1@%p: %s\nstr2@%p: %s\n",str1,str1,str2,str2);

int main(void){
	char str1[]="cat";
	char str2[]="dog";
	printf("Demonstration of Swap function");
	LOGVAL;
	printf("Now swapping the referenced values of pointers...");
	swap(str1,str2,4);
	LOGVAL;
	printf("Now swapping the address of pointers...");
	swap(&str1,&str2,sizeof(char*));
	LOGVAL;
	return 0;
}
