#include "LinkedList.h"

int main(int argc, const char * argv[]) {
    
    LinkedList *myLL = new LinkedList();
    
    myLL->insertToTail(1);
    myLL->insertToTail(2);
    myLL->insertToTail(3);

    cout << "Linked list data: ";
    myLL->print();
    cout << "Linked list median element: " << myLL->returnMedian() << endl;
    
    myLL->insertToMedian(10);
    myLL->insertToMedian(20);
    
    cout << "Linked list data: ";
    myLL->print();
    cout << "Linked list median element: " << myLL->returnMedian() << endl;
    
    cout << "Removed tail: " << myLL->removeFromTail() << endl;
    cout << "Linked list data: ";
    myLL->print();
    cout << "Linked list median element: " << myLL->returnMedian() << endl;
    
    cout << "removed median: " << myLL->removeFromMedian() << endl;
    cout << "Linked list data: ";
    myLL->print();
    cout << "Linked list median element: " << myLL->returnMedian() << endl;
    
    cout << "Removed head: " << myLL->removeFromHead() << endl;
    cout << "Linked list data: ";
    myLL->print();
    cout << "Linked list median element: " << myLL->returnMedian() << endl;
    
    return 0;
}
