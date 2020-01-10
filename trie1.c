#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "trie.h"
#include <stdlib.h>
#define SIZE_WORD 2

// #define ALPHABET_SIZE 26
#define CASE 'a'

Node *newNode()
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->parent = NULL;
	p->occurrences = 0;
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		p->children[i] = NULL;
	}

	return p;
}

void insertNode(Node *trieNode, char l[])
{

	printf("%s", l);
	Node *currentNode = trieNode;

	while (*l != '\0')
	{

		if (currentNode->children[*l - CASE] == NULL)
		{
			currentNode->children[*l - CASE] = newNode();
			currentNode->children[*l - CASE]->parent = currentNode;
		}
		currentNode = currentNode->children[*l - CASE];
		l++;
	}
	currentNode->occurrences++;
}

Node *search(Node *trieTree, char *word)
{

	while (*word != '\0')
	{
		if (trieTree->children[*word - CASE] != NULL)
		{
			trieTree = trieTree->children[*word - CASE];
			++word;
		}
		else
		{
			return NULL;
		}
	}

	return (trieTree->occurrences != 0) ? trieTree : NULL;
}

void printPreOrder(Node *node, char s[])
{
	if (node->occurrences > 0)
	{
		printf("%s  \t %d\n", s, node->occurrences);
	}
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (node->children[i] != NULL)
		{
			s[i] = i + CASE;
			printPreOrder(node->children[i], s);
			//need to delete the printed word
		}
	}
}

void printReverse(Node *node, char s[])
{
	if (node->occurrences > 0)
	{
		printf("%s  \t %d\n", s, node->occurrences);
	}
	for (int i = ALPHABET_SIZE; i >= 0; i--)
	{
		if (node->children[i] != NULL)
		{
			s[i] = i + CASE;
			printPreOrder(node->children[i], s);
			//need to delete the printed word
		}
	}
}

void freeNode(Node *trieTree)
{
	Node *currentNode = trieTree;

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (currentNode->children[i] != NULL)
		{
			freeNode(currentNode->children[i]);
		}
	}
	free(currentNode);
}

int main(int argc, char *argv[])
{
	Node *Root = newNode();
	Node **p = &Root;
	char letter;
	char *word = NULL;
	word = (char *)malloc(2 * (sizeof(char)));
	int index = 0;

	while ((scanf("%c", &letter)) == 1)
	{

		if ((letter == '\n') || (letter == '\t') || (letter == '\0') || (letter == ' ') || (letter == ',')) //end of word
		{
			word[index] = '\0';
			index = 0;
			insertNode(Root, word);
			free(word);
			continue;
		}

		if (letter >= 'A' && letter <= 'Z')
		{
			letter = letter + 32;
		}
		word[index] = letter;
		index++;
		word = realloc(word, index + 2);
	}

	if (argc == 1)
	{
	}
	else if (argc == 2)
	{
	}

	freeNode(Root);

	return 0;
}
