#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

typedef struct factor_pairs{
	int a;
	int b;
} factorpair_t;

size_t fill_pairs(int num,const factorpair_t *pairs)
{
	assert(num>0);
	int i;
	factorpair_t *p=(factorpair_t*)pairs;
	for(i=1;i<=num;i++){
		if(num%i)continue;
		p->a=i;
		p->b=num/i;
		p++;
	}
	return p-pairs;
}

int factor(int a,int b,int c,int *x1,int *c1,int *x2,int *c2)
{
	int i,j,x,y;
	int d,e,f,g;
	int ax=abs(a);
	int bx=abs(b);
	int cx=abs(c);
	int sign=b/bx;
	factorpair_t ap[ax];
	factorpair_t cp[cx];
	size_t na=fill_pairs(ax,ap);
	size_t nc=fill_pairs(cx,cp);
	for(i=0;i<na;i++){
		d=ap[i].a;
		f=ap[i].b;
		for(j=0;j<nc;j++){
			e=cp[j].a;
			g=cp[j].b;
			x=d*g;	// Outer
			y=e*f;	// Inner
			*x1=d;
			*x2=f;
			if(c<0&&bx==abs(x-y)){
				sign*=x>y?1:-1;
				*c1=-sign*e;
				*c2=sign*g;
				return 0;
			}
			if(c>0&&bx==x+y){
				*c1=sign*e;
				*c2=sign*g;
				return 0;
			}
		}
	}
	*x1=0;
	*x2=0;
	*c1=0;
	*c2=0;
	return -1;
}

int main(int argc,char **argv)
{
	int a,b,c;	// Input variables
	char neg=0;	// Is a negative?
	int x1,c1,x2,c2;	// Output variables
	int i;
	if(argc<4){
		fprintf(stderr,"usage: %s a b c\n",argv[0]);
		fprintf(stderr,"a,b,c as the parameters of:\n");
		fprintf(stderr,"\tax^2+bx+c\n");
		return -1;
	}else{
		a=atoi(argv[1]);
		b=atoi(argv[2]);
		c=atoi(argv[3]);
		if(c==0){
			fprintf(stderr,"error: c cannot be zero\n");
			return -1;
		}
	}
	if(a<0){
		neg=1;
		a=-a;
		b=-b;
		c=-c;
	}
	printf("%s: Processing %dx^2%+dx%+d...\n",argv[0],a,b,c);
	if(factor(a,b,c,&x1,&c1,&x2,&c2)){
		printf("Prime!\n");
		return 1;
	}
	if(neg){
		putchar('-');
	}
	if(x1==1){
		printf("(x%+d)",c1);
	}else{
		printf("(%dx%+d)",x1,c1);
	}
	if(x2==1){
		printf("(x%+d)\n",c2);
	}else{
		printf("(%dx%+d)\n",x2,c2);
	}
	return 0;
}
