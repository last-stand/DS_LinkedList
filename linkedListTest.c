#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "expr_assert.h"
#include "linkedList.h"

int number;
void *data = &number;
Node_ptr new_node,new_node2;
LinkedList list;
LinkedList_ptr list_ptr;
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

void test_add_to_list_should_return_1_if_node_added_to_Linked_List(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	list = createList();
	assertEqual(add_to_list(list_ptr, new_node), 1);
	free(new_node);
}

void test_add_to_list_should_increments_count_to_1_if_node_added_to_Linked_List(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	new_node2 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	assertEqual(list.count, 1);
	add_to_list(list_ptr, new_node2);
	assertEqual(list.count, 2);
	free(new_node);
	free(new_node2);
}

void test_add_to_list_should_set_head_as_address_of_first_node(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	assert(new_node==list.head);
	free(new_node);
}

void test_add_to_list_should_set_tail_as_address_of_last_node(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	new_node2 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	assert(new_node2==list.tail);
	free(new_node);
}

void test_get_first_element_should_return_head_of_given_linked_list(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	assert((Node_ptr)get_first_element(list)==list.head);
	free(new_node);
}

void test_get_last_element_should_return_tail_of_given_linked_list_if_head_and_tail_are_same(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	assert((Node_ptr)get_first_element(list)==list.tail);
	free(new_node);
}

void test_get_last_element_should_return_tail_of_given_linked_list_if_head_and_tail_are_different(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	new_node2 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	assert((Node_ptr)get_last_element(list)==list.tail);
	free(new_node);
	free(new_node2);
}

void increment(void* data){
	*(int*)data += 1;
}

void test_traverse_should_increment_all_list_elements_by_1_with_increment_function_in_INT(){
	int a = 10, b = 20, c = 30;
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	data = &c;
	new_node3 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	add_to_list(list_ptr, new_node3);
	traverse(list,increment);
	assertEqual(*(int*)new_node->data, 11);
	assertEqual(*(int*)new_node2->data, 21);
	assertEqual(*(int*)new_node3->data, 31);
	free(new_node);
	free(new_node2);
	free(new_node3);
}

void myToUpper(void* data){
	*(char*)data = (char)toupper(*(char*)data);
}

void test_traverse_should_convert_all_list_chars_in_upperCase_with_myToUpper_function_in_CHAR(){
	char a = 'a', b = 'b', c = 'c';
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	data = &c;
	new_node3 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	add_to_list(list_ptr, new_node3);
	traverse(list,myToUpper);
	assertEqual(*(char*)new_node->data, 'A');
	assertEqual(*(char*)new_node2->data, 'B');
	assertEqual(*(char*)new_node3->data, 'C');
	free(new_node);
	free(new_node2);
	free(new_node3);
}

void myCeil(void* data){
	*(float*)data = (float)ceil(*(float*)data);
}

void test_traverse_should_convert_all_list_float_in_their_Ceil_value_with_myCeil_function_in_FLOAT(){
	float a = 1.54, b = 0.012, c = 99.9;
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	data = &c;
	new_node3 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	add_to_list(list_ptr, new_node3);
	traverse(list,myCeil);
	assertEqual(*(float*)new_node->data, 2.000000);
	assertEqual(*(float*)new_node2->data, 1.000000);
	assertEqual(*(float*)new_node3->data, 100.000000);
	free(new_node);
	free(new_node2);
	free(new_node3);
}

void myFloor(void* data){
	*(double*)data = (double)floor(*(double*)data);
}

void test_traverse_should_convert_all_list_double_in_their_floor_value_with_myFloor_function_in_DOUBLE(){
	double a = 1.54, b = 0.012, c = 99.9;
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	data = &c;
	new_node3 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	add_to_list(list_ptr, new_node3);
	traverse(list,myFloor);
	assertEqual(*(double*)new_node->data, 1.000000);
	assertEqual(*(double*)new_node2->data, 0.000000);
	assertEqual(*(double*)new_node3->data, 99.000000);
	free(new_node);
	free(new_node2);
	free(new_node3);
}

void stringToUpper(void* data){
	int i, length = strlen(data);
	for(i=0; i < length; i++){
		((char*)data)[i] = (char)toupper(((char*)data)[i]);
	}
}

void test_traverse_should_convert_string_to_upperCase_with_stringToUpper_function_for_STRING(){
	char a[] = "Jungle Jungle baat chali hai";
	char expected[] = "JUNGLE JUNGLE BAAT CHALI HAI";
	list_ptr = &list;
	data = a;
	new_node = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	traverse(list,stringToUpper);
	assertEqual(strcmp((char*)new_node->data,expected),0);
	free(new_node);
}

void test_getElementAt_should_return_NULL_if_given_index_is_not_exist_in_list_of_INT(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	new_node2 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	assert(getElementAt(list,3)==NULL);
	free(new_node);
	free(new_node2);
}

void test_getElementAt_should_return_element_on_the_given_index_in_list_of_CHAR(){
	char a = 'a', b = 'b', c = 'c';
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	data = &c;
	new_node3 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	add_to_list(list_ptr, new_node3);
	assert(*(char*)getElementAt(list,0)==a);
	assert(*(char*)getElementAt(list,1)==b);
	assert(*(char*)getElementAt(list,2)==c);
	free(new_node);
	free(new_node2);
	free(new_node3);
}

void test_indexOf_should_return_minus_1_if_given_element_is_not_found_in_list(){
	int num = 12;
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	assertEqual(indexOf(list,&num),-1);
	free(new_node);
}

void test_indexOf_should_return_index_of_given_element_if_found_in_list_of_INT(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	assertEqual(indexOf(list,data),0);
	free(new_node);
}

void test_indexOf_should_return_index_of_given_element_if_found_in_list_of_CHAR(){
	char a = 'a', b = 'b', c = 'c',d = 'd';
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	data = &c;
	new_node3 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	add_to_list(list_ptr, new_node3);
	assertEqual(indexOf(list,&a),0);
	assertEqual(indexOf(list,&b),1);
	assertEqual(indexOf(list,&c),2);
	assertEqual(indexOf(list,&d),-1);
	free(new_node);
	free(new_node2);
	free(new_node3);
}

void test_deleteElementAt_should_return_NULL_if_given_index_is_not_in_list(){
	list_ptr = &list;
	number = 10;
	new_node = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	assert(deleteElementAt(list_ptr,2)==NULL);
	assert(list_ptr->count==1);
	free(new_node);
}

void test_deleteElementAt_should_return_the_data_referenced_by_the_node_at_given_index_in_list(){
	int a = 10, b = 20, c = 30, *result;
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	data = &c;
	new_node3 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	add_to_list(list_ptr, new_node3);
	result = deleteElementAt(list_ptr,1);
	assert(*result==20);
	assert(new_node->next == new_node3);
	assert(list_ptr->count == 2);
	free(new_node);
	free(new_node2);
	free(new_node3);
}

void test_deleteElementAt_should_set_next_node_as_head_in_list_if_index_is_0(){
	char a = 'a', b = 'b', *result;
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	result = deleteElementAt(list_ptr,0);
	assert(*result==a);
	assert(list_ptr->head == new_node2);
	assert(list_ptr->tail == new_node2);
	assert(list_ptr->count == 1);
	free(new_node);
	free(new_node2);
}

void test_deleteElementAt_should_set_head_tail_NULL_and_count_0_if_index_of_only_node_is_passed(){
	char a = 'a', *result;
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	result = deleteElementAt(list_ptr,0);
	assert(*result==a);
	assert(list_ptr->head == NULL);
	assert(list_ptr->tail == NULL);
	assert(list_ptr->count == 0);
	free(new_node);
}

void test_deleteElementAt_should_set_previous_node_as_tail_in_list_if_last_index_is_passed(){
	float a = 11.99, b = 99.324513, *result;
	Node_ptr new_node3;
	list_ptr = &list;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	list = createList();
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	result = deleteElementAt(list_ptr,1);
	assert(*result==b);
	assert(list_ptr->head == new_node);
	assert(list_ptr->tail == new_node);
	assert(list_ptr->count == 1);
	free(new_node);
	free(new_node2);
}

void test_asArray_returns_0_if_linked_list_is_empty(){
	void *array[2];
	list = createList();
	assertEqual(asArray(list,array), 0);
}

void test_asArray_returns_the_number_of_elements_added_to_the_array(){
	void *array[2];
	int a = 11, b = 99;
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	list = createList();
	list_ptr = &list;
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	assertEqual(asArray(list,array), 2);
}

void test_asArray_populates_the_array_with_all_the_elements_of_the_list(){
	void *array[2];
	char a = 'a', b = 'b';
	data = &a;
	new_node = create_node(data);
	data = &b;
	new_node2 = create_node(data);
	list = createList();
	list_ptr = &list;
	add_to_list(list_ptr, new_node);
	add_to_list(list_ptr, new_node2);
	assertEqual(asArray(list,array), 2);
	assert(*(char*)array[0]==a);
	assert(*(char*)array[1]==b);
}