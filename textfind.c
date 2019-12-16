#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
#define true 1
#define false 0

void print_similar_words(char* str, char* word);
void print_lines(char* str, char* word);

//&& line[line_length] != EOF
int main(){
	char line[LINE];
	char* p_line = line;
	char c;
	int line_num = 1, line_length = 0;
	char word[WORD];
	char type;
	while(1) {
		c = getchar();       // Get one character from the input
		if (c == EOF) {// line_length > LINE-1
			break; }  // Exit the loop if we receive EOF ("end of file")

		//  while(scanf("%c",&c) == 1 && line_length < LINE-1 && *(p_line + line_length) != EOF) {
		*(p_line + line_length) = c;// fill the array
		line_length++;
		if(c == '\n'  && line_num == 1){
			type = *(p_line + line_length -2); // get the type a or b
			strncpy(word,p_line, line_length - 3);
			word[line_length - 3] = '\0'; // to make it a string fixxxxxxxfix
			p_line = p_line + line_length + 1;// point to new line
			line_length = 0;
			line_num++;
			//strcat(word,"");
		}
		else if(c == '\n' && line_num > 1){
			if(type == 'a'){// type a print lines with word
				//printf("%c",*(p_line + line_length-1));
				*(p_line + line_length) = '\0';
				//printf("%s",p_line);
				print_lines(p_line,word);
				p_line = p_line + line_length + 1;// point to new line
				line_num++;
				line_length = 0;
			}
			else{
				print_similar_words(p_line,word);
				p_line = p_line + line_length + 1;// point to new line
				line_num++;
				line_length = 0;
			}
		}
		//print_lines(line + line_length, word);
	}
}

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
				//puts(str);
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
	int mistake = 0;
	int index = 0;
	char* p_ans;
	//int flag = true; // Boolean 1 true of 0 false
	int word_len = strlen(word);
	char ans[word_len+2];
	char* _ans = ans;
	int i = 0;
	int check = 0;
	while(*(str+index) != '\n'){
		//if(*(str+index) == *(word)){ // first char equal
		//	*(_ans) = *(word);
			p_ans = str+index;
			for(int k = 0;(*(p_ans+k+mistake) != ' ' && *(p_ans+k+mistake) != '\n' ) && k <= word_len; k++){// check if the strings are equals
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
					puts(_ans);
					index += word_len-1; // if success no need to check those letters
			}
			// break  while loop
			// if true then line contains the word
		//}
	   check = 0;
		mistake = 0;
		i=0;
		index++;
	}

}



