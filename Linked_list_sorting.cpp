#include <iostream>
#include <cctype> //For converting lowercase gender acronym into uppercase.
using namespace std;

class Sorting_Algorithms{

private:
    struct Student{
        char firstname[20]; //Variables of Student structure.
        char lastname[20];
        unsigned int age;
        char gender;
        int level;
        Student *next; 
    };
    int length, quantity; //Quantity is for declaring the number of students.
    Student *head, *tail;

public:

    Sorting_Algorithms(){

        head = tail = NULL;
        length = 0;

    }

    void add_node(){ //Adding Student nodes here. We are going to set values for variables.
        
        char gender_acronym;
        cout << "How many students you want to enter: ";
        cin >> quantity;
        cout << "\n";
        for (int x = 0; x < quantity; x++){
            Student *new_student_node = new Student; //Creating new student.
            cout << "Enter the firstname of student: ";
            cin >> new_student_node->firstname;
            cout << "\n" << "Enter the lastname of student: ";
            cin >> new_student_node->lastname;
            cout << "\n" << "Enter the age of student: ";
            cin >> new_student_node->age;
            cout << "\n" << "Enter the gender of student: (F/M-f/m) ";
            cin >> gender_acronym;
            gender_acronym = toupper(gender_acronym); //turning acronym into uppercase.
            while (gender_acronym != 'F' && gender_acronym != 'M'){
                    
                cout << "\n" << "Please enter a valid gender acronym (F/M-f/m): ";
                cin >> gender_acronym;
                gender_acronym = toupper(gender_acronym);
            }                 
            new_student_node->gender = gender_acronym;
            cout << "\n" <<"Enter the level of student: ";
            cin >> new_student_node->level;
            new_student_node->next = NULL; //The last node's next pointer will be NULL because there is no other nodes which are on the front.

            if (length == 0){
                head = tail = new_student_node;
            }

            else{
                tail->next = new_student_node;
                tail = new_student_node;
            }            

            length++;
        }

    }

    void bubbleSort(){
        
        Student *student_queue1, *student_queue2, *student_queue3; //queue 1 is for reassigning next pointer.
        
        for (int index = 0; index < length; index++){

            student_queue1 = NULL;
            student_queue2 = head;
            student_queue3 = head->next;
            for (int n = 1; n < (length-index); n++){

                if (student_queue2->age > student_queue3->age){

                    if (n == 1){ //for definining new head.

                        student_queue2->next = student_queue3->next;
                        student_queue3->next = student_queue2;
                        head = student_queue1 = student_queue3;
                        student_queue3 = student_queue2->next;
                        continue;
                    }

                    student_queue2->next = student_queue3->next;
                    student_queue3->next = student_queue2;
                    student_queue1->next = student_queue3;
                    student_queue3 = student_queue2->next;
                    student_queue1 = student_queue1->next;
                    if (student_queue3 == NULL){

                        tail = student_queue2;
                    }
                    continue;
                }
                student_queue3 = student_queue3->next; //moving to the next nodes.
                student_queue1 = student_queue2;
                student_queue2 = student_queue2->next;
                
            }   
        }
    }

    void insertionSort(){
        
        Student *current, *previous, *temp;
        Student *dummy = new Student; //we have to create a new student structure as dummy.
        
        dummy->next = previous = head;
        current = head->next;

        while (current != NULL){
            
            if (current->age >= previous->age){

                previous = current;
                current = current->next;
                continue;
            }
            temp = dummy; //temp next's age will be compared with current's age.
            
            while (current->age > temp->next->age){ //from beginning to the case where current's age is lesser than temp next's age.
                temp = temp->next;
            }
            previous->next = current->next;
            current->next = temp->next;
            if (temp->next == head){
                head = current;
            }
            temp->next = current; //moving to next nodes.
            current = previous->next;
        }
    }

    void selectionSort(){

        Student *dummy = new Student;
        Student *current, *small, *temp, *temp_holder, *border, *small_next_address;
        dummy->next = head; //temp_holder and small_next_address are for storing pointer address data for manipulating next pointer values.
        border = dummy;
        temp = border;

        while (border->next->next != NULL){ //Until two swappable nodes.
           
            temp = border;
            current = border->next;
            small = current;
            while (current != NULL){
                
                if (current->age < small->age){ //storing data for pointer manipulation. Because temp is always changing. 
                    small = current;
                    small_next_address = small->next;
                    temp_holder = temp; 
                    
                }
                current = current->next;
                temp = temp->next;
            }
            if (small != border->next){ 
                if (border->next->next == small){ //Special case for if the two swappable numbers come right after the border.
                    temp_holder->next = small_next_address;
                    small->next = temp_holder;
                    border->next = small;
                }
                else{
                    small->next = border->next->next;
                    border->next->next = small_next_address;
                    temp_holder->next = border->next;
                    border->next = small;
                }
            }

            border = border->next; //moving border to next node.
        }

        head = dummy->next;
    }

    void Print(){

        int student_queue = 1;
        Student *student_node = head;
        while (student_node != NULL){
            string name = student_node->firstname;
            string surname = student_node->lastname;
            int age_out = student_node->age;
            char student_gender = student_node->gender;
            int school_year = student_node->level;
            
            cout<<student_queue<<"-name: "<<name<<" surname: "<<surname<<" age: "<<age_out<<" gender: "<<student_gender<<" school year: "<<school_year;
            cout<<"\n";
            student_node = student_node->next;
            student_queue++;
        }
    }

};

int main(){

    Sorting_Algorithms Necmettin;
    int selection;
    bool loop_status = true;

    Necmettin.add_node();
      
    cout << "\n" << "~~ WELCOME Sorting Algorithms program ~~"<< endl;
    cout << "Select a sorting algorithm and enter the number of the algorithm you selected: " << endl;
    cout << "1- Bubble Sort" << "\n" << "2- Insertion Sort" << "\n" << "3- Selection Sort" << endl;

    while (loop_status == true){
        
        cin >> selection;
        cout << "\n";

        switch (selection){

            case 1:{
                Necmettin.bubbleSort();
                Necmettin.Print();
                return 0;
            }

            case 2:{
                Necmettin.insertionSort();
                Necmettin.Print();
                return 0;
            }

            case 3:{
                Necmettin.selectionSort();
                Necmettin.Print();
                return 0;
            }

            default:{
                cout << "\n" << "Invalid selection. Please enter a valid selection: " << endl;
                
            }

        }
        continue;
    }

    return 0;
}
