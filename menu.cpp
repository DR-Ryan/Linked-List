#include <iostream>
#include "SingleNode.h"
#include "CyclicLinkedList.h"
#include "DoubleNode.h"
#include "DoublyLinkedList.h"
#include <stdlib.h>


using namespace std;
int main(){
	double val;
	int data;
	int op = 0;
    bool flag = false;
    CyclicLinkedList<double> lis;
    DoublyLinkedList<double> lst;
    while(true){
        cout << "******Menu Program******" << endl;
        cout << "Please select an option." << endl;
        cout << "1. Create Cyclic Linked List." << endl;
        cout << "2. Create Double Linked List" << endl;
        cout << "3. Exit." << endl;
        cout << "--> ";
        cin >> op;
        if (op==3) break;
        else if (op==1){
        	    flag = true;
        	    cout << endl << "List created." << endl;
        	while(true){
        	cout << "******Menu Program******" << endl;
        	cout << "Please select an option." << endl;
        	cout << "1. Insert Element." << endl;
        	cout << "2. Delete Element." << endl;
        	cout << "3. Print List." << endl;
        	cout << "4. Exit." << endl;
        	cout << "--> ";
        	cin >> op;
        	if (op==4) break;
    	    	else if (op==1){
    	    	double data;
                cout << "Enter value to be inserted" << endl;
                cin >> data;
                int op_i;
                cout << "Do you want insert element in the Front or Back of the list ?(1.Front, 2.Back)\n-->";
                cin >> op_i;
                if (op_i==1){
                	lis.push_front(data);
                }
                else {
                	lis.push_back(data);
                	}
           		}
        		else if (op==2){
        		double data;
        		int op_i;
                cout << "Do you want to delete a specific element or the first in the list ?(1.Specific, 2.Front)\n-->";
                cin >> op_i;
                if (op_i==1){
                cout << "Enter value to delete\n-->";
           		cin >> data;
           			try{
            			lis.erase(data);
            	}
            		catch(const exception & e){
            			cout << "error-->" << e.what() << endl;
            		}
                }
                else{
                	try{
						lis.pop_front();
					}
					catch (const exception & e){
						cout << "error-->" << e.what() << endl;
						}
                	} 
        		}
        		else if (op==3){
        		int op_i;
                cout << "Do you want to print the whole list or a specific node?(1.Whole, 2.Specific)\n-->";
                cin >> op_i;
                if (op_i==1){
        				cout << endl;
        					if(lis.empty()== true){
        						cout << "List is empty" << endl;
        						cout << endl;
        					}
        					else{	
        					cout << "Printing out " << lis.count(lis.size()) << " nodes." <<endl;
            				lis.printLst();
            				}
            		}
            		else{
            		int op_i;
                	cout << "Print the first or the last node?(1.First, 2.Last)\n-->";
                	cin >> op_i;
                		if (op_i==1){
						try{
							cout << "First element " << lis.front() << " has an address of " << lis.head() << endl;
						}
							catch (const exception & e){
								cout << "error-->" << e.what() << endl;
							}                		
                		}
                		else{
                			try{
								cout << "Last element " << lis.back() << " has an address of " << lis.tail() << endl;
							}
								catch (const exception & e){
									cout << "error-->" << e.what() << endl;
							}		
                		}
            		}
        		}
    		}
    	}
    	else if (op==2){
        	    flag = true;
        	    cout << endl << "List created." << endl;
        	while(true){
        	cout << "******Menu Program******" << endl;
        	cout << "Please select an option." << endl;
        	cout << "1. Insert Element." << endl;
        	cout << "2. Delete Element." << endl;
        	cout << "3. Print List." << endl;
        	cout << "4. Exit." << endl;
        	cout << "--> ";
        	cin >> op;
        	if (op==4) break;
    	    	else if (op==1){
    	    	double data;
                cout << "Enter value to be inserted" << endl;
                cin >> data;
                int op_i;
                cout << "Do you want insert element in the Front or Back of the list ?(1.Front, 2.Back)\n-->";
                cin >> op_i;
                if (op_i==1){
                	lst.push_front(data);
                }
                else {
                	lst.push_back(data);
                	}
           		}
        		else if (op==2){
        		double data;
        		int op_i;
                cout << "Do you want to delete a specific element or the first in the list ?(1.Specific, 2.Front)\n-->";
                cin >> op_i;
                if (op_i==1){
                cout << "Enter value to delete\n-->";
           		cin >> data;
           			try{
            			lst.erase(data);
            	}
            		catch(const exception & e){
            			cout << "error-->" << e.what() << endl;
            		}
                }
                else{
                	try{
						lst.pop_front();
					}
					catch (const exception & e){
						cout << "error-->" << e.what() << endl;
						}
                	} 
        		}
        		else if (op==3){
        		int op_i;
                cout << "Do you want to print the whole list or a specific node?(1.Whole, 2.Specific)\n-->";
                cin >> op_i;
                if (op_i==1){
        				cout << endl;
        					if(lst.empty()== true){
        						cout << "List is empty" << endl;
        						cout << endl;
        					}
        					else{	
        					cout << "Printing out " << lst.count(lst.size()) << " nodes." <<endl;
            				lst.printLst();
            				}
            		}
            		else{
            		int op_i;
                	cout << "Print the first or the last node?(1.First, 2.Last)\n-->";
                	cin >> op_i;
                		if (op_i==1){
						try{
							cout << "First element " << lst.front() << " has an address of " << lst.head() << endl;
						}
							catch (const exception & e){
								cout << "error-->" << e.what() << endl;
							}                		
                		}
                		else{
                			try{
								cout << "Last element " << lst.back() << " has an address of " << lst.tail() << endl;
							}
								catch (const exception & e){
									cout << "error-->" << e.what() << endl;
							}		
                		}
            		}
        		}
    		}
    	}
    }
	return 0;
}


