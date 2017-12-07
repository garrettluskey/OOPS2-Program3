#ifndef LLIST
#define LLIST

#include "stdafx.h"
typedef VBot InfoType;
class LList
{
public:
	LList() { list = NULL; }
	~LList();    // delete all the nodes
	bool IsEmpty() const; //is list empty?
	bool Insert(InfoType *x_ptr); //inserts into list where name is alphabetically ordered
	void DeleteDead(); //Deletes all dead bots
	void BattleManager(); //Checks if 2 bots are colliding then they fight based on energy
	void MoveAll(); //Calls move on all bots
	void ShowAll(); //Calls show on all bots
	//bool Delete(InfoType *x); // deletes node from list
	//void Display(ostream & out_stream) const; //prints list

private:
	struct Node;
	Node *list;
	LList(const LList & copyFrom);       // Copy constructor           
	LList & operator= (const LList & assignFrom);   //Assignment operator
};
#endif // !LLIST