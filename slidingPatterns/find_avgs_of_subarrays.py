"""  12 Feb 2022 "Sliding Window pattern"
     Given an array, find the average of all subarrays of ‘K’ contiguous elements in it.
      0  1  2  3  4  5   6  7
     [1, 2, 4, 5, 6, 8 , 9, 11]   k = 4 n = 8
     result [n-k+1] 
     result[0] = sum[0-3]/4    ---->  sum03
     result[1] = sum[1-4]/4    ---->  sum14 = sum03 - arr[0] + arr[4]
     result[2] = sum[2-5]/4    ---->  sum25 = sum14 - arr[1] + arr[5]
     result[3] = sum[3-6]/4    ---->  sum36 = sum25 - arr[2] + arr[6]    
     result[4] = sum[4-7]/4    
"""     

def find_averages_of_subarrays(k, arr):
     result = []
     sum = 0.0
     start = 0
     for end in range(len(arr)):
          sum += arr[end]
          if end >= k - 1:
               result.append(sum/k)
               sum -= arr[start]
               start += 1
     return result


def main():
  k = 5
  result = find_averages_of_subarrays(k, [1, 3, 2, 6, -1, 4, 1, 8, 2])
  print("\nAverages of subarrays of size K: " + str(k) + " " + str(result))
  k = 3
  result = find_averages_of_subarrays(k, [1, 3, 2, 6, -1, 4, 1, 8, 2, 3])
  print("\nAverages of subarrays of size K: " + str(k) + " " + str(result))

main()
