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
        int mednum;
        if(size%2 ==0){
            mednum = size/2;
        } else {
            mednum = ceil(size/2); }
        Node* current = head;
        for(int i =0;i<mednum; i++){
            current = current->next; // Loop sets current as current median node
        }
        Node *beforemed = current->prev; // node before median node
        Node *newNode = new Node(data);
        newNode->next = current;
        newNode->prev = beforemed;
        beforemed->next = newNode;
        current->prev = newNode;

        

    }                  
    // remove node from meidan position of list, return its data
    int LinkedList::removeFromMedian(){
    int mednum;
        if(size%2 ==0){
            mednum = size/2;
        } else {
            mednum = ceil(size/2); }
        Node* current = head;
        for(int i =0;i<mednum; i++){
            current = current->next; // Loop sets current as current median node
        }
        return current->data;

    }                         
    
    // prints the data of the median position
    int LinkedList::returnMedian(){
        int datstore;
        int mednum;
        if(size%2 ==0){
            mednum = size/2;
        } else {
            mednum = ceil(size/2); }
        Node* current = head;
        for(int i =0;i<mednum; i++){
            current = current->next; // Loop stops at current median node
        }
        Node *tempfirst = current->prev;
        Node *templast = current->next;
        tempfirst->next = templast;
        templast->prev = tempfirst;
        datstore = current->data;
        delete current;
        return datstore;
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
