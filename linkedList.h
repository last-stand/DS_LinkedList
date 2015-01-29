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