#include <stdio.h>
#include <string.h>
#include "textfind.h"
#define true 1
#define false 0


void print_lines(char* str, char* word){
	int index = 0;
	int flag = true; // Boolean 1 true of 0 false
	int word_len = strlen(word);
	// runner on the lines until \n
	while(*(str+index) != '\n'){
		// if found in the line the same first letter as word, continue check for equality
		if(*(str+index) == *(word)){
			for(int k = 0; k < word_len; k++){// check if the strings are equals
				if(*(str+index+k) != *(word+k)){
					flag = false;
					break; // break for loop
				}
			}
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
	int mistake = 0, index = 0, word_len = strlen(word);
	char* p_str; // pointer to str to make it shorter for every index increment
	char ans[word_len+2]; // will save the similar word + 1 mistake + '\0'
	char* _ans = ans; // pointer to ans
	int i = 0; // _ans index
	int check = 0; // make sure that the similar word has char as word
	while(*(str+index) != '\n'){ // while not finish run on the line
			p_str = str+index;
			//loop on similir word until you get ' ' or '\n' or '\t' and check mistakes
			for(int k = 0;(*(p_str+k+mistake) != ' ' && *(p_str+k+mistake) != '\n' && *(p_str+k+mistake) != '\t' ) && k <= word_len; k++){
				if(mistake > 1){
					break; // break for loop
				}
				// add the mistake and subtract the k index for not losing letter
				else if(*(p_str+k+mistake) != *(word+k)){// mistake 0
					*(_ans+i) = *(p_str+k+mistake);
					i++;
					mistake++;
					k--;
				}
				// found same letter as word
				else{
					*(_ans+i) = *(word+k);
					i++;
					check++;
				}
			}
			// print only if the mistake is 1 or less and the check is at word_len
			if(mistake <= 1 && check == word_len){
					*(_ans+i) = '\0';
					printf("%s\n",_ans);
					index += word_len-1; // if success no need to check those letters
			}
		// reset variables every end of loop and incerement index
	    check = 0;
		mistake = 0;
		i=0;
		index++;
	}

}



