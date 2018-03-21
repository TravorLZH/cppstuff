#include <stdio.h>

struct{
	unsigned char byte;
	unsigned short word;
} deflt;

struct{
	unsigned char byte;
	unsigned short word;
} __attribute__((packed)) packed;

int main(int argc,char **argv){
	deflt.byte=0xAA;
	deflt.word=0xDDDD;
	unsigned long long val=*(unsigned long long*)&deflt;
	printf("deflt: 0x%llX\n",val);
	packed.byte=0xAA;
	packed.word=0xDDDD;
	val=*(unsigned long long*)&packed;
	printf("packed: 0x%llX\n",val);
	return 0;
}
