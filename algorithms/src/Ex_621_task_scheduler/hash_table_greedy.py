"""
Idea:
determine a map where
    key: task character X
    value: a tuple (number of the task X we still need to complete (frequency), cooldown period for task X)
then sort the tasks based on the frequency every time

Time complexity: O(n^2 * logn)
Space complexity: O(n)

"""

from typing import List


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        mmap = {}
        for task in tasks:
            if task not in mmap:
                mmap[task] = [1, 0]
            else:
                mmap[task][0] += 1
        print(mmap)

        count = 0
        while mmap:
            mmap = {task: li for task, li in sorted(mmap.items(), key=lambda item: item[1][0], reverse=True)}
            flag = False    # check if a task is scheduled in this round
            for task, li in mmap.items():
                freq, cooldown = li
                if cooldown == 0:
                    freq -= 1
                    cooldown = n + 1
                    if freq == 0:
                        # remove the task
                        mmap.pop(task)
                    else:
                        mmap[task] = [freq, cooldown]
                    print(task, end=' -> ')
                    flag = True
                    break
                else:
                    continue
            count += 1
            if flag is False:
                print('idle', end=' -> ')
            # decrement the cooldown for all tasks
            for task in mmap.keys():
                if mmap[task][1] > 0:
                    mmap[task][1] -= 1
        print()
        return count


if __name__ == '__main__':
    solu = Solution()
    print(solu.leastInterval(["A","A","A","B","B","B"], 2)) # 8
    print(solu.leastInterval(["A","A","A","B","B","B"], 0)) # 6
    print(solu.leastInterval(["A","A","A","A","A","A","B","C","D","E","F","G"], 2)) # 16
    print(solu.leastInterval(["A","A","A","B","B","B","C","C","C","D","D","E"], 2)) # 12
