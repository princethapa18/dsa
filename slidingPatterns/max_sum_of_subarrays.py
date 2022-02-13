""" Sliding Window  Maximum Sum Subarray of Size K (easy)
    12 Feb 2022


"""
def max_sub_array_of_size_k(k, arr):
      # TODO: Write your code here
  maxSum =0
  sum_ = 0
  start = 0
  for end in range(len(arr)):
    sum_ += arr[end]
    if end >= k - 1:
      if maxSum < sum_:
        maxSum = sum_
      sum_ -= arr[start]
      start += 1
  return maxSum

def main():
  k = 5
  arr = [1, 3, 2, 6, -1, 4, 1, 8, 2]
  maxSum = max_sub_array_of_size_k(k, arr)
  print("\nMaximum Sum Subarray of Size K: " + str(k) + " " + str(maxSum))
  k = 3
  maxSum = max_sub_array_of_size_k(k, [1, 3, 2, 6, -1, 4, 1, 8, 2, 3])
  print("\nMaximum Sum Subarray of Size K: " + str(k) + " " + str(maxSum))

main()