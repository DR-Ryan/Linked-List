#pragma once
#include <iostream>

using namespace std;

static int num = 0;

template <class Type> class DoubleNode{
private:
	DoubleNode * prev;
	Type data;
	DoubleNode * next;
	int ID;
	template<class u>
	friend class DoublyLinkedList;
public:

	DoubleNode():data(0),next(nullptr),prev(nullptr){
		this->ID = ++num;
	}
	DoubleNode(const Type & data):next(nullptr),prev(nullptr){
		this->data = data;
		this->ID = ++num;
	}
	DoubleNode(const Type & data, DoubleNode * next):prev(nullptr){
		this->data = data;
		this->next = next;
		this->ID = ++num;
	}
	DoubleNode(const Type & data, DoubleNode * next, DoubleNode * prev){
		this->data = data;
		this->next = next;
		this->prev = prev;
		this->ID = ++num;
	}
	~DoubleNode(){
		cout << "Node " << this->ID << " is being deleted" << endl;
	}
	Type getData()const{
		return this->data;
	}

	DoubleNode *getNext()const{
		return this->next;
	}
	DoubleNode *getPrev()const{
		return this->prev;
	}
};