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
		if(listSize == 0) {
			cout<< "List is empty" << endl;
			return listSize;
		}
		else{
			return listSize;
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
		SingleNode<Type> *ptr = headptr;
		if (listSize == 0){						//When the list is empty sets all pointers equal to the first node
			headptr = NewNode;					//makes the NewNode the head of the list
			NewNode->next = headptr;			//NewNode ends up pointing to itself because its head of the list
			tailptr = NewNode;					//tailptr is the last element in the list
		}else{							
			do{
				while(ptr->next != headptr){ 	//traverse list to the last node
					ptr = ptr->next;		
				}		
				NewNode->next = headptr;		//sets the NewNode to point to the first node in the list
				ptr->next = NewNode;			//sets the last node to point to the NewNode in the list
				headptr = NewNode;				//makes NewNode the new head of the list
			}while(ptr->next != NewNode);
		}
		++listSize;								//Keeps track of the amount of nodes in our list
		}

	void push_back(const double &val){
		SingleNode<Type> *NewNode = new SingleNode<Type>(val, nullptr);
		SingleNode<Type> *ptr = headptr;
		if(listSize == 0){						//When the list is empty sets all pointers equal to the first node
			headptr = NewNode;					//makes the NewNode the head of the list
			NewNode->next = headptr;			//NewNode ends up pointing to itself because its head of the list
			tailptr = NewNode;					//tailptr is the last element in the list
		}else{
			do{
				while(ptr->next != headptr){		//traverse list to the last node
					ptr = ptr->next;
				}
				NewNode->next = headptr;		//sets the NewNode to point to the first node in the list
				ptr->next = NewNode;			//sets the last node to point to the NewNode in the list	
				tailptr = NewNode;				//updates the tailptr to the NewNode
			}while(ptr->next != NewNode);
		}
		++listSize;
	}
	
	Type pop_front(){
		if (this->empty()) throw underflow_error("List is Empty");
		if (headptr == tailptr) // One node list
    	{
        	delete headptr;
        	headptr = nullptr;
        	tailptr = nullptr;
    	}
		else{
			SingleNode<Type> *tempNode = new SingleNode<Type>(0, nullptr);
			tempNode = headptr->next;
			delete headptr;
			headptr = tempNode;
			tailptr->next = tempNode;
		}
		--listSize;
		if (this->empty()) throw underflow_error("Removed last element in list");
		CyclicLinkedList::printLst();
		return listSize;
	}
	
	void printLst() const{
        SingleNode<Type> *ptr = headptr;
        cout << "Items to be printed " << listSize << endl;
         do{
			cout << "Node=[" <<ptr->ID << "]=" << ptr->data << "-->";
            ptr = ptr->next;
         }while(ptr != headptr);
        cout << "end" << endl;
    }
	
	int erase(int const & data){
		if (this->empty()) throw underflow_error("List is Empty");
		SingleNode<Type> *ptr = headptr;	//locates ptr to be deleted
        SingleNode<Type> *lnkptr = headptr;	//relinks the node that is going ot have its next deleted
        int del = 0;
        int count = 0;					//Keeps track of how many times we've traversed the list
        	while(ptr->data != data){	//Traverses the list look for the data value
        		ptr = ptr->next;
        		count++;
        		if (count > listSize)	//if we searched through the entire list and havent found the data value exits
        		{
        			cout <<"Value is not in List" << endl;
        			return del;
        		}
        	}
            if(headptr == tailptr){			//one node lists
            	delete headptr;
                headptr = nullptr;
                tailptr = nullptr;
                --listSize;
                if (this->empty()) throw underflow_error("Removed last element in list"); //stop automatic call of print
            }else if(ptr == headptr){	//special case when deleteing head ptr
            	++del;
            	/*--listSize;*/
            	cout << "Deleted " << del << " nodes." << endl;
            	pop_front();
            	return del;
        	}else{						//all other deletions
            	while(lnkptr->next != ptr){
            		lnkptr = lnkptr->next;
            	}
                lnkptr->next = ptr->next;
                delete ptr;
            }
            del ++;
            listSize--;
       	 	cout << "Deleted " << del << " nodes." << endl;
        	CyclicLinkedList::printLst();
        return del;
    	}
};

