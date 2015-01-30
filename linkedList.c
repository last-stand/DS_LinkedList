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

void* deleteHead(LinkedList *list, int index){
	Node_ptr walker = list->head;
	void* data = walker->data;
	(list->head == list->tail) && (list->tail = NULL);
	list->head = walker->next;
	list->count -= 1;
	return data;
}

void *deleteTail(LinkedList *list, int index){
	int counter;
	void* data;
	Node_ptr walker = list->head, previous;
	for(counter=0; counter <= index; counter++){
			(counter == index-1) && (previous = walker);
			if(counter == index){
				list->tail = previous;
				previous->next = NULL;
				list->count -= 1;
				data = walker->data;
			}
			walker = walker->next;
	}
	return data;
}

void *deleteMiddle(LinkedList *list, int index){
	int counter =0;
	void *data;
	Node_ptr walker = list->head, previous;
	for(counter=0; counter<=index ;++counter){
			(counter == index-1) && (previous = walker);
			if(counter == index){
				previous->next = walker->next;
				list->count -= 1;
				data = walker->data;
			}
			walker = walker->next;
		}
		return data;
}

void * deleteElementAt(LinkedList *list, int index){
	Node_ptr walker = list->head, previous;
	if(index > list->count-1)
		return NULL;
	if(index == 0)	return deleteHead(list,index);
	if(index == list->count-1)
		return deleteTail(list,index);
	else
		return deleteMiddle(list,index);
	return NULL;
};

int asArray(LinkedList list, void **array){
	Node_ptr walker = list.head;
	int counter = 0;
	if(list.count == 0) return 0;
	while(walker != NULL){
		 array[counter] = walker->data;
		 walker = walker->next;
		 counter++;
	}
	return counter;
};