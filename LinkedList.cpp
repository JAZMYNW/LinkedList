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
        newNode ->next = NULL;
        newNode->prev = tail;
        tail = newNode;
        size++;
    }                  
    
    // remove node from tail of list, return its data
    int LinkedList::removeFromTail()  {
        Node *current = tail;
        Node *temp = tail->prev;
        delete current;
        tail = temp;
        size--;
    }                        
    
    // insert node with data to head of list
    void LinkedList::insertToHead(int data){
        Node *newNode = new Node(data);
        newNode->next = head;
        newNode->prev = NULL;
        head = newNode;
        size++;
    }
    
    // remove node from head of list, return its data
    int LinkedList::removeFromHead(){
        Node *current = head;
        Node *temp = head->next;
        delete current;
        head = temp;
        size--;

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
        Node *temp1= current->next;
        Node *temp2 = current->prev; 
        temp1->prev = current->prev;
        temp2->prev = current->next;
        delete current;
        size--;


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
        while(head->next){
            cout<< head->data << " ";
            head = head->next;
        }
    }                                   // prints linked list data
   

    Node* head;                                     // head of list
    Node* tail;                                     // tail of list
    Node* median;                                   // median of list
    int size;                                       // number of elements in the list
