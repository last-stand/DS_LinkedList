#include <stdio.h>
#include <stdlib.h>
#include "expr_assert.h"
#include "linkedList.h"

int number;
void *data = &number;
Node_ptr new_node;
LinkedList list;
void test_create_node_should_return_address_of_created_node_for_INT_type(){
	number = 10;
	new_node = create_node(data);
	assert(new_node!=NULL);
	free(new_node);
}

void test_create_node_should_create_new_node_and_initialises_data_in_INT_type(){
	number = 10;
	new_node = create_node(data);
	assertEqual(*(int*)new_node->data, number);
	free(new_node);
}

void test_create_node_should_create_new_node_and_initialises_next_to_NULL_in_INT_type(){
	number = 10;
	new_node = create_node(data);
	assertEqual((int)new_node->next, 0);
	free(new_node);
}

void test_createList_should_create_an_empty_Linked_List_structure(){
	list = createList();
	assertEqual((int)list.head, 0);
	assertEqual((int)list.tail, 0);
	assertEqual(list.count, 0);
}