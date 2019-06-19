#include <stdio.h>

struct{
	unsigned char a:1;
	unsigned char b:1;
	unsigned char c:4;
	unsigned char d:2;
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
