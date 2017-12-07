#include "stdafx.h"
#include "LList.h"
#include "VBot.h"
typedef VBot InfoType;
//#define TESTING_LLIST
struct LList::Node
{
	Node(InfoType * x, Node * p = NULL) { infoPtr = x;  next = p; }
	~Node() { delete infoPtr; }
	InfoType * infoPtr;
	Node * next;
};

LList::~LList()
{
	Node *P = list, *Q;
	list = NULL;
	while(P != NULL) {
		Q = P;
		P = P->next;
		delete Q;
	}
	P = NULL;
	Q = NULL;
}

bool LList::IsEmpty() const
{
	if (list == NULL) 
	{
		return true;
	}
	return false;
}

bool LList::Insert(InfoType * x_ptr)
{
	bool status = false;
	Node *Q = list, *P = list;
	if (IsEmpty()) {
		list = new Node(x_ptr);
		status = true;
	}
	else {
		list = new Node(x_ptr, list);
		status = true;
	}
	return status;
}

void LList::DeleteDead()
{
	Node *P = list;
	if (P == NULL) {
		return;
	}
	while (P != NULL && P->next != NULL ) {
		if (P->next->infoPtr->IsDead()) {
			Node *Q = P->next;
			if (P->next->next != NULL) {
				P->next = P->next->next;
			}
			else {
				P->next = NULL;
			}
			
			delete Q;
		}
		P = P->next;
		
	}
}

void LList::BattleManager() {
	Node *P = list;
	if (P != NULL && P->next != NULL) {
		Node *Q = list->next;
		while (P->next != NULL) {
			while (Q != NULL) {
				if (P->infoPtr->CollidedWith(Q->infoPtr)) {
					Q->infoPtr->DoBattleWith(P->infoPtr);
				}
				Q = Q->next;
			}
			P = P->next;
		}
	}
}
void LList::MoveAll() {
	Node *P = list;
	while (P != NULL) {
		P->infoPtr->Move();
		P = P->next;
	}
}

void LList::ShowAll()
{
	Node *P = list;
	while (P != NULL) {
		P->infoPtr->Show();
		P = P->next;
	}
}

LList & LList::operator=(const LList & assignFrom)
{
	LList returnlist;

	Node *P = list;
	while (P->next != NULL) {
		
		returnlist.Insert(P->infoPtr);
		P = P->next;
	}
	return returnlist;
}

#ifdef TESTING_LLIST

// ------------------------------
// Testbed main
// ------------------------------
void main()
{
#include <iostream>
	// .... etc, to test all the methods.
	const int MAX_INPUT_LEN = 34;
	//-------------------------------------------------------
	// Don't touch any of this!
	//-------------------------------------------------------

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);

	Fruit *test = new Fruit();
	cin >> *test;

	LList *LL = new LList();
	LL->Insert(test);
	LL->Display(cout);

	LL->Delete(test);
	LL->Display(cout);

	Fruit *test2 = new Fruit();
	cin >> *test2;
	Fruit *test3 = new Fruit();
	cin >> *test3;

	LL->Insert(test2);
	LL->Insert(test3);

	LL->Display(cout);

	Fruit *test4 = new Fruit();
	cin >> *test4;

	LL->Insert(test4);
	LL->Delete(test3);
	LL->Display(cout);

	delete LL;

	delete test;
	_CrtDumpMemoryLeaks();
	int pause;
	cin >> pause;
}

#endif
