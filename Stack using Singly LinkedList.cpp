#include <iostream>
using namespace std;

class Node{
      private:
          int data;
          Node *next;
      public:
          Node()
          {
              data = 0;
              next = NULL;
          }
          Node(int data)
          {
              this -> data = data;
              next = NULL;
          }
          void setData(int data)
          {
              this -> data = data;
          }
          void setNext(Node *next)
          {
              this -> next = next;
          }
          int getData()
          {
              return this -> data;
          }
          Node* getNext()
          {
              return this -> next;
          }
};

class LinkedList{
       private:
         Node *head;
       public: 
         LinkedList()
         {
             head = NULL;
         }
         bool isEmpty()
         {
           return (head == NULL);  
         }
         void inserAtBeginning(int val)
         {
             if(isEmpty())
             {
                 head = new Node(val);
             }
             else
             {
                 Node *t = new Node(val);
                 t -> setNext(head);
                 head = t;
             }
         }
         void removeFromBeginning()
         {
             Node *t;
             t = head -> getNext();
             delete t;
             head = t;
         }
          void getFirstElement()
          {
             cout << "\nPrinting 1st Element:" << endl;
             cout << (head -> getData());
          }
          Node* getLastElement()
           {        
              Node *temp = head;
              if(temp != NULL)
              {
               while(temp -> getNext() != NULL)
               {
                   temp = temp -> getNext();
               }
          }
           return temp;
           }
           void printAllElements()
           {
               if(!isEmpty())
               {
                   Node *temp = head;
                   while(temp != NULL){
                       cout << temp -> getData() << "->";
                       temp = temp -> getNext();
                   }
                   cout << "NULL\n";
               }
           }
           void getLength()
           {
               if(!isEmpty())
               {
                   int i = 0;
                   Node *temp = head;
                   while( temp != NULL)
                   {
                       temp = temp -> getNext();
                       i++;
                   }
                   cout << i;
               }
           }
           void insertNodeAtEnd(int val)
           {
               Node *t1 = new Node (val);
               if(isEmpty())
               {
                   head = t1;
               }
               else
               {
                   Node *temp = head;
                   while(temp -> getNext() != NULL)
                   {
                       temp = temp -> getNext();
                   }
                   temp -> setNext(t1);
               }
           }
           void removeFromLast(){
               Node *temp = head;
               Node *temp2 = head -> getNext();
               
                 while(temp2 -> getNext() != NULL)
                 {
                     temp = temp -> getNext();
                     temp2 = temp2 -> getNext();
                 }
                delete temp2;
                temp -> setNext(NULL);
           }
};

class Stack{         //LIFO
       private:
          LinkedList l1;
       public:
          void push(int val)
          {
              l1.insertNodeAtEnd(val);
          }
          bool isEmpty()
          {
              return l1.isEmpty();
          }
          void print()
          {
              l1.printAllElements();
          }
          int pop()
          {
              int x = l1.getLastElement() -> getData();
              l1.removeFromLast();
              return x;
          }
          int top()
          {
              int b;
              b = l1.getLastElement() -> getData();
              return b;
          }
};
int main(){
    Stack s1;
//  cout<< s1.isEmpty() << endl;
    s1.push(69);
    s1.push(78);
    s1.push(99);
    s1.print();
    cout << s1.pop() << endl;
    s1.print();
    cout << s1.top();
}