typedef struct list LinkedList;
typedef struct node Node;
typedef LinkedList *LinkedList_ptr;
typedef Node *Node_ptr;
struct node{
	void *data;
	Node *next;
};
struct list
{
	int count;
	Node_ptr head;
	Node_ptr tail;
};

Node * create_node(void *data);
LinkedList createList(void);
int add_to_list(LinkedList *,Node *);
void *get_first_element(LinkedList list);
void *get_last_element(LinkedList list);
typedef void (*Function)(void *data);
void traverse(LinkedList, Function);