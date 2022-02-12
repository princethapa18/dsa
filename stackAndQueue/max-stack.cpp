// Week 51 23 Dec 2021
// Week 1  02 Jan 2022
// Generic Max stack  using templates  
// should have a max() which returns the greatest element in the stack

#include <stack>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T>
class MaxStack 
{
    std::stack<T> element;

    /*
    No need of typedef struct in C++
    --> This doesn't work <--
         template <typename T>
         typedef struct {  } SomeStruct; 

    --> Shadows template parm ‘class T’ error <--
    // template <typename T>
    // struct MaxWithCount
    // {
    //     T max; 
    //     int count;
    // };
    // because class also takes typename T 
    // redeclaring MaxWithcount struct with typename T gives following error 
    // max-stack.cpp:12:11: error:  shadows template parm ‘class T’ template <typename T>
    */

    template <typename T1>
    struct MaxWithCount
    {
        T1 max;
        int count;
    };
    std::stack<MaxWithCount<T> > cached_max_with_count;  // this is okay because we are just passing the same type T
public:
    bool Empty() const 
    {
        return element.empty(); 
    }
    T Max() const 
    {
        if(Empty())
        {
            throw std::length_error("Max() : empty stack");
        }
        return cached_max_with_count.top().max;
    }

    void pop()
    {
        if(Empty())
        {
            throw std::length_error("Max() : empty stack");
        }

        T top = element.top();
        if(top == cached_max_with_count.top().max )
        {
            cached_max_with_count.top().count--;
            if(cached_max_with_count.top().count == 0)
                cached_max_with_count.pop();
        }

        element.pop();
    }

    void push(T x)
    {
        element.emplace(x);  

        if(cached_max_with_count.empty())
        {
            cached_max_with_count.emplace(MaxWithCount<T>{x, 1});
        }
        else
        {
            if(x == cached_max_with_count.top().max)
            {
                int &maxCount = cached_max_with_count.top().count;
                maxCount++;
            }
            else if(x > cached_max_with_count.top().max)
            {
                cached_max_with_count.emplace(MaxWithCount<T>{x, 1});
            }
        }
    }
};



int main()
{
    MaxStack<int> intstack;
    intstack.push(3);
    intstack.push(4);
    intstack.push(2);
    intstack.push(4);
    intstack.push(1);
    intstack.push(5);

    cout << "Max : " << intstack.Max() << std::endl;
    intstack.pop();
    cout << "Max : " << intstack.Max() << std::endl;
    intstack.pop();
    cout << "Max : " << intstack.Max() << std::endl;
    intstack.pop();
    cout << "Max : " << intstack.Max() << std::endl;
    intstack.pop();
    cout << "Max : " << intstack.Max() << std::endl;

    MaxStack<std::string> stck;
    stck.push("hello");
    stck.push("this is");
    stck.push("prince");
    stck.push("thapa");
    stck.push("prince");
    stck.push("this is");

    cout << "Max : " << stck.Max() << std::endl;
    stck.pop();
    cout << "Max : " << stck.Max() << std::endl;
    stck.pop();

    return 0;
}