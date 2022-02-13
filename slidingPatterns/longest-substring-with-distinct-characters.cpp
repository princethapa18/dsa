/* 13Feb 2022 Longest substring with distinct characters Medium   Sliding Pattern
   https://leetcode.com/problems/longest-substring-without-repeating-characters/ 

   Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:

Input: s = "qrsvbspk"
Output: 5
Explanation: The answer is "qrsvb" or "vbspk", with the length of 5.

Constraints:

    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.


*/

#include <iostream>
#include <sstream>   // for std::stringstream
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    /* Solution 1
    int lengthOfLongestSubstring(const std::string& s) 
    {
        int maxLen = 0;
        int start = 0, end = 0; 
        std::unordered_set<char> uniqueChars;
        for(; end < (int)s.length(); end++)
        {
            auto it = uniqueChars.find(s[end]);
            if(it != uniqueChars.end())
            {                
                uniqueChars.erase(s[start]);                   
                start++;
            }
            uniqueChars.insert(s[end]);

            if(maxLen < uniqueChars.size())
                maxLen = uniqueChars.size();
        }

        return maxLen;
    }
    --- Okay --- 
    Enter the string : pwwke
    obj.lengthOfLongestSubstring(inputStr): 3
    [thapa@gns101 slidingPatterns]$ ./a.out 
    Enter the string : dvdf
    obj.lengthOfLongestSubstring(inputStr): 3
    [thapa@gns101 slidingPatterns]$ ./a.out 
    Enter the string : abcabcdfa
    obj.lengthOfLongestSubstring(inputStr): 5
    [thapa@gns101 slidingPatterns]$ ./a.out 
    Enter the string : pwwxwke
    obj.lengthOfLongestSubstring(inputStr): 4
    [thapa@gns101 slidingPatterns]$ ./a.out 
    Enter the string : abcabcbb
    obj.lengthOfLongestSubstring(inputStr): 3
    [thapa@gns101 slidingPatterns]$ ./a.out 
    Enter the string : bbbbb
    obj.lengthOfLongestSubstring(inputStr): 1

    --- Wrong Output ---
    Enter the string : qrsvbspk
    obj.lengthOfLongestSubstring(inputStr): 6

    Answer is 5
    */

    /* 
    Example   str = "qrsvbspk"
    uniqueChars   maxLen    start   end
    q              1          0      0
    qr             2          0      1
    qrs            3          0      2
    qrsv           4          0      3
    qrsvb          5          0      4
    when end = 5  increase start and erase str[start] from the set till str[end]='s' is in the set
    rsvb           5          1      5     's' is still in the set
    svb            5          2      5     's' is still in the set
    vb             5          3      5     's' is not there . now insert str[end] in the set
    vbs            5          3      5
    vbsp           5          3      6
    vbspk          5          3      7
    
    maxLen = 5
    
    Example   str = "dvdf"
    uniqueChars   maxLen    start   end
    d              1         0       0
    dv             2         0       1
    when end = 2  increase start and erase str[start] from the set till str[end]='d' is in the set
    v              2         1       2      'd' is not in the set. now insert str[end]='d' in the set
    vd             2         1       2
    vdf            3         1       3
    
    maxLen = 3
    
    */

    /*  using std::unordered_set  Works 
        Runtime: 49 ms, faster than 23.57% of C++ online submissions for Longest Substring Without Repeating  Characters.
        Memory Usage: 10.9 MB, less than 24.35% of C++ online submissions for Longest Substring Without Repeating Characters.
    int lengthOfLongestSubstring(const std::string& s) 
    {
        int maxLen = 0;
        int start = 0, end = 0; 
        std::unordered_set<char> substr;
        for(; end < (int)s.length(); end++)
        {
            while( substr.find(s[end]) != substr.end() )
            {
                substr.erase(s[start]);
                start++;
            }
            substr.insert(s[end]);
            if(maxLen < substr.size())
                maxLen = substr.size();
        }

        return maxLen;
    }
    */

     /* Using std::unordered_map also works
        Runtime: 25 ms, faster than 49.10% of C++ online submissions for Longest Substring Without Repeating Characters.
        Memory Usage: 8.1 MB, less than 78.62% of C++ online submissions for Longest Substring Without Repeating Characters.
        
        Run time is less and also space usage is less because
        We don't have to do while loop
        We don't have to do multiple insertions and deletions
    */
    int lengthOfLongestSubstring(const std::string& s) 
    {
        int maxLen = 0;
        int start = 0, end = 0; 
        std::unordered_map<char, int> charIndexMap;
        for(; end < (int)s.length(); end++)
        {
            char rightChar = s[end];
            if(charIndexMap.find(rightChar) != charIndexMap.end())
            {
                // find the position of the current char in the map
                // now change the position of the start depending upon the index
                // Ex:  qrsvbspk
                // When end = 5    rightChar = s[5] = 's'
                // in the map the position of 's' is 2
                // therefore new position of the start is 3   
                // window start = 3  
                start = max(start, charIndexMap[rightChar] + 1 );
            }
            charIndexMap[rightChar] = end; 

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};

int main()
{
    std::string inputStr;
    cout << "Enter the string : ";
    std::getline(std::cin , inputStr);
  
    Solution obj;
    std::cout << "obj.lengthOfLongestSubstring(inputStr): " <<  obj.lengthOfLongestSubstring(inputStr) << "\n";

    return 0;
}

/*



*/