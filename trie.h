#define ALPHABET_SIZE 26
#define CASE 'a'

typedef enum {FALSE=0, TRUE=1} boolean;



typedef struct Node{

	struct Node* parent;
	struct Node* children[ALPHABET_SIZE];
	int occurrences; 
	
} Node;

Node* newNode();
void InsertNode(Node* trieNode, char* word);
Node* Search(Node* trieTree, char* word);
void printPreOrder(Node* node, char s[]);
void printReverse(Node* node, char s[]); 