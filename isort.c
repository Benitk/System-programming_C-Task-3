#include "isort.h"

void insertion_sort(int* arr, int len){
	int counter, temp, j;
	for(int i = 1; i < len; i++){
		counter = 0; // reset the counter
		// j always be one less then i at start for the if compare
		j = i-1;
		//j can be 0 because j is index and there is a value in arr[0]
		while(j >= 0){
			if(*(arr+i) <= *(arr+j)){
				// count the number of smaller values then arr[i]
				counter++;
				// keep substruct j until is less then 0 --> be -1 or if fails
				j--;
				continue;
			}
			// if arr[i] > arr[j] than break;
			break;
		}
		if(counter > 0){ // if there isnt any smaller values , there is nothing do to
			temp = *(arr+i); // save the arr[i] before shift and override it

			// send arr+j because j will be always 1 index less then what we want to shift right
		    // shift_element - shift any i as input beside the first index
			shift_element(arr+j, counter);

			// now return temp to its place in the array, in the end of every while loop j is index of one less
			// than the most left value we need to swap with so this is way its j+1.

			*(arr+j+1) = temp;
		}
	}
}

void shift_element(int* arr, int i) {
	int* p = arr + i; //pointer to the last index
	int* p_new = arr + i + 1; //pointer to the last index + 1
	while(p > arr) { // as long as pointer p is has bigger index then the first
		*(p_new) = *(p); // shift elemtents to the left
		p--;
		p_new--;
	}
}
