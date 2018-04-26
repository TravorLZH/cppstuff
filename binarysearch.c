#include <stdio.h>
#include <stdint.h>

int binary_search(int key,int arr[],int n)
{
	register int start=0;
	register int end=n-1;
	int i=0;
	if(arr[n-1]==key){
		printf("%s: Found %d at arr[%d]\n",__func__,key,n);
		return n;
	}
	register int backup=arr[n-1];
	arr[n-1]=key;
	for(i;;i++){
		if(arr[i]==key){
			if(i<n-1){
				printf("%s: Found %d at arr[%d]\n",__func__,key,n);
				if(i<n-1){
					return i;
				}
				return -1;
			}
		}
	}
	return -1;
}

int main(void)
{
	int arr[]={3,5,6,4,7,10,9};
	binary_search(10,arr,7);
	return 0;
}

