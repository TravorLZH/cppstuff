#include <stdio.h>

struct{
	char a:1;
	char b:1;
	char c:4;
	char d:2;
} bitfield;

int main(int argc,char **argv)
{
	bitfield.a=1;
	bitfield.b=0;
	bitfield.c=0x09;	// Binary: 1001
	bitfield.d=0;
	char x=*(char*)&bitfield;
	printf("bitfield: 0x%x\n",x);
	return 0;
}
