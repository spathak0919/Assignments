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
    int *S;         //array pointer
    int capacity;   //max stack size
    int top;        //current top (index)
    int size;       //current num items
    int StartSize;  // initial capacity
    int MaxSize=0;  // initialize maxsize =0
    int LastSize;  //final capacity
    int DoubledAlready =0;

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
        StartSize=capacity;     //start size of array
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
        StartSize=capacity;     // start size of array
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
         cout <<"+:" << capacity << "->" <<capacity*2;
         capacity=capacity*2;

         if (capacity >MaxSize)
         {
           MaxSize=capacity;
         }
         DoubledAlready++;
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

        if((DoubledAlready>0)&& (size<capacity/2))
        {
          int*newStack=new int[capacity/2];
          for(int i =0;i<capacity/2;i++)
          {
            newStack[i]=S[i];
          }
          delete[] S;
          S=newStack;
          cout <<"-:"<<capacity<<"->"<<capacity/2<<endl;
          capacity/=2;
        }
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
      os<<"Overlaoded"<<endl;
    
     
        for (int i = s.top; i >= 0; i--) 
        {
            os << s.S[i] << endl;
        }
        return os;
    }

    /**
    *getStartingSize:
    *return starting size
    *Parameters:
    *void:

    *Returns:
    *int Starting size
    */
    int getStartSize()
    {
      return StartSize;  //return starting size
    }

    /*
    *get maxSize:
    * Return largest size of an array
    *Parms:
    *void

    *returns:
    *int MaxSize
    */
    int getMaxSize()

    {
      return MaxSize;   //return max size
    }

    /*
    *get lastSize:
    * Return final size of an array
    *Parms:
    *void

    *returns:
    *int lastSize
    */
    int getlastsize()
    {
      return capacity;  // final size of na array
    }
};

int main()
{
   
   ifstream infile;
    infile.open("input.txt");     //input file

  ofstream outfile;
  outfile.open("output.txt");     // output file

    cout <<"Name : Sandesh Pathak"<<endl;
    cout<<" Program: P01"<<endl;
    cout<<" Date:15 sep 2020"<<endl;
    string var;                    
    int number;  
    
    Stack S1;     //default constructor called
    while(infile>> var)
    {
      if(var == "pop")
      {
        S1.Pop();
      }
      else if (var == "push")
      {
      infile >>number;
      S1.Push(number);
      }
    }
   
    cout << S1 <<endl;

    outfile<< "Name : Sandesh Pathak"<<endl;
    outfile<<"Program: P01"<<endl;
    outfile<< "Date: 15 sep 2020"<<endl;
    outfile<<endl;

            outfile <<"Start size:" << S1.getStartSize()<<endl;
            outfile <<"Max size:"<<S1.getMaxSize()<<endl;
            outfile <<"Ending Size:"<<S1.getlastsize()<<endl;

            infile.close();
            outfile.close();

    return 0;
}
