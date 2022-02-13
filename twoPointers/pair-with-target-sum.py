""" 13 Feb 2022  Two pointer pattern
    Pair with Target Sum (easy)
    Given an ordered array

    Input: [1, 2, 3, 4, 6], target=6
    Output: [1, 3]
    Explanation: The numbers at index 1 and 3 add up to 6: 2+4=6

    Input: [2, 5, 9, 11], target=11
    Output: [0, 2]
    Explanation: The numbers at index 0 and 2 add up to 11: 2+9=11
"""

def pair_with_targetsum(arr, target_sum):
      # TODO: Write your code here
  i = 0
  j = len(arr) -1
  while i < j :
    sum_ = arr[i] + arr[j]
    if sum_ == target_sum:
      return [i, j]
    elif sum_ > target_sum:
      j -= 1
    else:
      i += 1
  return [-1, -1]

def main():
  target = 6
  arr = [1, 2, 3, 4, 6]
  res = pair_with_targetsum(arr, target)
  print("\npair_with_targetsum(arr) : " + str(res))
  arr = [2, 5, 9, 11]
  target = 11
  res = pair_with_targetsum(arr, target)
  print("\npair_with_targetsum(arr) : " + str(res))

  arr = [-1, 3, 5, 9, 11, 13]
  target = 11
  res = pair_with_targetsum(arr, target)
  print("\npair_with_targetsum(arr) : " + str(res))

  arr = [-1, 3, 5, 9, 11, 13]
  target = 8
  res = pair_with_targetsum(arr, target)
  print("\npair_with_targetsum(arr) : " + str(res))


main()