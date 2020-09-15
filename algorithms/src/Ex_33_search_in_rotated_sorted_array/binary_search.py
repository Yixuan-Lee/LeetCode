from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # boundary checking
        if len(nums) == 0:
            return -1

        # find the pivot
        # pivot represents the index of last element in the first ascending array
        pivot = len(nums) - 1
        for i in range(len(nums) - 1):
            if nums[i] > nums[i+1]:
                pivot = i
                break
        # so far, we know that the first ascending array indexing from
        #   [0, pivot]
        # the second ascending array indexing from
        #   [pivot + 1, len(nums)-1]

        if nums[pivot] == target:
            return pivot
        elif nums[pivot] < target:
            # nums[pivot] should be the largest value in nums
            return -1
        else:
            # search in the first ascending array
            l = 0
            r = pivot - 1
            while l <= r:
                mid = int((l + r) / 2)
                if nums[mid] == target:
                    return mid
                elif nums[mid] > target:
                    # search in the left part
                    r = mid - 1
                else:
                    # search in the right part
                    l = mid + 1

            # search in the second ascending array
            l = pivot + 1
            r = len(nums) - 1
            while l <= r:
                mid = int((l + r) / 2)
                if nums[mid] == target:
                    return mid
                elif nums[mid] > target:
                    # search in the left part
                    r = mid - 1
                else:
                    # search in the right part
                    l = mid + 1
        return -1


if __name__ == '__main__':
    solu = Solution()
    print(solu.search([4,5,6,7,0,1,2], 0))  # expect 0
    print(solu.search([4,5,6,7,0,1,2], 3))  # expect 3
    print(solu.search([1], 0))  # expect -1
