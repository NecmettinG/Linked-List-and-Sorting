#include <iostream>
using namespace std;

template <class Necmettin> //It allows to use different datatypes for same variable name. However; THE CODE ONLY WORKS WITH INTEGER.

class LinkedList{

private:
	struct Node{ //Each node will be created from Node structure.

		Necmettin item;
		Node *next; //Next node's pointer address will be stored here, inside of every previous Node structures.
	};
	int length;
	Node *head, *tail; //Linked list will have head and tail address.

public:
	LinkedList(){ //Constructor for LinkedList class. Automatically defines the values of instance variables when a new object is created.

		head, tail = NULL;
		length = 0; //List's length will start from 0;
	}

	void Add(){ //For adding element to linked list:
		
		Necmettin element;
		Node *new_node_of_list = new Node;
		cout << "Enter the element you want to append:";
		cin >> element;
		cout << "\n";
		new_node_of_list->item = element; //Assigning the element's value to new_node_of_list's item variable.
		new_node_of_list->next = NULL; //Address for next node is NULL.

		if (length == 0){ //If list's length equals to 0, head and tail address will be same, Which are the address of only one node.

			head = tail = new_node_of_list;
		}

		else{
			tail->next = new_node_of_list; //Assign the new tail's memory address to previous tail node's pointer section.
			tail = new_node_of_list; //Specify your new tail as the tail.
		}
		length++; //Length will be increased when we try to append a new node.
	}

	void Delete(){ //For deleting elements from the list:

		Necmettin element;
    	Node *primary = NULL; //Primary will be on behind right before secondary. It will start from NULL because no node points the head node. 
    	Node *secondary = head; //Secondary will start from head node.
    	bool is_found = false; //For "couldn't be found" message.

    	cout << "Enter the element you want to delete:";
    	cin >> element;
    	cout << "\n";

		while (secondary != NULL){ //It will work until secondary's address will equal to NULL.
			
			if (secondary->item == element){ //If secondary's item equals to the element that we want to delete:
				cout << element << " has been found. Deleting..." << "\n";
				is_found = true;
				Node *temp = secondary->next; //Creating a temp pointer node and making it equal to the node which comes right after secondary.
				delete secondary; //deleting secondary.
				length--; //length will be decreased.
				
				if (temp != NULL){ //If secondary is not the tail node:
					if (primary == NULL){ //This is for starting section. If we delete head node.
						
						primary = temp;
						head = primary;
						secondary = temp->next;
						break;
					}
					else{ //This section will be ran after starting section.

						secondary = temp;
						primary->next = secondary;
						break;
					} //When we delete secondary's node, Primary node will point to new next node and new secondary will equal to that node.
				}
			
				else{ //If secondary is the tail node:
					
					if (length == 0){ //If no node left in linked list:

						cout << "No nodes exist in the linked list. Please append node." << "\n";
						head = tail = NULL; //head and tail will equal to NULL. Unless we add a new element.
						return;
					}	

					primary->next = NULL;
					tail = primary;
					if(length == 1){ //If length equals to 1:
						head = tail; //head and tail will be on same address.
						primary = NULL;
						secondary = head;
						break;
					}
					secondary = NULL;
					break;
				}
			}

			
			primary = secondary; //When an element couldn't be found in secondary node, move primary and secondary to one node ahead.
			secondary = secondary->next;
		}
		
    if (is_found == false) //Warning messages according to is_found and length.
        cout << element << " doesn't exist in linked list." << "\n";
		if (length == 0)
			cout << "No nodes exist in the linked list. Please append node." << "\n";
	}

	void Search(){ //For searching specified element.

		Necmettin element;
		cout << "Enter the element you want to search:";
		cin >> element;
		cout << "\n";
		Node *temp = head; //temp will start from head node.
		int i = 0; //Counter for the quantity of specified element.
		bool loop_status = true; //For loop statement.
		bool is_found = false; //For messages.
		
		while (loop_status == true){

			if (temp == NULL || length == 0){
				loop_status = false;
				break;
			}
			if (temp->item == element){
				is_found = true; //Once element has been found in the list, is_found is going to equal to true.			
				i++; //Increasing the counter.
			}

			
			temp = temp->next;
		}

		if (is_found == false) //For information messages of element's status.
			cout << element << " hasn't been found in linked list." << "\n";

		else{
			cout << "element has been found successfully for " << i << " times." << "\n"; //We are going to use that i counter.
		}
	}

	void Print(){ //For printing all the nodes of the linked list.

		Node *temp = head; //temp will start from the head node.
		
		if (length != 0){ //If length doesn't equal to 0: (This section for printing.)
			cout << "[";
			while (temp!=NULL){

				cout << temp->item << " "; //Printing each node's item.			

				temp = temp->next; //Moving to next node.
			}
			cout << "]" << "\n";
		}
		else{ //If length equals to 0, no node in the list, This message will show up.
			cout << "linked list doesn't exist. Please insert nodes first." << "\n";
		}
	}
};

int main(){

	LinkedList<int>instance; //Running the constructor.
	int choice; //choice for switch-case.
	bool loop_status = true; //For making the interface work constantly.

	while (loop_status == true){

		cout << "\n";
        cout << "===============By Necmettin Gedikli================" << "\n";
        cout << "~~ WELCOME to Linked List program ~~" << "\n";
        cout << "Select and Enter Your Choice from the Menu :" << "\n";
        cout << "1. Add" << "\n";
        cout << "2. Delete"<< "\n";
        cout << "3. Search" << "\n";
        cout << "4. Print" << "\n";
        cout << "5. Exit" << "\n";
        cout << "PLEASE MAKE SURE YOUR CONSOLE'S SIZE IS INCREASED AND ENTER INTEGER ONLY. THANK YOU :)" << "\n";
		cout << "=======================================================" << "\n";
        
        cin >> choice;
        switch(choice){

            case 1:{ //For adding.
				instance.Add();
				cout << "\n";
                break;
            }
            case 2:{ //For deleting.

				instance.Delete();
                cout << "\n";
                break;
            }
            case 3:{ //For searching.

                instance.Search();
                cout << "\n";
                break;
            }
            case 4:{ //For printing.

                instance.Print();
                cout << "\n";
                break;

            }
            case 5:{ //For closing the program.
                
                cout << "\n" << "closing the program..." << "\n"; 
                loop_status = false;
				return 0;
            }
            default:{ //For warning message when we enter invalid selection.

                cout << "\n" << "Invalid selection. Try again." << "\n";
                break;
            }

        }

    }

	return 0;
}