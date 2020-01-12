#include <stdio.h>
#include<stdlib.h>
#include "trie1.h"



int main(int argc, char *argv[])
{
	Node *Root = newNode();
	char letter;
	char *word = NULL;
	word = (char *)malloc(2 * (sizeof(char)));
	*word = 0;
	*(word+1) = 0;
	int index = 0;
	int word_length=0;
	int max_length = 0;
	

	while ((scanf("%c", &letter)) == 1) // gets each word and check if something went wrong with scanf function
	{

		//printf("the letter is : %c\n",letter);
		if ((letter == '\n') || (letter == '\t') || (letter == '\0') || (letter == ' ') || (letter == ',')) //end of word
		{
			
			//printf("letter in while is : %d\n",letter);
			if(word_length > max_length)
				max_length = word_length;

			 word[index] = '\0';
			index = 0;
			insertNode(Root, word);
			free(word);
			word = (char *)malloc(2 * (sizeof(char)));
			*word = 0;
			*(word+1) = 0;
			word_length = 0;
			continue;
		}

		if (letter >= 'A' && letter <= 'Z')
		{
			letter = letter + 32;
		}
		if(letter >= 'a' && letter <= 'z'){
		word[index] = letter;
		index++;
		word = realloc(word, index + 2);
		for(int i=index;i<index+2;i++){
			*(word+index) =0;
		}
		word_length++;
		}
	}
			// if(word_length > max_length)
			// max_length = word_length;
			// word[index] = '\0';
			// index = 0;
			insertNode(Root, word);
			free(word);
			word = (char *)malloc(2 * (sizeof(char)));
			*word = 0;
			*(word+1) = 0;
			word_length = 0;
			
	free(word);

	char w[max_length];

	if (argc == 1)
	{
		int i=0;
		printf("there is only 1 argc\n");
		printPreOrder(Root,  w, i);
	} 
	
	else if (argc == 2)
	{

		int i=0;
		printf("there is only 2 argc\n");
		printReverse(Root, w, i);
	}

	
	
	
	 freeNode(Root);

	return 0;
}