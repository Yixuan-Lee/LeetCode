class Solution(object):
    def fib(self, N):
        """
        :type N: int
        :rtype: int
        """
        prev_prev = 0
        prev = 1

        if N == 0:
            return prev_prev
        elif N == 1:
            return prev
        else:
            curr = 0
            for i in range(2, N + 1):
                curr = prev + prev_prev
                prev_prev = prev
                prev = curr
            return curr

if __name__ == '__main__':
    s = Solution()
    print(s.fib(2))
    print(s.fib(3))
    print(s.fib(4))
