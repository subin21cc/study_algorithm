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
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

void SLL_Print(Node* List)
{
	while (List != NULL)
	{
		printf("%d ", List->Data);
		List = List->NextNode;
	}
	printf("\n");
}

void SLL_InsertAfter(Node* Current, Node* NewNode)
{
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
	if (*Head == NULL)
	{
		(*Head) = NewHead;
	}
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}


void SLL_RemoveAt(Node** Head, int Location)
{
	int count = 0;
	Node* next = *Head;

	if (next == NULL)
	{
		return;
	}

	if (Location == 0)
	{
		free(*Head);
		(*Head) = next->NextNode;
		return;
	}

	while (next != NULL)
	{
		if (count + 1 == Location)
		{
			if (next->NextNode != NULL)
			{
				free(next->NextNode);
				next->NextNode = next->NextNode->NextNode;
			}
			return;
		}
		count++;
		next = next->NextNode;
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	int count = 0;

	while (Head != NULL)
	{
		if (count == Location)
		{
			return Head;
		}
		count++;
		Head = Head->NextNode;
	}
	return NULL;
}

int SLL_GetNodeCount(Node* Head)
{
	int count = 0;

	while (Head != NULL)
	{
		count++;
		Head = Head->NextNode;
	}
	return count;
}

