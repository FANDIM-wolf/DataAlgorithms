#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Node {
public:
    int data;
    Node* next;
};

void printList(Node* n)
{
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

void append(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
 
    Node *last = *head_ref; /* used in step 5*/
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = NULL;
 
    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
 
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
    {
        last = last->next;
    }
 
    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

//function to find node in linked list
void findNode(Node** head_ref, int key)
{
     
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        
		cout<< "Node was found:"<< temp->data<<endl;             // print head
        return;
    }
 
    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Print found node 
    cout<< "Node was found:"<< temp->data<<endl;  
   	
    }
}


//function to delete node from linked list
void deleteNode(Node** head_ref, int key)
{
     
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
 
    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    // Free memory
    delete temp;
    }
}
