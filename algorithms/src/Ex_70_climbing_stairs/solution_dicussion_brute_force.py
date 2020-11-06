"""
Reference:
https://leetcode.com/problems/climbing-stairs/solution/

Idea:
climbStairs(i, n) = climbStairs(i+1, n) + climbStairs(i+2, n)

Time complexity: O(2^n)
Space complexity: O(n)

"""

class Solution:
    def climbStairs(self, n: int) -> int:
        return self.__brute_force(0, n)

    def __brute_force(self, curr_floor: int, target_floor: int) -> int:
        if curr_floor > target_floor:
            return 0
        if curr_floor == target_floor:
            return 1

        return self.__brute_force(curr_floor+1, target_floor) + self.__brute_force(curr_floor+2, target_floor)


if __name__ == '__main__':
    solu = Solution()
    print(solu.climbStairs(2))  # 2
    print(solu.climbStairs(3))  # 3
