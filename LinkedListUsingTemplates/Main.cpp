/*
* Name: Mansi Patel
* Purpose: The purpose of this program is implement the linked list using templates.
*/

#include <iostream>
using namespace std;

/*
* This is A struct called Node
* data member of struct uses templates (T) and
* next is pointer to type Node
*/
template <typename T>
struct Node
{
    T data;
    Node* next;
};

/*
* LinkedList class implements a singly linked list
*/
template <class T>
class LinkedList
{
private:
    Node<T>* _head; //private data member _head
    Node<T>* _tail; //private data member _tail
public:
    LinkedList() //constructor with initialization of _head and _tail as null
    {
        _head = NULL;
        _tail = NULL;
    }
    void add(T value);
    void remove(T value);
    T head();
    T tail();
    void show();
};

/*
* add(), which takes an argument value that is added to the linked list and adds the value to the head of the linkedlist
*/
template <class T>
void LinkedList<T>::add(T value)
{
    Node<T>* newNode = new Node<T>;
    newNode->data = value;
    newNode->next = NULL;
    //newNode->next = _head; //inserting at the head
    //_head = newNode;
    if (_head == NULL)
    {
        _head = newNode;
        _tail = newNode;
        newNode = NULL;
    }
    else
    {
        _tail->next = newNode;
        _tail = newNode;
    }

}

/*
* remove(), takes an argument value and if it is found in the linked list removes it from the linked list.
*/
template <class T>
void LinkedList<T>::remove(T value)
{
    //Node<T> *currentNode;  //initialization of currentNode pointer
    Node<T>* previousNode; //initialization of previousNode pointer
    Node<T>* deleteNode;   //initialization of deleteNode pointer
    _tail->data = _tail->data;

    //if value is in the first node
    if (_head->data == value)
    {
        //set a deleteNode to the first node
        deleteNode = _head;

        //change the _haed pointer to the second node/next node
        _head = _head->next;

        //delete the node indicated by deleteNode
        delete deleteNode;
        deleteNode = NULL;
    }
    else
    {
        //set a previousNode to the _head
        previousNode = _head;

        //check if the previousNode->next is not null and the previousNode->next != value we are trying to delete
        while (previousNode->next != NULL && previousNode->next->data != value)
        {
            //set the previousNode to the next node in the list.
            previousNode = previousNode->next;

            //check if previousNode->next == NULL then set the _tail as lastNode (previousNode)
            if (previousNode->next == NULL)
            {
                _tail = previousNode;
            }
        }
        if (previousNode->next != NULL) //check if it is not end of the list
        {
            deleteNode = previousNode->next;       //assign deleteNode = previousNode->next
            previousNode->next = deleteNode->next; //assign the previousNode->next to deleteNode->next

            //check if previousNode->next == NULL then set the _tail as lastNode (previousNode)
            if (previousNode->next == NULL)
            {
                _tail = previousNode;
            }
            //delete the node indicated by deleteNode
            delete deleteNode;
            deleteNode = NULL;
        }
        else
        {
            cout << "Sorry, could not find and item in the list. Please try again." << endl;
        }
    }
}

/*
* head() returns the head of the linked list
*/
template <class T>
T LinkedList<T>::head()
{
    return _head->data;
}

/*
* tail() returns the tail of the linked list
*/
template <class T>
T LinkedList<T>::tail()
{
    //alternate method: without tail
    // Node<T> *currentNode = _head;
    // Node<T> *nextNode = _head->next;
    // while (nextNode != NULL)
    // {

    //     currentNode = nextNode;
    //     nextNode = currentNode->next;
    // }
    // return currentNode->data;
    return _tail->data;
}

/*
* show(), displays all the items of the linked list
*/
template <class T>
void LinkedList<T>::show()
{
    Node<T>* currentItem = _head;
    while (currentItem != NULL)
    {
        cout << currentItem->data << " ";
        currentItem = currentItem->next;
    }
    cout << endl;
}

int main()
{
    LinkedList<int> li;
    Node<int>* head = NULL;
    for (int i = 10; i > 0; --i)
    {
        li.add(i);
    }
    cout << "Default LinkedList:" << endl;
    li.show();
    cout << "head is " << li.head() << endl;
    cout << "tail is " << li.tail() << endl;

    li.remove(10);
    //added as part of testing and future reference
    cout << "After removing head(10 here), list is: " << endl;
    li.show();
    cout << "new head is " << li.head() << endl;
    cout << "new tail is " << li.tail() << endl;

    li.remove(5);
    //added as part of testing and future reference
    cout << "After removing middle element(5 here), list is: " << endl;
    li.show();
    cout << "new head is " << li.head() << endl;
    cout << "new tail is " << li.tail() << endl;

    li.remove(1);
    //added as part of testing and future reference
    cout << "After removing last element(1 here), list is: " << endl;
    li.show();
    cout << "new head is " << li.head() << endl;
    cout << "new tail is " << li.tail() << endl;

    cout << "Final LinkedList:" << endl;
    li.show();
    //added as part of testing and future reference
    cout << "head is " << li.head() << endl;
    cout << "tail is " << li.tail() << endl;

    return 0;
}