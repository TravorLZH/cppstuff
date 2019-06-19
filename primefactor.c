#include <stdio.h>

/* Most efficient algorithm without a prime list */
int is_prime(unsigned int num)
{
	unsigned int i;
	/* 2 is the least prime */
	for(i=2;i<num;i++)
		if(num%i==0)
			return 0;
	return 1;
}

void find_prime_factors(unsigned int num)
{
	unsigned int i;
	if(is_prime(num)){
		printf("%u",num);
	}
	for(i=2;i<num;i++){
		if(num%i==0){
			printf("%u*",i);
			find_prime_factors(num/i);
			break;
		}
	}
}

int main(int argc,char **argv)
{
	unsigned int i,num;
	if(argc<2){
		fprintf(stderr,"usage: %s number1 number2...\n",argv[0]);
		return -1;
	}
	for(i=1;i<argc;i++){
		if(!sscanf(argv[i],"%u",&num)){
			perror(argv[i]);
		}
		printf("%u",num);
		if(num==1){
			puts(" is neither prime nor composite number");
			continue;
		}
		if(is_prime(num)){
			puts(" is prime");
			continue;
		}
		putchar('=');
		find_prime_factors(num);
		putchar('\n');
	}
	return 0;
}
