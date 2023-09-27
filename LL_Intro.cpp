#include <iostream>
#include <cstdlib>


class Node
{
public:
    Node* next;  // Your code here
    int data;
};

using namespace std;

class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    void add(int data);
    void remove(int data);
	  int sum();
    void display();
};

// Initialize the lists management information
LinkedList::LinkedList(){
    this->length = 0;// Your code here
    this->head =  NULL;// Your code here
}

// Clear the list management information and release all allocated Nodes
LinkedList::~LinkedList(){
   Node* current = this->head;
    while(current){
        this->head = current->next;
        this->length -= 1;
		delete current;
		current = this->head;
    }
    std::cout << "LIST DELETED: " << this->length << std::endl;
}

// Add a new node that contains 'data'
void LinkedList::add(int data){
        Node *tmp = new Node;
        Node *current = head;

        tmp->data = data;
        tmp->next = NULL;
        
         if(!head){
           head=tmp;
            }else{
              tmp->next=current;
              head=tmp;
              
        //     while(current->next)
        //       current = current->next;
        //     current->next=tmp;
        //   }
        }
        this->length+=1;
}


 /*       if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;*/
  // Your code here




// Locate the node that contains 'val' in the list and remove the node
void LinkedList::remove(int val){
  // Your code here
  Node *current=head;
  Node *tmp;
    Node* temp;
  //cout<<"remove"<<endl;

if(current){    
  if(current->data==val){
      tmp=current->next;
      head=tmp;
      free(current);
      //cout<<"removed head"<<endl;
      this->length-=1;
      return;
    }
while(current){

  if(current->next->data==val){
  tmp=current->next->next;
  temp=current->next;
   current->next=tmp;
 //  cout<<val<<endl;
  free(temp);
  this->length-=1;
 return;
 //if()
  }
 current = current->next; 
 //cout<<"done with first it"<<val<<endl;
}
//temp->next = NULL;
}
}


// Sum all the integer data elements in the list
int LinkedList::sum(){

int sum=0;
Node *current = head;
while(current){
  sum+=current->data;
  current = current->next;
}

  // Your code here

	return sum;
}

// print the entire list's data
void LinkedList::display(){
    Node* current = this->head;
    int i = 1;
    while(current){
        std::cout << i << ": " << current->data << std::endl;
        current = current->next;
        i++;
    }
}


// Main performs various list operations and reports results
int main(int argc, char const *argv[])
{
    LinkedList* list = new LinkedList();
	int j = 49;
	int sum = 0;
	int testSum = 0;

	// Install inital values in list
    for (int i = 0; i < 50; i += 2)
    {
		testSum = testSum + i + j;
        list->add(i);
        list->add(j);
		j -= 2;
    }
	
    list->display();
	std::cout << "List initial sum: " << testSum << std::endl;
	sum = list->sum();
	std::cout << "List initial sum: " << sum << std::endl;
	if (sum != testSum)
	{
		std::cout << "Ooops!  Initialization failed" << std::endl;
		return(1);
	}

	// Test 1
	std::cout << std::endl << "- - - -" << std::endl;
	list->remove(2);
    list->display();
    std::cout << "List Length: " << list->length << std::endl;
	sum = list->sum();
	std::cout << "sum 1: " << sum << std::endl;
	
	// Test 2
	std::cout << std::endl << "- - - -" << std::endl;
	for (int i = 10; i < 20; i++)
	{
		list->remove(i);
	}
    list->display();
    std::cout << "List Length: " << list->length << std::endl;
	sum = list->sum();
	std::cout << "sum 2: " << sum << std::endl;

    delete list;
    return 0;
}