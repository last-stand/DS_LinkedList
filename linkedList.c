#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

Node * create_node(void *data){
	Node_ptr link = calloc(1,sizeof(Node));
	link->data = data;
	link->next = NULL;
	return link;
};

LinkedList createList(void){
	LinkedList list;
	list.head = NULL;
	list.tail = NULL;
	list.count = 0;
	return list;
};