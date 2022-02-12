/*  Week 52 28 dec 2021 

    https://leetcode.com/problems/remove-duplicates-from-sorted-array/

    Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

 

Constraints:

    0 <= nums.length <= 3 * 104
    -100 <= nums[i] <= 100
    nums is sorted in non-decreasing order.


*/


#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


class Solution {
public:
    //  this method giving wrong result for
    //  [1 1 2 2 2 3 4 5 5 5 6 6]
    // int removeDuplicates(vector<int>& nums) {
    //    int temp = 0, i, j; 
    //    int uniqueCount = 0;
       
    //    if(nums.size() > 0)
    //    {
    //        temp = nums[0];
    //        uniqueCount++;
    //        for(i = 1; i < nums.size() ; i++)
    //        {
    //            if(nums[i] == temp )
    //            {
    //                for(j = i; j < nums.size()-1; j++)
    //                {
    //                    nums[j] = nums[j+1];
    //                }
    //                nums[j] = -1;
    //                if(nums[i] != temp)
    //                {
    //                    temp = nums[i];
    //                    uniqueCount++;
    //                }
    //            }
    //            else if( nums[i] != temp && nums[i] != -1)
    //            {
    //                temp = nums[i];
    //                uniqueCount++;
    //            }
    //        }
           
    //    }
        
    //    return uniqueCount;
    // }

    // time complexity  O(n) 
    // space complexity O(1)
    // [1 1 2 2 2 3 4 5 5 5 6 6]
    // [1 2]
    int removeDuplicates(vector<int> & nums)
    {
        if(nums.size() == 0) return 0;

        int t = 0;
        for(int i = 0 ; i < (int)nums.size(); i++)
        {
            if(nums[t] != nums[i])
            {
                t++;
                nums[t] = nums[i];
            }            
        }
        return t+1;
    }
};

template<typename T>
void printArray(std::vector<T>& vec)
{
    for(int i = 0; i < (int)vec.size(); i++)
        cout << vec[i] << " ";
}

int main()
{
    std::cout << "Enter a sorted array of integers (use space) containing duplicates\n";

    std::vector<int> vec;

    std::string line;
    std::getline(std::cin, line);
    std::istringstream os(line);

    int i;
    while (os >> i)
        vec.emplace_back(i);

    Solution obj;
    std::cout << "number of unique numbers : " << obj.removeDuplicates(vec) << std::endl;   

    printArray<int>(vec);


    return 0;
}