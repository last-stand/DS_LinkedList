#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stud Student;
typedef struct stuList List;
typedef Student *Student_ptr;
typedef List *List_ptr;
Student_ptr createStudent();
struct stud{
	int id;
	char *name;
	Student *next;
};

struct stuList
{
	int count;
	Student_ptr head;
	Student_ptr tail;
};

Student_ptr createStudent(int id,char *name,Student_ptr next){
	Student_ptr stu = calloc(1,sizeof(Student));
	(*stu).name = (char*)malloc(strlen(name)+1);
	(*stu).id = id;
	strcpy((*stu).name,name);
	stu->next = next;
	return stu;
}

List_ptr createList(void){
	List_ptr lst = calloc(1,sizeof(List));
	return lst;
}

void printStudent(Student_ptr stu){
	printf("Id: %d\t Name: %s\t next: %p \n",stu->id,stu->name,stu->next);
}

void addStudentToList(List_ptr lst,Student_ptr stu){
	lst->count += 1;
	if(lst->head == NULL){
		lst->head = stu;
		lst->tail = stu;
		return;
	}
	lst->tail = stu;
}

int main(int argc, char const *argv[])
{
	Student_ptr s1,s2,s3;
	List_ptr lst = createList();

	s3 = createStudent(3,"Vijay",NULL);
	s2 = createStudent(2,"Om",s2);
	s1 = createStudent(1,"Jai",s2);
	printf("Address of s1:  %p\n",s1);
	printf("Address of s2:  %p\n",s2);
	printf("Address of s3:  %p\n",s3);
	printStudent(s1);
	printStudent(s2);

	// lst->count = 3;
	// lst->head = s1;
	// lst->tail = s3;

	addStudentToList(lst,s1);
	addStudentToList(lst,s2);
	addStudentToList(lst,s3);

	printf("Address of head:  %p\n",lst->head);
	printf("Address of tail:  %p\n",lst->tail);
	printf("Address of tail:  %d\n",lst->count);
	return 0;
}