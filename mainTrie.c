#include <stdio.h>
#include<stdlib.h>
#include "trie1.h"



int main(int argc, char *argv[])
{
	Node *Root = newNode();
	char letter;
	char *word = NULL;
	word = (char *)malloc(2 * (sizeof(char)));
	int index = 0;
	int word_length=0;
	int max_length = 0;
	

	while ((scanf("%c", &letter)) == 1) // gets each word and check if something went wrong with scanf function
	{
		

		if ((letter == '\n') || (letter == '\t') || (letter == '\0') || (letter == ' ') || (letter == ',')) //end of word
		{
			if(word_length > max_length)
				max_length = word_length;
			word[index] = '\0';
			index = 0;
			insertNode(Root, word);
			free(word);
			word = (char *)malloc(2 * (sizeof(char)));
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
		word_length++;
		}
	}
			if(word_length > max_length)
			max_length = word_length;
			word[index] = '\0';
			index = 0;
			insertNode(Root, word);
			free(word);
			word = (char *)malloc(2 * (sizeof(char)));
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