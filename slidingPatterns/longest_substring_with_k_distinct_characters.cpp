/* Sliding Window 
   Longest substring with k distinct characters
   Sliding window shrinks or grows
*/

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class LongestSubstringKDistinct {
public:
    static int findLength(const string& str, int k) 
    {
        int maxLength = 0;
        int len  = 0;
        int start = 0;
        std::unordered_map<char, int> charFreqMap;   // character --> frequency map
        for(int end = 0; end < str.size(); end++)
        {
            char endChar = str[end];
            charFreqMap[endChar]++;
            while(charFreqMap.size() > k)
            {
                char startChar = str[start];
                charFreqMap[startChar]--;
                if(charFreqMap[startChar] == 0) charFreqMap.erase(startChar);                
                start++; // shrink the size of the sliding window till the number of distinct characters is > k
            }
           
            len = end - start + 1;
            if(maxLength < len) maxLength = len;
        }
        return maxLength;
    }
};

int main()
{
    std::string inputStr;
    cout << "Enter a string: ";
    std::getline(std::cin , inputStr);
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    std::cout << LongestSubstringKDistinct::findLength(inputStr, k) << std::endl;
    return 0;
}

/*
Case 1
Enter a string: araaci
Enter the value of k: 2
4

Case 2
Enter a string: araaci
Enter the value of k: 1
2

Case 3
Enter a string: cbbebi
Enter the value of k: 3
5

Case 4
Enter a string: cbbebi
Enter the value of k: 10
6

*/
