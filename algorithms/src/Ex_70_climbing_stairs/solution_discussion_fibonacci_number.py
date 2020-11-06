"""
Reference:
https://leetcode.com/problems/climbing-stairs/solution/

Idea:
the solution bottom_up_dynamic_program can be deduced to calculate the i-th fibonacci number
    Fib(n) = Fib(n-1) + Fib(n-2)
where the base cases:
    Fib(1) = 1
    Fib(2) = 2

Time complexity: O(n)
Space complexity: O(1)

"""


class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        first = 1
        second = 2
        for i in range(3, n+1):
            third = first + second
            first, second = second, third
        return second


if __name__ == '__main__':
    solu = Solution()
    print(solu.climbStairs(2))  # 2
    print(solu.climbStairs(3))  # 3
