class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        if len(nums1) == 0 or len(nums2) == 0:
            return []
        nums1 = sorted(nums1)
        nums2 = sorted(nums2)

        intersection = []
        cache = {}
        for e in nums1:
            if e not in cache:
                cache[e] = 1
            else:
                cache[e] += 1
        for e in nums2:
            if e in cache:
                intersection.append(e)
                cache[e] -= 1
                if cache[e] == 0:
                    del cache[e]
        return intersection



if __name__ == '__main__':
    s = Solution()
    print(s.intersect([1, 2, 2, 1], [2, 2]))
    print(s.intersect([4, 9, 5], [9, 4, 9, 8, 4]))

