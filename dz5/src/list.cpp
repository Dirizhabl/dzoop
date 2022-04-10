#include "list.hpp"
#include <iostream>
#include <vector>

list::list()
{

}

list::~list()
{
}

void list::push_front(int n)
{
    Node *temp = new Node{n, head};
    if(head!=nullptr)
    {
        Node *it = head;
        while(it->next != head)
            it = it->next;

        head = new Node{n, head};
        it->next = head;

        return;
    }
    head = temp;
    head->next = head;
    
    
}

void list::display()
{
    if(head==nullptr)
        return;
    Node *it = head;
    std::cout<<"list: ";
    fflush(stdout);
    do
    {
        std::cout << it->n << " ";
        fflush(stdout);
        it = it->next;
    }while(it->next != head);
    std::cout << it->n;
    std::cout<<std::endl;
}

void list::reverse()
{
    Node *it = head, *prev, *next;
    std::vector<Node *> vec;
    while(it->next != head)
    {
        it = it->next;
    }
    prev = it;
    it = head;
    while(it->next != head)
    {
        next = it->next;
        it->next = prev;
        prev = it;
        it = next;
    }
    next = it->next;
    it->next = prev;
    prev = it;
    it = next;
    
    head = head->next;

}

double list::avg()
{
    Node *it = head;
    int sum=0;
    size_t count = 1;
    while (it->next!=head)
    {
        sum+=it->n;
        it=it->next;
        count ++;
    }
    sum+=it->n;

    return (double)sum/(double)count;
    
}

Node *list::max()
{
    Node *max = head, *it = head->next;

    while(it!= head)
    {
        if(it->n > max->n)
            max = it;
        it = it->next;
    }
    return max;
}
Node *list::min()
{
    Node *min = head, *it = head->next;

    while(it!= head)
    {
        if(it->n < min->n)
            min = it;
        it = it->next;
    }
    return min;
}

void list::delete_below_avg()
{
    double avg = this->avg();
    Node *it=head;
    while (it->next != head)
    {
        if(it->n < avg)
            erase(it->n);
        it = it->next;
    }
        if(it->n < avg)
            erase(it->n);
    
}
bool list::erase(int n)
{
    Node *it = head->next, *prev = head;
    if(it->n == n)
        {
            while (it->next != head)
            {
                it = it->next;
            }
            it->next = head->next;
            //delete head;
            head = it->next;
            return true;
        }
    while (it != head)
    {
        if(it->n==n)
        {
            prev->next = it->next;
            //delete it;
            return true;
        }
        prev = it;
        it = it->next;
    }
    return false;
}