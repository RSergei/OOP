#pragma once

using namespace std;

struct UnidirectionalCLNode

{

	int data;

	UnidirectionalCLNode* ptrnext;

	UnidirectionalCLNode* ptrprev;

};

class UnidirectionalCL

{

private:

	UnidirectionalCLNode * first;

	UnidirectionalCLNode* last;

public:

	UnidirectionalCL();

	~UnidirectionalCL();

	void AddBack(int dt);

	void AddFront(int dt);

	int RemoveFront();

	int RemoveBack();

	int ElementAt(int index);

	void DeleteLink(UnidirectionalCLNode* node);

	UnidirectionalCL operator=(UnidirectionalCL& l);

	int Length();

	void Clear();

};