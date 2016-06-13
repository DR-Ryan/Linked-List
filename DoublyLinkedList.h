#include "DoubleNode.h"
#include <iostream>
#include <cassert>
#include <stdexcept>
#include <exception>
using namespace std;

template<class Type> class DoublyLinkedList{
private:
	DoubleNode<Type> *headptr;
	DoubleNode<Type> *tailptr;
	int listsz;
public:
	//constructor
	DoublyLinkedList():headptr(nullptr),tailptr(nullptr),listsz(0){}
	//destructor
	~DoublyLinkedList(){}
	//Accessor
	int size()const{
		if(listsz == 0) {
			return cout<< "List is empty" << endl;
		}
		else{
		return listsz;
		}
	}
	bool empty()const{
		return headptr == nullptr;
	}
	Type front()const{
		if(this->empty()) throw underflow_error("List is Empty");
		return DoublyLinkedList<Type>::headptr->data; 
	}
	Type back()const{
		if(this->empty()) throw underflow_error("List is Empty");
		return DoublyLinkedList<Type>::tailptr->data;
	}
	DoubleNode<Type> *head()const{
		return this->headptr;
	}
	DoubleNode<Type> *tail()const{
		return this->tailptr;
	}
	int count(Type const & listsz){
		int size = 0;
		DoubleNode<Type> *ptr = headptr;
        while(ptr->ID != listsz){
            ptr = ptr->next;
            ++size;
        }
            return size;
	}

	//All the Mutators
	void push_front(const Type & data){
		DoubleNode<Type> *NewNode = new DoubleNode<Type>(data,nullptr,nullptr);
		if(listsz == 0){
			headptr = NewNode;
			NewNode->next = nullptr;
			tailptr = NewNode;
			++listsz;
		}
		else{
			NewNode->next = headptr;
			headptr = NewNode;
			headptr->next->prev = NewNode;
		}
		NewNode->prev = nullptr;
	}
	void push_back(Type const & data){
		DoubleNode<Type> *NewNode = new DoubleNode<Type>(data,nullptr,nullptr);
		if(listsz == 0){
		tailptr = NewNode;
		NewNode->prev = nullptr;
		headptr = NewNode;
			++listsz;
		}
		else{
			NewNode->prev = tailptr;
			tailptr = NewNode;
			tailptr->prev->next = NewNode;
		}
		NewNode->next = nullptr;
	}
	void pop_front(){
		if(headptr == nullptr) throw underflow_error("Stack is empty");
		if(headptr == tailptr){
			delete headptr;
			headptr = nullptr;
			tailptr = nullptr;
			--listsz;
		}
		else{
			DoubleNode<Type> *tmpnode = new DoubleNode<Type>(0,nullptr,nullptr);
			tmpnode = headptr->next;
			headptr->next->prev = tmpnode;
			tmpnode->prev = nullptr;
			delete headptr;
			headptr = tmpnode;
		}
		DoublyLinkedList::printLst();
	}
	void printLst()const{
        DoubleNode<Type> *ptr = headptr;
        cout << "Printing from Heads Perspective" << endl;
        while(ptr != nullptr){
            cout << "Node[" << ptr->ID <<"]=" << ptr->data << "-->";
            ptr = ptr->next;
        }
        cout << "end" << endl;
		DoubleNode<Type> *ptrtail = tailptr;
		cout << endl;
		cout << "Printing from Tails Perspective" << endl;
        while(ptrtail != nullptr){
            cout << "Node[" << ptrtail->ID <<"]=" << ptrtail->data << "-->";
            ptrtail = ptrtail->prev;
        }
        cout << "end" << endl;
    }
	int erase(Type const & data){
		DoubleNode<Type> *ptr = headptr;
        DoubleNode<Type> *prev = headptr;
        int del = 0;
        while(ptr->next != nullptr){
            if(ptr->data == data){
                if(ptr==headptr){
                headptr->next->prev = nullptr;
                delete headptr;
                 headptr = ptr->next;
                ++del;
                --listsz;
                }
                else{
                    prev->next=ptr->next;
                    ptr->next->prev=prev;
                    ptr = prev;
                    ++del;
                    --listsz;
                }
            }
            prev = ptr;
            ptr = ptr->next;
        }
        if (ptr->next == nullptr)
        {
        	if(ptr->data == data){
        	cout << "This is working" << endl;
        	ptr->prev->next = nullptr;
        	delete tailptr;
        	tailptr = ptr->prev;
        	}
        }
        DoublyLinkedList::printLst();
        return cout << "Deleted " << del << " node/s." << endl;
	}
};