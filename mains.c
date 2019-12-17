#include <stdio.h>
#include "isort.h"
#define MAX_SIZE 50


int main(){
	int arr[MAX_SIZE], index = 0, num;
	while(scanf("%d", &num) == 1 && index < MAX_SIZE){// getting user input up to 50 numbers
		*(arr+index) = num;
		index++;
	}
	int len = sizeof(arr) / sizeof(int);
	insertion_sort(arr, len); // sort
	for(int i = 0; i < len; i++){
		if(i == len -1 ){
			printf("%d", *(arr+i)); // last number shouldnt end with comma
		}
		else{
			printf("%d,", *(arr+i));
		}
	}
}
