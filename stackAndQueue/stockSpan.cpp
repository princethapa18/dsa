/* Week 02 15 Jan 2022
   Stock Span problem
   Example 1:

Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span for 100 
will be 1, 80 is smaller than 100 so the 
span is 1, 60 is smaller than 80 so the 
span is 1, 70 is greater than 60 so the 
span is 2 and so on. Hence the output will 
be 1 1 1 2 1 4 6.

Example 2:

Input: 
N = 6, price[] = [10 4 5 90 120 80]
Output:
1 1 2 4 5 1
Explanation:
Traversing the given input span for 10 
will be 1, 4 is smaller than 10 so the 
span will be 1, 5 is greater than 4 so 
the span will be 2 and so on. Hence, the 
output will be 1 1 2 4 5 1.

    span = [index of current element - index of previous greater element]
    if the current element > the previous greater elements then 
    span = index of current element + 1

    10,    4,     5,     90,   120,    80
    0+1   [1-0]  [2-0]  [3+1]  [4+1]  [5-4]
    
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

std::vector<int> calculateSpan(std::vector<int>& price)
{
    // Your code here
    std::vector<int> spanVec;
    
    /* contains indexes of previous greater element */
    std::stack<int> st;
    st.push(0);
    spanVec.push_back(1);
    
    for(int  i = 1; i < (int)price.size(); i++)
    {
        while(!st.empty() && price[st.top()] <= price[i])
        {
            st.pop();
        }
        int span = (st.empty() ? i + 1 : i-st.top());
        spanVec.push_back(span);
        st.push(i);
    }
    return spanVec;
}

template<typename T>
void printArray(std::vector<T>& vec)
{
    for(int i = 0; i < (int)vec.size(); i++)
        std::cout << vec[i] << " ";
}


int main()
{
    std::cout << "Enter an array of integers (use space)\n";

    std::vector<int> vec;

    std::string line;
    std::getline(std::cin, line);
    std::istringstream os(line);

    int i;
    while (os >> i)
        vec.emplace_back(i);

    std::vector<int> spanVec = calculateSpan(vec);
    printArray(spanVec);

    return 0;
}
