#include <stdio.h>
#include <stdlib.h>

struct bucket* hashTable=NULL;
int SIZE = 10;

struct node{int key; int value; struct node* next;};
struct bucket{struct node* head; int count;};
struct node* createNode(int key, int value){
    struct node* newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
int hashFunction(int key){return key % SIZE;}
void insert(int key, int value){
    int hashIndex = hashFunction(key);
    struct node* newNode = createNode(key, value);
    if (hashTable[hashIndex].head == NULL) {
	//if (hashTable[hashIndex].count == 0) {
	hashTable[hashIndex].head = newNode;
	hashTable[hashIndex].count = 1;
    }else{
	newNode->next = hashTable[hashIndex].head;
	hashTable[hashIndex].head = newNode;
	hashTable[hashIndex].count++;
    }
}
void delete(int key){
    int hashIndex = hashFunction(key);
    struct node* node;
    struct node* trace;
    node = hashTable[hashIndex].head;
    if (node == NULL) {
	printf("\n no key found!!!\n");
	return;
    }
    while(node != NULL){
	if (node->key == key) {
	    if (node == hashTable[hashIndex].head) {
		hashTable[hashIndex].head = node->next;
	    } else{
		trace->next = node->next;
	    }
	    hashTable[hashIndex].count--;
	    free(node);
	    return;
	}
	trace = node;
	node = node->next;
    }
    printf("\n no key found!!!");
    return;
}

void search(int key){
    int hashIndex = hashFunction(key);
    struct node* node = hashTable[hashIndex].head;
    if (node == NULL) {
	printf("\n no key found!!\n");
	return;
    }
    while (node != NULL) {
	if (node->key == key) {
	    printf("key found!! key=[%d], value=[%d]\n", node->key, node->value);
	    return;
	}
	node = node->next;
    }
    printf("\nno key found!!\n");
    return;
}
void display(){
    struct node* horse;
    int i = 0;
    for (i = 0; i < SIZE; ++i) {
	horse = hashTable[i].head;
	printf("Bucket[%d] : ", i);
	while (horse != NULL) {
	    printf("(key: %d, val: %d) -> ", horse->key, horse->value);
	    horse = horse->next;
	}
	printf("\n");
    }
    printf("------- end of display --------");
    return;
}

int main(int argc, char *argv[])
{
    hashTable = (struct bucket*)malloc(SIZE*sizeof(struct bucket));
    for (int i=0; i<SIZE; ++i) {
	hashTable[i].head = NULL;
	//hashTable[i].count = 0;
    }

    insert(0,1012);
    insert(1,1012);
    insert(2,2022);
    insert(3,3132);
    insert(33,32);
    insert(4,3032);
    insert(5,5102);
    insert(6,5002);
    insert(7,5052);
    insert(8,152);
    insert(9,52);
    display();
    remove(0);
    delete(3);
    display();
  
    return 0;
}
