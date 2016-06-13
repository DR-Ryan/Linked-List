#pragma once
#include <iostream>

using namespace std;

static int numb = 0;
//A class that stores an element of any type and an pointer to the next node in a list.
template<class Type> class SingleNode{	//Cyclic Linked List to access private member of SingleNode						
private:
	Type data;							
	SingleNode *next;
	int ID;
	template<class u>
	friend class CyclicLinkedList; //Cyclic Linked List to access private member of SingleNode	
public:
	SingleNode():data(0), next(nullptr){
		this->ID = ++numb;
	}
	SingleNode(const Type & data):next(nullptr){
		this->ID = ++numb;
		this->data = data;
	}
	SingleNode(const Type & data, SingleNode * next){	//This constructor takes two arguments
		this ->ID = ++numb;
		this->data = data;
		this->next = next;
	}
	
	~SingleNode(){
		cout << "Node " << this->ID << " is being deleted" << endl;
	}

	Type getData() const{	//Returns the data element of the node
		return this->data;
	}
	
	SingleNode *getNext() const{	//Returns the next pointer
		return this->next;
	}

};



