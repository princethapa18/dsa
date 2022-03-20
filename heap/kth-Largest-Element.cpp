/* 20 Mar 2022
   https://leetcode.com/problems/kth-largest-element-in-an-array/

*/

#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        if(nums.size() == 0) return -1;
        
        priority_queue<int> maxHeap{nums.begin(), nums.end()};
        
        int cnt = 0;
        int ret = -1;
        
        while(!maxHeap.empty() && cnt != k )
        {
            ret = maxHeap.top();
            maxHeap.pop();
            cnt++;
        }
        
        return ret;
    }
};

int main()
{
    cout << "Enter an unsorted array: ";
    string str;
    std::getline(cin, str); 
    stringstream ss{str};
    auto num{0};
    vector<int> vec;
    while(ss >> num)
    {
        vec.push_back(num);
    }

    cout << "\nEnter k : ";
    auto k{0};
    cin >> k;
    Solution sln;
    cout << "ans: " << sln.findKthLargest(vec, k) << endl;

    return 0;
}