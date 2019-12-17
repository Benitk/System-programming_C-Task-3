#include <stdio.h>
#include <string.h>
#include "textfind.h"
#define true 1
#define false 0


void print_lines(char* str, char* word){
	int index = 0;
	int flag = true; // Boolean 1 true of 0 false
	int word_len = strlen(word);
	while(*(str+index) != '\n'){
		if(*(str+index) == *(word)){
			for(int k = 0; k < word_len; k++){// check if the strings are equals
				if(*(str+index+k) != *(word+k)){
					flag = false;
					break; // break for loop
				}
			}
			// break  while loop
			// if true then line contains the word
			if(flag){
				printf("%s",str);
				flag = false;
				break; // break  while loop
			}
		}
		flag = true;
		index++;
	}
}

void print_similar_words(char* str, char* word){
	int mistake = 0, index = 0, word_len = strlen(word);;
	char* p_ans;
	char ans[word_len+2];
	char* _ans = ans;
	int i = 0;
	int check = 0;
	while(*(str+index) != '\n'){ //runner/current
			p_ans = str+index; // pointer to current
			for(int k = 0;(*(p_ans+k+mistake) != ' ' && *(p_ans+k+mistake) != '\n' && *(p_ans+k+mistake) != '\t' ) && k <= word_len; k++){
				if(mistake > 1){
					break; // break for loop
				}
				else if(*(p_ans+k+mistake) != *(word+k)){// mistake 0
					*(_ans+i) = *(p_ans+k+mistake);
					i++;
					mistake++;
					k--;
				}
				else{
					*(_ans+i) = *(word+k);
					i++;
					check++;
				}
			}
			if(mistake <= 1 && check == word_len){
					*(_ans+i) = '\0';
					printf("%s\n",_ans);
					index += word_len-1; // if success no need to check those letters
			}
	   check = 0;
		mistake = 0;
		i=0;
		index++;
	}

}



