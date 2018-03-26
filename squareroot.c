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

bool closeEnough(register float a,register float b){
	return (abs(a-b)<0.001f);
}

float my_sqrt(register float val){
	register float guess=1;	// Always starts with one
	while(!closeEnough(guess,val/guess)){
		guess=(guess+val/guess)/2;
	}
	return guess;
}

int main(void){
	printf("Square root of 4 is %f\n",sqrt(4.0f));
	return 0;
}
