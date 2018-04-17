#include <genfunc.h>
#include <stdio.h>

typedef struct{
	char name[10];
	int age;
} person_t;

int cmp_age(void* p1,void* p2)
{
	person_t* pa=p1;
	person_t* pb=p2;
	return pa->age-pb->age;
}

int main(void)
{
	person_t people[]={{"John",15},{"Percy",16},{"Travor",13},{"Eric",20}};
	person_t key={"Whatever",13};
	printf("Searching person matching age: %d\n",key.age);
	person_t *p=lsearchx(&key,people,4,sizeof(person_t),&cmp_age);
	printf("Matched person: %s\n",p->name);
	return 0;
}
