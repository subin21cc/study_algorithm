#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "single_linked_list.h"

void test1()
{
	/*
		0 1 2 3 4
		-1 0 1 2 3 4
		-2 -1 0 1 2 3 4
		-2 -1 0 3000 1 2 3 4
		-2 -1 0 1 2 3 4

	*/
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;

	// 노드 5개 추가
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

	Current = SLL_GetNodeAt(List, 2);
	NewNode = SLL_CreateNode(3000);

	SLL_InsertAfter(Current, NewNode);
	SLL_Print(List);

	SLL_RemoveAt(&List, 3);
	SLL_Print(List);

	SLL_Clear(&List);
	SLL_Print(List);
}

void test2()
{
	/*
		4 3 0 9
		3 0 9
		3 0 1 2 3 9
		3 1 3
		1 2 3
	*/

	Node* List = NULL;
	Node* Current = NULL;
	Node* NewNode = NULL;

	NewNode = SLL_CreateNode(4);
	SLL_AppendNode(&List, NewNode);

	NewNode = SLL_CreateNode(3);
	SLL_AppendNode(&List, NewNode);

	NewNode = SLL_CreateNode(0);
	SLL_AppendNode(&List, NewNode);

	NewNode = SLL_CreateNode(9);
	SLL_AppendNode(&List, NewNode);
	SLL_Print(List);

	SLL_RemoveAt(&List, 0);
	SLL_Print(List);

	for (int i = 0; i < 3; i++)
	{
		Current = SLL_GetNodeAt(List, i+1);
		NewNode = SLL_CreateNode(i+1);

		SLL_InsertAfter(Current, NewNode);
	}
	SLL_Print(List);

	for (int i = 0; i < 6; i ++)
	{
		SLL_RemoveAt(&List, i+1);
	}
	SLL_Print(List);

	SLL_RemoveAt(&List, 0);
	Current = SLL_GetNodeAt(List, 0);
	NewNode = SLL_CreateNode(2);

	SLL_InsertAfter(Current, NewNode);
	SLL_Print(List);

	SLL_Clear(&List);
	SLL_Print(List);
}

void test3()
{

	/*
		4 3 0 9
		3 0 9
		3 0 1 2 3 9
		3 1 3
		1 2 3
	*/

	Node* List = NULL;
	
	SLL_Append(&List, 4);
	SLL_Append(&List, 3);
	SLL_Append(&List, 0);
	SLL_Append(&List, 9);
	SLL_Print(List);

	SLL_RemoveAt(&List, 0);
	SLL_Print(List);

	for (int i = 0; i < 3; i++)
	{
		SLL_InsertAt(List, i + 1, i + 1);
	}
	SLL_Print(List);

	for (int i = 0; i < 6; i++)
	{
		SLL_RemoveAt(&List, i + 1);
	}
	SLL_Print(List);

	SLL_RemoveAt(&List, 0);
	SLL_InsertAt(List, 0, 2);

	SLL_Print(List);

	SLL_Clear(&List);
	SLL_Print(List);
}

int main()
{
	test1();
	test2();
	test3();

	return 0;
}