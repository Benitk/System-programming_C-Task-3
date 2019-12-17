#include <stdio.h>
#include <string.h>
#include "textfind.h"
#define LINE 256
#define WORD 30


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
		*(p_line + line_length) = c;// fill the array
		line_length++;
		if(c == '\n'  && line_num == 1){
			type = *(p_line + line_length -2); // get the type a or b
			strncpy(word,p_line, line_length - 3);
			*(word +line_length - 3) = '\0';
			p_line = p_line + line_length + 1;// point to new line
			line_length = 0;
			line_num++;
		}
		else if(c == '\n' && line_num > 1){
			if(type == 'a'){// type a print lines with word
				*(p_line + line_length) = '\0';
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
	}
}
