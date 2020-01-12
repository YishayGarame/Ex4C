#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "trie1.h"
#include <stdlib.h>
#define SIZE_WORD 2
 #define ALPHABET_SIZE 26
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


void printPreOrder(Node *node, char s[], int index)
{
	if (node->occurrences > 0)
	{
		s[index]='\0';
		printf("%s\t%d\n", s, node->occurrences);

	}
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (node->children[i] != NULL)
		{
			s[index] = i + CASE;			
			index++;		
			printPreOrder(node->children[i], s,  index);
		
			index--; 
		
			
		}		

	} 
	
			
}  

void printReverse(Node *node, char s[], int index)
{
	if (node->occurrences > 0)
	{
		s[index]='\0';
		printf("%s\t%d\n", s, node->occurrences);
	}

	for (int i = ALPHABET_SIZE-1; i >= 0; i--)
	{
		if (node->children[i] != NULL)
		{
			s[index] = i + CASE;
			index++;
			printReverse(node->children[i], s, index);
			index--;
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

void insertNode(Node *trieNode, char l[])
{

	//printf("%s", l);
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

