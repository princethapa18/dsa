/* Week 02 15 Jan 2022
    nextLargerELement
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

template<typename T>
void printArray(std::vector<T>& vec)
{
    std::cout << "inside printArray\n";
    for(int i = 0; i < (int)vec.size(); i++)
        std::cout << vec[i] << " ";
}

std::vector<int> nextLargerElement(std::vector<int> arr, int n){
    // Your code here
    std::stack<int> st;
    std::vector<int> vec(n, -1);  // n items with value -1
    //vec.reserve(n);
    std::cout << "vec.capacity() " << vec.capacity() << std::endl;

    for(int i = n-1; i >= 0; i--)
    {
        while(!st.empty() && arr[i] > st.top())
        {
            st.pop();
        }
        if(!st.empty())
        {
            vec.at(i) = st.top();
        }
        else
        {
            // stack is empty means no next greater element exist
            vec.at(i) = -1;
        }
        std::cout << "index i: " << i << " vec.at(i) " << vec.at(i) << std::endl;
        st.push(arr[i]);
    }
    return vec;
}


int main()
{
    std::cout << "Enter an array of integers (use space)\n";

    std::string line;
    std::getline(std::cin, line);
    std::istringstream os(line);

    std::vector<int> vec;
    int i;
    while (os >> i)
        vec.emplace_back(i);

    std::vector<int> largeVec = nextLargerElement(vec, (int)vec.size());
    printArray(largeVec);

    return 0;
}


