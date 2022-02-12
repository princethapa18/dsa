/* 04 Feb 2022 Week 05 - Segregate 0s and 1s  - Asked in CapeGemini interview   
   https://practice.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1/#
   Easy 
*/

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

/*

Input:
N = 5
arr[] = {0, 0, 1, 1, 0}
Output: 0 0 0 1 1

Input:
N = 4
Arr[] = {1, 1, 1, 1}
Output: 1 1 1 1
Explanation: There are no 0 in the given array, 
so the modified array is 1 1 1 1.

Your Task:
You don't need to read input or print anything. Your task is to complete the function segregate0and1() which takes arr[] and n as input parameters and modifies arr[] in-place without using any extra memory.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 107
0 ≤ arri ≤ 1

*/

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // Do u really need swap??
    // void swap(int &l , int &r)
    // {
    //     int& temp = r;
    //     l = r;
    //     r = temp;
    // }
    void segregate0and1(int arr[], int n) {
        // code here
        {
        /* Brute force - Two passes
        count no. of 0s
        int i;
        int cnt_zero = 0;
        for(i = 0; i < n; i++)
        {
            if(arr[i] == 0)
                cnt_zero++;
        }
        if(cnt_zero > 0)
        {
            for(i = 0; i < n; i++)
            {
                if(cnt_zero > 0)
                {
                    arr[i] = 0;
                    cnt_zero--;
                }
                else
                {
                    arr[i] = 1;
                }
            }
        }
        */
        
        /* This solution took more time than expected
        Expected time limit 2.45 sec
        if(n < 2)
            return;
        
        int i = 0, j = n - 1;
        while(i != j)
        {
            if(arr[i] == 0)
                i++;   
            if(arr[j] == 1)
                j--;  
            if( arr[i] == 1 && arr[j] == 0 )
            {
                swap(arr[i], arr[j]);
                i++; 
                j--;
            }
        }
        */
        }

        if(n < 2)
            return;
        
        int i = 0, j = n - 1;
        // i moves from left to right  ---->
        // <----- j moves from right to left      
        // loop stops when i becomes >= j
        while(i < j)
        {
            // if arr[i] == 1 and arr[j] == 0  then swap 
            // move i and j
            if( arr[i] == 1 && arr[j] == 0 )
            {
                arr[i++] = 0; // arr[i] = 0 then i++   
                arr[j--] = 1; // arr[j] = 1 then j--
            }
            if(arr[i] == 0) i++; // i only moves if arr[i] is equal to 0
            if(arr[j] == 1) j--; // j only moves if arr[j] is equal to 1
        }
        
    }
    
};

// { Driver Code Starts.

int main() {
    int t;
    cout << "Enter t: ";
    cin >> t;
    while (t--) {
        int n;
        cout << "\n Enter no. of elements n: ";
        cin >> n;
        int arr[n];
        cout << "\nEnter only 0s and 1s";
        for (int i = 0; i < n; i++) {
            cout << "\nEnter arr[" << i << "] : ";
            cin >> arr[i];
        }
        Solution ob;
        ob.segregate0and1(arr, n);
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
<<<<<<< HEAD
}  // } Driver Code Ends
=======
}  // } Driver Code Ends
>>>>>>> 18bc71a10c9d0ca50ee876a4c6d096cbed0a2028
