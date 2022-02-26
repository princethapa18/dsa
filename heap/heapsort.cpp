/* 26 Feb 2022
   Heap sort is an optimisation of a selection sort
   unordered array
   buildHeap   ---> maxHeap or a minHeap 
   for maxHeap
   swap arr[0] , arr[n-1] // swap max element with the last 
   [unsorted array][max element]
   // reduce the size of the heap
   maxHeapify(arr, n-1, 0); //  again maxheapify root
  
   swap arr[0] , arr[n-2] // swap second max element with the second last index
   maxHeapify(arr, n-2, 0);  //  again maxheapify root

   and so on till heapsize > 1
  
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void maxHeapify(vector<int>& vec, int n, int i)
{
    if(i < 0 || i >= n) return;

    int largest = i;
    int left  = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && vec[left] > vec[largest]) largest = left;
    if(right < n && vec[right] > vec[largest]) largest = right;

    if(largest != i)
    {
        std::swap(vec[largest], vec[i]);
        maxHeapify(vec, n, largest);
    }
}

void buildHeap(vector<int>& vec)
{
    int n = vec.size();
    for(int i = (n-2)/2; i >= 0; i--)
    {
        maxHeapify(vec, n, i);
    }
}

void heapSort(vector<int>& vec)
{
    if(!vec.size()) return;
    buildHeap(vec);
    int n = (int)vec.size();
    for(int i = n-1; i >= 1; i--)
    {
        std::swap(vec[0], vec[i]);
        maxHeapify(vec, i, 0);
    }
}

void Print(vector<int>& vec)
{
    cout << "\n-------\n";
    for(auto &it: vec)
    {
        cout << it << " ";
    }
    cout << "\n-------\n";
}

int main()
{
    cout << "Enter an unsorted array : ";
    string str;
    getline(cin, str);
    stringstream ss{str};

    int num;
    vector<int> vec;
    while (ss >> num)
        vec.push_back(num);
    
    Print(vec);
    heapSort(vec);
    cout << "--- Heap sort---\n";
    Print(vec);

    return 0;
}

// 10 30 20 40 60 5 70