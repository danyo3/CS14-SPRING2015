//Name: Danny Diep
//SID: 861146918
//Date: 4-16-20-15
#ifndef _LAB2_H_
#define _LAB2_H_

#include <forward_list>

using namespace std;

template <typename Type> 
class Node
{
    public:
    Type value;
    Node<Type> * next;
    
    Node(Type val)
    :value(val), next(0)
    {}
};

bool isPrime(int i);
int primeCount(forward_list<int> lst);



template <typename Type> 
class List
{
    private:
        Node<Type>* head;
        Node<Type>* tail;
    
    public:
        List()
        {
            head = 0;
            tail = 0;
        };
        void elementSwap(List<Type>lst, int pos)
        {
            Node<Type> *temp = head;
            Node<Type> *temp2 =0;
            Node<Type> *prev = head;
            if (pos < 0)
            {
                return;
            }
            if (pos >= size()-1)
            {
                return;
            }
            for (int i = 0; i < pos; ++i)
            {
                temp = temp->next;
            }
            for (int i = 1; i < pos; ++i)
            {
                prev = prev->next;
            }
            temp2 = temp->next;
            if (pos == 0)
            {
                
                temp->next = temp->next->next;
                temp2->next = temp;
                head = temp2;
                return; 
            }
            else
            {
                if (temp->next == tail)
                {
                    temp->next = 0;
                    tail->next = temp;
                    prev->next = tail;
                    return; 
                }
                else
                {
                    prev->next = temp->next;
                    temp->next = temp->next->next;
                    temp2->next = temp;
                }
            }
            return;
        };
        
    void push(Type str)
    {
        Node<Type> *temp = 0;
        temp = new Node<Type>(str);
        if (head == 0)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    };
    void display() const
    {
        Node<Type> * curr;
        if (head == 0)
        {
            return;
        }
        for(curr = head; curr != 0; curr = curr->next)
        {
            if (curr->next != 0)
            {
                cout << curr->value << " ";
            }
            else
            {
                cout << curr->value;
            }
        }
        cout << endl;
    };
    int size() const
    {
        int size = 0;
        if (head == 0)
        {
            //cout << "Error No Elements\n";
            return size;
        }
        Node<Type> *curr =0;
        for (curr = head; curr != 0; curr = curr->next)
        {
            //cout << head->value;
            size ++;
        }
        return size;
    };
    
 
};
template <typename Type>
forward_list<Type>listCopy(forward_list<Type> L, forward_list<Type>& P)
{
    if (L.empty() == true)
    {
        if (P.empty() == true)
        {
            return P;
        }
        for (auto it = P.begin(); it != P.end(); it++)
        {
            P.pop_front();
        }
        return P;
    }
    if (P.empty() == true)
    {
        for (auto it = L.begin(); it != L.end(); it++)
        {
            cout << *it << " ";
            P.push_front(*it);
        }
        return P;
    }
    else
    {
        for (auto it = P.begin(); it != P.end(); it++)
        {
            P.pop_front();
        }
        for (auto it = L.begin(); it != L.end(); it++)
        {
            P.push_front(*it);
        }
        return P;
    }
    
    
}
template <typename Type> 
void printLots(forward_list<Type> L, forward_list<Type> positions)
{
    if (L.empty() == true)
    {
        return;
    }
    
    auto it = L.begin();
    int counter = 0;
    int sz = 0;
    for (auto it = L.begin(); it != L.end(); it++)
    {
        sz++;
    }
    positions.sort(less<int>());
    for(auto pos = positions.begin(); pos != positions.end(); pos++)
    {
        if (*pos >= sz)
        {
            return;
        }
        while(counter != *pos)
        {
            counter++;
            it++;

        }
        if(counter == *pos)
        {
            std::cout << *it << " ";
        }

    }
}
#endif
