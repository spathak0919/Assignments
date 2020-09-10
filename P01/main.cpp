//////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Sandesh Pathak
// Email:            sapthak0919@my.msutexas.edu
// Label:            L02
// Title:            Array Based Stack 
// Course:           2143-OOP
// Semester:         Fall 2020
//
// Description:
//       Array based stack .
//
// Usage:
//       Example implementation of an array based stack that holds integers.
//
// Files:            
//       None
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * Stack
 * 
 * Description:
 *      Integer array based stack implementation
 * 
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
 *      
 */
class Stack {
private:
    int *S;       //array pointer
    int capacity; //max stack size
    int top;      //current top (index)
    int size;     //current num items
public:
    /**
     * Stack:
     *    Constructor.
     * Params:
     *    void
     * 
     * Returns:
     *     Void
     */
    Stack() {
        capacity = 10;          // set array size
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
    }

    /**
     * Stack:
     *    Constructor.
     * Params:
     *    int : capacity
     * 
     * Returns:
     *     Void
     */
    Stack(int cap) {
        capacity = cap;         // set array size      
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
    }

    /**
     * Push:
     *    Push item onto stack.
     * Params:
     *    int : data
     * 
     * Returns:
     *     Void
     */
    void Push(int data)
     {
       if(Full())
       {
         int* newstack = new int[capacity * 2];
         for(int i=0;i< capacity;i++)
         {
           newstack[i] =S[i];
         }
         delete[] S;
         S= newstack;
         capacity=capacity*2;
       }
        top++;              // move top of stack up
        size++;             // increment size
        S[top] = data;      // add item to array
    }

    /**
     * Pop:
     *    remove item from stack.
     * Params:
     *    void
     * 
     * Returns:
     *     int
     */
    int Pop() {
      if (Empty())
      {
        cout<<"Error. Empty stack"<<endl;
        return -1;

      }
        int data = S[top];  // pull item from stack
        top--;              // shrink the stack
        size--;             // update our size
        return data;        // send item back
    }

    /**
     * Empty:
     *    is the stack empty?
     * Params:
     *    void
     * 
     * Returns:
     *     bool : true == stack is empty
     */
    bool Empty() {
        //return size == 0;
        return top == -1;
    }

    /**
     * Full:
     *    is the stack full?
     * Params:
     *    void
     * 
     * Returns:
     *     bool : true == stack is full
     */
    bool Full() {
        return top == capacity - 1;
    }

    /**
     * Print:
     *    Used so we can inspect our stack.
     * Params:
     *    void
     * 
     * Returns:
     *     void
     */    
    void Print() {
        for (int i = top; i >= 0; i--) {
            cout << S[i] << endl;
        }
    }

    /**
     * Overloaded ostream <<
     *    Lets us print a stack using cout
     * Params:
     *    ostream &os   : instance of ostream passed in by reference
     *    const Stack   : instance of stack passed in using const so 
     *                    it cannot be changed
     * 
     * Returns:
     *     ostream 
     */
    friend ostream &operator<<(ostream &os, const Stack s)
     {
        for (int i = s.top; i >= 0; i--) {
            os << s.S[i] << endl;
        }
        return os;
    }
};

int main()
{
    Stack S1;           // calls default constructor
   ifstream infile;
    infile.open("sandesh.txt");
    string PushOrPop;                    
    int value;                              
    while (infile >> PushOrPop)            
    {
        if (PushOrPop == "push")            //reads push
        {
            infile >> value;                 
            S1.Push(value);      
        }
        if (PushOrPop == "pop")            //reads pop
        {
            S1.Pop();                 
        }
    }
    infile.close();                         //close file
    S1.Print();                              //prints stack 

    return 0;
}
