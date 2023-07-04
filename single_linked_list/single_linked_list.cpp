#include "single_linked_list.h"

Node* SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	
	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

void SLL_DestroyNode(Node* Node)
{

}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
	if (*Head == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = { *Head };
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

void SLL_InsertAfter(Node* Current, Node* NewNode)
{

}

void SLL_InsertNewHead(Node** Head, Node* NewHead)
{

}


void SLL_RemoveNode(Node** Head, Node* Remove)
{

}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	return NULL;
}

int SLL_GetNodeCount(Node* Head)
{
	return 0;
}

