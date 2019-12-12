//Ex1 (insertion sort)

#include <stdio.h>

void insertion_sort(int* arr, int len);
void shift_element(int* arr, int i);

int main(){
    int arr[] = {3,2,1,2,5,61,7};
    int len = sizeof(arr) / sizeof(int);
    insertion_sort(arr, len);
    for(int i = 0; i < 7; i++){
        printf("array index %d = %d\n",i, *(arr+i));
    }
}

void insertion_sort(int* arr, int len){
    for(int i=1; i<len; i++){
        if(*(arr+i) >= *(arr+i-1)) continue;
        int temp = *(arr+i); //the value we need to save and change it's place;
        int counter = 0; 
        for(int j=i-1; j>=0; j--){
            if(temp < *(arr+j)) counter++; 
        }
        shift_element(arr+i-counter, counter);
        *(arr+i-counter) = temp;
    }
}

void insertion_sort_ben(int* arr, int len){
    int counter;
    int temp;
    for(int i = 1; i < len; i++){
        counter = 0;
         temp = *(arr+i);
         int j = i;
        while(j > 0){
            if(*(arr+j) <= *(arr+j-1)){
                counter++;
                j--;
                continue;
            }
            break;
        }
        shift_element(arr, counter);
        *(arr+j) = temp;

    }

}

void shift_element(int* arr, int i) {
    int* p = arr+i; //pointer to the last index 
    int* p_new = arr+i+1;
    while(p > arr) {
        *(p_new) = *(p);
        p--;
        p_new--;
    }
}