#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
 
list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
    node_t*temp=malloc(sizeof(node_t));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    if(list->size==0)
    {
        list->head = temp;
        list->tail = temp;
    }
    else
    {
		temp->next = list->head;
		list->head->prev = temp;
		list->head = temp;
    }
	(list->size)++;
}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
	node_t*temp=malloc(sizeof(node_t));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
	if(list->size==0)
    {
        list->head = temp;
        list->tail = temp;
    }
	else
	{
		temp->prev=list->tail;
		list->tail->next = temp;
		list->tail = temp;
	}
	(list->size)++;

}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node with data “prev”. Do not insert or do anything if prev doesn't exist
{
	node_t* node=(node_t*)malloc(sizeof(node_t));
	node->data=data;
	node_t* temp=search(list,prev);
	if(temp){
		temp->next->prev=node;
		node->prev=temp;
		node->next=temp->next;
		temp->next=node;
		(list->size)++;
	}
}

void delete_front(list_t* list) // TODO: delete the start node from the linked list.
{
	node_t*p;
	if(list->size!=0)
	{
		p=list->head;
		if(size(list)==1)
		{
			list->head=NULL;
			list->tail=NULL;
			free(p);
		}
		else
		{
			list->head = list->head->next;
			list->head->prev=NULL;
			free(p);
		}
}
}

void delete_back(list_t* list)    // TODO: delete the end node from the linked list.
{
	node_t*p;
	if(list->size!=0)
	{
		p=list->head;
		if(size(list)==1)
		{
			list->head=NULL;
			list->tail=NULL;
			free(p);
		}
		else
		{
			list->tail=list->tail->prev;
			list->tail->next=NULL;
			free(p);
		}
	}
	
	
}

void delete_node(list_t* list, int data) // TODO: delete the node with “data” from the linked list.
{
	if(list->size!=0)
	{
		node_t*p = search(list,data);
		if(list->head==p)
		{
			delete_front(list);
		}
		else if(list->tail==p)
		{
			delete_back(list);
		}
		else
		{
			p->prev->next = p->next;
			p->next->prev=p->prev;
			free(p);
		}
	}
}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node with “data” field. Return NULL if not found.
{	
	node_t*p;
	if(list->size!=0)
	{
		p=list->head;
		while(p!=NULL && p->data!=data)
		{
			p=p->next;
		}
		return p;
	}
	else
	{
		return NULL;
	}
}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}
