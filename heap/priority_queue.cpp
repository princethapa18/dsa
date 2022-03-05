/* 05 Mar 2022 
   std::priority_queue in STL

   Defined in header <queue>
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;


*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    std::priority_queue<int> max_pq; // by default it is a max heap
    max_pq.push(3);
    max_pq.push(10);
    max_pq.push(15);
    max_pq.push(5);
    max_pq.push(8);

    while(!max_pq.empty())
    {
        cout << max_pq.top() << " ";
        max_pq.pop();
    }

    // Min heap example
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq; // by default it is a max heap
    // priority_queue is built using vector
    min_pq.push(3);
    min_pq.push(10);
    min_pq.push(15);
    min_pq.push(5);
    min_pq.push(8);

    cout << "\n ---- min heap -----\n";
    while(!min_pq.empty())
    {
        cout << min_pq.top() << " ";
        min_pq.pop();
    }

    return 0;
}