#include <cpuid.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define	MOV_TO_TMP(n)	memcpy(tmp,&where[n],sizeof(uint32_t))

int main(void)
{
	char tmp[5]={0,0,0,0,0};
	uint32_t where[4]={0,0,0,0};
	printf("CPU Information\n");
	printf("Vendor: ");
	cpuid_string(CPUID_VENDORSTRING,where);
	MOV_TO_TMP(1);
	printf("%s",tmp);
	MOV_TO_TMP(3);
	printf("%s",tmp);
	MOV_TO_TMP(2);
	printf("%s",tmp);
	putchar('\n');
	memset(tmp,0,5);
	printf("Brand: ");
	cpuid_string(CPUID_INTELBRANDSTRING,where);
	printf("%s",(char*)where);
	cpuid_string(CPUID_INTELBRANDSTRINGMORE,where);
	printf("%s",(char*)where);
	cpuid_string(CPUID_INTELBRANDSTRINGEND,where);
	printf("%s",(char*)where);
	putchar('\n');
	return 0;
}
