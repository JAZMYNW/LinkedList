#include <iostream>
#include "LinkedList.h"
#include <math.h>
using namespace std;

 Node::Node(int data){
    this->data = data;
 }



    //constructor
    LinkedList::LinkedList(){
        head = NULL;
        tail = NULL;
        median = NULL;
        size = 0;
    }                               
   
    //Destructor
    LinkedList::~LinkedList(){
        Node *current = head;
        Node *temp = NULL;
        while(current->next){
            temp = current->next;
            delete current;
            current = temp;
        }

    }                                

    // insert node with data to tail of list
    void LinkedList::insertToTail(int data) {
        Node *newNode = new Node(data);
	if(size ==0){
        newNode ->next = NULL;
        newNode->prev = NULL;
        tail = newNode;
	head = newNode;
        size++;
	}
	else{
	newNode->next = NULL;
	newNode->prev = tail;
	tail->next = newNode;
	tail = newNode;
	size++;
	}
    }                  
    
    // remove node from tail of list, return its data
    int LinkedList::removeFromTail()  {
       if(size==1){
	Node *current = tail;
	int taildat = tail->data;
        tail=NULL;
        head=NULL;
        delete current;
	    size--;	
	    return taildat;
	} 
    else if(tail==NULL){
	cout<<"Error, list is empty!"<< endl;
	return 0;
	} else{} 
	Node *current = tail;
	int taildat = tail->data;
	tail = tail->prev;
	tail->next = NULL;
	delete current;
	size--;
	return taildat;
    }
	


                        
    
    // insert node with data to head of list
    void LinkedList::insertToHead(int data){
 	Node *newNode = new Node(data); 
    if(size!=0){
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        size++;
    } else{
	newNode->next = NULL;
	newNode->prev = NULL;
	tail = newNode;
	head = newNode;
	}
    }
    // remove node from head of list, return its data
     int LinkedList::removeFromHead(){  
        if(size==1){
        Node *current = head;
        int headdat = head->data;
        tail=NULL;
        head=NULL;
        delete current;
        size--;
        return headdat;
        } else if(head==NULL){
        cout<<"Error, list is empty!"<< endl;
	    return 0;
        } else{
        Node *current = head;
        int headdat = head->data;
        head = head->next;
        head->prev = NULL;
	    delete current;
	    size--;
	    return headdat;
    }
     }
    
    

    void LinkedList::insertToMedian(int data){
        Node *temp = head;
        int mednum = ceil(size/2);
        while(mednum--){
            temp = temp->next;
        }
        Node *newNode = new Node(data);
        Node *temp1 = temp->next;
        Node * temp2 = temp->prev;
        temp2->next = newNode;
        newNode->prev = temp2;
        temp->prev = newNode;
        newNode->next = temp;
        size++;

        

    }                  
    // remove node from meidan position of list, return its data
    int LinkedList::removeFromMedian(){
        Node *current = head;
        int mednum = ceil(size/2);
        while(mednum--){
            current = current->next;
        }
	int currentdat = current->data;
        Node *temp1= current->next;
        Node *temp2 = current->prev; 
        temp1->prev = current->prev;
        temp2->prev = current->next;
        delete current;
        size--;
	return currentdat;


    }                         
    
    // prints the data of the median position
    int LinkedList::returnMedian(){
        Node *current = head;
        int mednum = ceil(size/2);
        while(mednum--){
            current = current->next;
        }
        return current->data;
    }                             
  
   // prints linked list data
    void LinkedList::print(){
        Node *iter=head;
	for(int i = 0;i<size;i++){
            cout<< iter->data << " ";
            iter = iter->next;
	}
	cout<<endl;
	delete iter;
    }                                   // prints linked list data
   

 
