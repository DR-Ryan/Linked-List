#include "SingleNode.h"
#include <stdexcept>
#include <exception>


template<class Type> class CyclicLinkedList{
	
private:
	SingleNode<Type> *headptr;			//head pointer
	SingleNode<Type> *tailptr;			//tail pointer;				
	int listSize;
public:
	//constructor
	CyclicLinkedList():headptr(nullptr),tailptr(nullptr),listSize(0){	
		cout << "List Created" << endl;
	}
	//destructor
	~CyclicLinkedList(){}
	//Accessors
	int size() const{
		if(numb == 0) {
			return cout<< "List is empty" << endl;
		}
		else{
			return numb;
		}
	}
	bool empty() const{
		return headptr == nullptr;
	}
	Type front() const{
		if (this->empty()) throw underflow_error("Stack is Empty");
		return CyclicLinkedList<Type>::headptr->data;
	}
	Type back() const{
		if (this->empty()) throw underflow_error("Stack is Empty");
		return CyclicLinkedList<Type>::tailptr->data;
	}
	void print_list();
	SingleNode<Type> *head() const{
		return this->headptr;
	}
	SingleNode<Type> *tail() const{
		return this->tailptr;
	}
	int count(Type const & listSize){
		int sz = 0;
		SingleNode<Type> *ptr = headptr;
        while(ptr->ID != listSize){
            ptr = ptr->next;
            ++sz;
        }
            return sz;
	}
	//All the mutators
	void push_front(const Type & val){
		SingleNode<Type> *NewNode = new SingleNode<Type>(val, nullptr);
		NewNode->next = headptr;
		headptr = NewNode;
		if (listSize == 0){
			tailptr = NewNode;
			tailptr->next = headptr;
		}
		++listSize;
		}
	void push_back(const double &val){
		SingleNode<Type> *NewNode = new SingleNode<Type>(val, nullptr);
		if(listSize == 0){
			headptr = NewNode;
			NewNode->next = headptr;
			tailptr = NewNode;
			tailptr->next = headptr;
			++listSize;
		}
		else{
			tailptr = NewNode;
			NewNode->next = headptr;
			NewNode = tailptr->next;
			tailptr->next = NewNode;
		}
	}
	void pop_front(){
		if (this->empty()) throw underflow_error("List is Empty");
		if (headptr == tailptr) // One element nodes
    	{
        	delete headptr;
        	headptr = nullptr;
        	tailptr = nullptr;
        	--listSize;
        	//return;
    	}
		else{
			SingleNode<Type> *tempNode = new SingleNode<Type>(0, nullptr);
			tempNode = headptr->next;
			delete headptr;
			headptr = tempNode;
			--listSize;
		}
		CyclicLinkedList::printLst();
	}
	void printLst() const{
        SingleNode<Type> *ptr = headptr;
        while(ptr != tailptr->next){
            cout << "Node=[" <<ptr->ID << "]=" << ptr->data << "-->";
            ptr = ptr->next;
        };
        if(ptr == tailptr->next){
        	cout << "Node=[" <<ptr->ID << "]=" << ptr->data << "-->";
            ptr = ptr->next;
	        cout << "end" << endl;
        }
    }
	int erase(int const & data){
		if (this->empty()) throw underflow_error("List is Empty");
		SingleNode<Type> *ptr = headptr;
        SingleNode<Type> *prev = headptr;
        int del = 0;
        while(ptr!=nullptr){
            if(ptr->data == data){
                if(ptr==headptr){
                 headptr = ptr->next; 
                ++del;
                --listSize;
                }
                else{
                    prev->next=ptr->next;
                    ptr = prev;
                    ++del;
                    --listSize;
                }
            }
            prev = ptr;
            ptr = ptr->next;
        }
        CyclicLinkedList::printLst();
        return cout << "Deleted " << del << " nodes." << endl;
	}
		
	
	
};

