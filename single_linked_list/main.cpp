#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "single_linked_list.h"

int main()
{
	_CrtSetBreakAlloc(86);
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;

	// ��� 5�� �߰�
	for (i = 0; i < 5; i++)
	{
		NewNode = SLL_CreateNode(i);
		SLL_AppendNode(&List, NewNode);
	}

	SLL_Print(List);

	NewNode = SLL_CreateNode(-1);
	SLL_InsertNewHead(&List, NewNode);
	SLL_Print(List);

	NewNode = SLL_CreateNode(-2);
	SLL_InsertNewHead(&List, NewNode);
	SLL_Print(List);

	// ����Ʈ�� �� ��° ��� �ڿ� �� ��� ����
	printf("\nInserting 3000 After [2]...\n\n");

	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(3000);

	SLL_InsertAfter(Current, NewNode);
	SLL_Print(List);

	SLL_RemoveAt(&List, 3);

	/*
	// ��� ��带 �޸𸮿��� ����
	printf("\nDestroying List...\n");

	for (i = 0; i < Count; i++)
	{
		Current = SLL_GetNodeAt(List, 0);

		if (Current != NULL)
		{
			SLL_RemoveAt(&List, Current);
			SLL_DestroyNode(Current);
		}
	}
	*/

	_CrtDumpMemoryLeaks();
	return 0;
}