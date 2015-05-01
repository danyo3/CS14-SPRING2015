#ifndef LAB3_H
#define LAB3_H
#include <iostream>
#include <stack>

using namespace std;
template <typename T>
class TwoStackFixed
{
    private:
    T* array;
    int topmost1;
    int topmost2;
    int sz;
    int max;
    bool maxclaimedby1;
    bool maxclaimedby2;
    public:
    TwoStackFixed<T> (int size, int maxtop)
    {
        sz = size;
        max = maxtop;
        if (maxtop >= size)
        {
            cout << "Error: maxtop out of bounds." << endl;
            return;
        }
        if (maxtop < 0)
        {
            cout <<"Error: out of bounds.\n";
            return;
        }
        array = new T[sz]; // new <type> [size]
        topmost1 = 0; //stack 1 starts at 0
        topmost2 = size - 1; //stack 2 starts at the last index of the array
        maxclaimedby1 = false;
        maxclaimedby2 = false;
    };
    void pushStack1(T value)
    {
        if (topmost1 > max)
        {
            cout << "Error cannot push into stack 2\n";
            return;
        }
        if (topmost1 == max)
        {
            maxclaimedby1 = true;
        }
        if (maxclaimedby2 == true)
        {
            if (topmost1 != max)
            {
                array[topmost1] = value;
                topmost1++;
                display();
                return;
            }
            cout << "Max taken by stack2\n";
            return;
        }
        array[topmost1] = value;
        topmost1++;
        display();
        
    }; //to push element into first stack. //display contents of stack when push/pop
    void pushStack2(T value)
    {
        if(topmost2 < max)
        {
            cout << "Error cannot push into stack 1\n";
            return;
        }
        if(topmost2 == max)
        {
            maxclaimedby2 = true;
        }
        if (maxclaimedby1 == true)
        {
            if (topmost2 != max)
            {
                array[topmost2] = value;
                topmost2--;
                display();
                return;
            }
            cout << "Max taken by stack1\n";
            return;
        }
        
        array[topmost2] = value;
        topmost2--;
        display();
        
        
    }; //to push element into second stack.
    T popStack1()
    {
        if (topmost1 > max)
        {
            cout <<"Element popped: " <<topmost1-1 << endl;
            maxclaimedby1 = false;
        }
        if  (topmost1 == 0)
        {
            cout << "Stack empty\n";
            return;
        }
        T popped = array[topmost1-1];
        topmost1--;
        array[topmost1] = 0;

        return popped;
        
    }; //to pop element from first stack. //display which element was popped. 
    T popStack2()
    {
        if (topmost2 < max)
        {
            cout << "Element popped: " << topmost2 +1 << endl;
            maxclaimedby2 = false;
        }
        if (topmost2 == sz-1)
        {
            cout << "Stack empty\n";
            return;
        }
        T popped = array[topmost2+1];
        topmost2++;
        array[topmost2] = 0;
        return popped;
        
    }; //to pop element from second stack.
    bool isFullStack1()
    {
        if ((maxclaimedby1 == true))
        {
            return true;
        }
        if ((maxclaimedby2 == true) && (topmost1 = max))
        {
            return true;
        }
        return false;
    }; //helper function to check whether first stack is full.
    bool isFullStack2()
    {
        if (maxclaimedby2 == true)
        {
            return true;
        }
        if((maxclaimedby1 == true) && (topmost2 == max))
        {
            return true;
        }
        return false;
    }; //helper function to check whether second stack is full.
    bool isEmptyStack1()
    {
        if (topmost1 == 0)
        {
            return true;
        }
        return false;
    }; //helper function to check whether first stack is empty.
    bool isEmptyStack2()
    {
        if (topmost2 == sz -1)
        {
            return true;
        }
        return false;
    }; //helper function to check whether second stack is empty.
    void display()
    {
        for(int i =0; i <sz; i++)
        {
            if ((i<topmost1) || (i >topmost2))
            {
                cout << array[i] << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    };
};

template <typename T>
class TwoStackOptimal
{
    private: 
    T* array;
    int topmost1;
    int topmost2;
    int sz;
    int max;
    bool maxclaimedby1;
    bool maxclaimedby2;
    public:
    TwoStackOptimal(int size)
    {
        sz = size;
        topmost1 = 0;
        topmost2 = size - 1;
        array = new T[sz]; // new <type> [size]
    };
    void pushFlexStack1(T value)
    {
        if (topmost1 > topmost2)
        {
            cout << "Cannot push into Stack 2\n";
            return;
        }
        array[topmost1] = value;
        topmost1++;
        //cout << "Top: " << topmost1 << endl;
        display();
    }; //to push element into first stack. Display the contents of stack after each push.
    void pushFlexStack2(T value)
    {
        if (topmost2 < topmost1)
        {
            cout << "Cannot push into Stack 1\n";
            return;
        }
        array[topmost2] = value;
        topmost2--;
        display();
    }; //to push element into second stack. Display the contents of stack after each push.
    T popFlexStack1()
    {
        if  (topmost1 == 0)
        {
            cout << "Stack empty cannot pop\n";
            return 0;
        }
        T pop = array[topmost1-1];
        topmost1--;
        return pop;
    }; //to pop element into first stack. Return the popped element and print.
    T popFlexStack2()
    {
        if (topmost2 == sz)
        {
            cout << "Stack empty cannot pop\n";
            return 0;
        }
        T pop = array[topmost2 +1];
        topmost2++;
        return pop;
    }; //to pop element from second stack. Return the popped element and print.
    bool isFullStack1()
    {
        if (topmost1 > topmost2)
        {
            return true;
        }
        return false;
    };// helper function to check whether first stack is full.
    bool isFullStack2()
    {
        if (topmost2 < topmost1)
        {
            return true;
        }
        return false;
    }; //helper function to check whether second stack is full.
    bool isEmptyStack1()
    {
        if (topmost1 == 0)
        {
            return true;
        }
        return false;
    }; //helper function to check whether first stack is empty.
    bool isEmptyStack2()
    {
        if (topmost2 == sz-1)
        {
            return true;
        }
        return false;
    }; //helper function to check whether second stack is empty.
    void display()
    {
        for(int i = 0; i <sz; i++)
        {
            if ((i<topmost1) || (i >topmost2))
            {
                cout << array[i] << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }; //to display contents of array.
};


template <typename T>
void moveAtoB (int n, stack<T>& A, stack<T>& B, stack<T>& C, char a = ' ', char b = ' ' , char c = ' ')
{
    //cout << "......" << endl;
    if (n > 0)
    {
        moveAtoB(n-1, A, C ,B, a, c, b );
        cout << "Moved " << A.top() << " from peg " << a << " to " << c;
        C.push(A.top());
        A.pop();
        moveAtoB(n-1, B, A, C, b, a, c);
        
    }
    
}


template <typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C)
{   
    moveAtoB(n, A, B, C, 'A', 'B', 'C');
};


#endif