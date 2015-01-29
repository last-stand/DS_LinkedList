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

int add_to_list(LinkedList *list,Node *node){
	if(list->head == NULL){
		list->head = node;
		list->tail = node;
		list->count = 1;
		return 1;
	}
	list->tail->next = node;
	list->tail = node;
	list->count += 1;
	if(list->count > 0)
		return 1;
	return 0;
};

void *get_first_element(LinkedList list){
	return list.head;
};

void *get_last_element(LinkedList list){
	return list.tail;
};

void traverse(LinkedList list, Function fun){
	Node_ptr walker = list.head;
	while(walker != NULL){
		 fun(walker->data);
		 walker = walker->next;
	}
};

void * getElementAt(LinkedList list, int index){
	void *result = NULL;
	int counter;
	Node_ptr walker = list.head;
	if(index > list.count-1)
		return result;
	for(counter=0; counter<=index ;++counter){
		if(counter == index)
			result = walker->data;
		walker = walker->next;
	}
	return result;
};

int indexOf(LinkedList list, void *element){
	Node_ptr walker = list.head;
	int index = 0;
	while(walker != NULL){
		if(walker->data == element)
			return index;
		 ++index;
		 walker = walker->next;
	}
	return -1;
};