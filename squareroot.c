/* Custom implmentation of sqrt(). */
/* Reference: www.cs.wustl.edu/~kjg/CS101_SP97/Notes/SquareRoot/sqrt.html */
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/* To square root, we can think of the following step
 * 1. Guess a value and store in variable g
 * 2. Check if val/g is close enough to g
 * 3. Exit if true, otherwise go to 1
*/

bool closeEnough(double a,double b)
{
	return (fabs(a-b)<b*0.001);
}

double betterGuess(double x,double g)
{
	return ((g+x/g)/2);
}

double test(double x,double g)
{
	if(closeEnough(x/g,g)){
		return g;
	}
	return test(x,betterGuess(x,g));
}

double my_sqrt(double val)
{
	return test(val,1);
}

int main(void)
{
	double root=my_sqrt(4.0f);
	printf("Square root of 4 is %f\n",root);
	return 0;
}

