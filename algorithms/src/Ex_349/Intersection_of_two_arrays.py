'''
references:
    https://leetcode.com/problems/intersection-of-two-arrays/discuss/232127/Python-Runtime%3A-20-ms-faster-than-100.00-not-using-built-in-functions-like-set()
'''


class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        ans = []
        cache = {}
        for e in nums1:
            if e not in cache:
                cache[e] = True
        for e in nums2:
            if e in cache:
                ans.append(e)
                del cache[e]

        return ans


def main():
    s = Solution()
    print(s.intersection([1, 2, 2, 1], [2, 2]))


if __name__ == "__main__":
    main()
