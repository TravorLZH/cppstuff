#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <assert.h>

typedef struct factor_pairs{
	int a;
	int b;
} factorpair_t;

inline int get_sign(int num){
	return num/abs(num);
}

/* Compaire factor pairs
 * Returns 0 if equal, positive if reverse, otherwise negative
*/
int compare_pairs(const factorpair_t a,const factorpair_t b){
	if(a.a==b.a&&a.b==b.b){
		return 0;
	}
	if(a.a==b.b&&a.b==b.a){
		return 1;
	}
	return -1;
}

void print_pairs(const factorpair_t *pairs,size_t n,const char *title){
	int i;
	for(i=0;i<n;i++){
		printf("%s: Pair: %d, %d\n",title,pairs[i].a,pairs[i].b);
	}
}

size_t fill_pairs(int num,const factorpair_t *pairs){
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

int factor(int a,int b,int c,int *x1,int *c1,int *x2,int *c2){
	int i,j,x,y;
	int d,e,f,g;
	int ax=abs(a);
	int bx=abs(b);
	int cx=abs(c);
	int sign=get_sign(b);
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
			if(c<0){
				if(abs(x-y)==bx){
					if(x>y){
						*c1=-sign*e;
						*c2=sign*g;
					}else{
						*c1=sign*e;
						*c2=-sign*g;
					}
					return 0;
				}
			}
			if(c>0){
				if(bx==x+y){
					*c1=sign*e;
					*c2=sign*g;
					return 0;
				}
			}
		}
	}
	*x1=0;
	*x2=0;
	*c1=0;
	*c2=0;
	return -1;
}

int main(int argc,char **argv){
	int a,b,c;	// Input variables
	int x1,c1,x2,c2;	// Output variables
	int i;
	printf("%s: enter coefficient for: ax^2+bx+c\n",__func__);
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("c=");
	scanf("%d",&c);
	assert(c!=0);
	printf("%s: Processing %dx^2%+dx%+d...\n",__func__,a,b,c);
	if(factor(a,b,c,&x1,&c1,&x2,&c2)){
		printf("Prime!\n");
		return;
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
