#include <regex.h>
#include <stdio.h>

int main(void)
{
	regex_t re;
	regmatch_t matches[10];
	char str[]="Travor Liu travor_lzh@outlook.com 15011964779";
	regcomp(&re,"1[0-9]{10}",REG_EXTENDED);
	printf("Demonstration of POSIX ERE");
	printf("Now matching chinese phone number from the following string:\n%s\n",str);
	regexec(&re,str,10,matches,0);
	str[matches[0].rm_eo]='\0';
	printf("Matched result: %s\n",str+matches[0].rm_so);
	return 0;
}

