"""
Reference:
https://leetcode.com/problems/task-scheduler/discuss/104496/concise-Java-Solution-O(N)-time-O(26)-space

Idea:
first we consider the most frequent characters, we can determine their relative positions first and use them as a frame to insert the
remaining less frequent characters.

greedy strategy:
assume the most frequent task is A(6), and second most frequent task is B(5), third is C(4), fourth is D(3), ...
and cooldown n = 4
first, we create n chunks based on the most frequent task
A____A____A____A____A____A
second, we insert the less frequent task B into gaps between these chunks sequentially
AB___AB___AB___AB___AB___A
ABC__ABC__ABC__ABC__AB___A
ABCD_ABCD_ABCD_ABC__AB___A

if multiple tasks are the most frequent:
A(6), B(6), C(5), D(4), n = 3
then 'AB' forms the frame
A___A___A___A___A___A
AB__AB__AB__AB__AB__AB
ABC_ABC_ABC_ABC_ABC_AB
ABCDABCDABCDABCDABC_AB

the final formula: (c[25]-1) * n + c[25] + (25 - i - 1) is derived as
take the example A(6), B(6), C(5), D(4), n = 3 above:
(c[25]-1) * n -> number of _ in A___A___A___A___A___A
c[25] -> number of the most frequent task (A) in A___A___A___A___A___A
25-i-1 -> number of tasks that may need to append at the end of the last A, i.e. AB__AB__AB__AB__AB__AB
                                                                                                      ^
Time complexity: O(n)
Space complexity: O(1)

"""


from typing import List


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        c = [0] * 26
        for t in tasks:
            c[ord(t) - ord('A')] += 1
        c.sort()
        i = 25
        while i >= 0 and c[i] == c[25]:
            i -= 1
        return max(len(tasks), (c[25]-1) * n + c[25] + (25 - i - 1))


if __name__ == '__main__':
    solu = Solution()
    print(solu.leastInterval(["A","A","A","B","B","B"], 2)) # 8
    print(solu.leastInterval(["A","A","A","B","B","B"], 0)) # 6
    print(solu.leastInterval(["A","A","A","A","A","A","B","C","D","E","F","G"], 2)) # 16
    print(solu.leastInterval(["A","A","A","B","B","B","C","C","C","D","D","E"], 2)) # 12
