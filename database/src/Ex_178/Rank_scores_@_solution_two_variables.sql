# references:
#     https://leetcode.com/problems/rank-scores/discuss/53094/Simple-Short-Fast


# Write your MySQL query statement below
select Score, @rank := @rank + (@prev <> (@prev := Score)) Rank
from Scores, (
    select @rank := 0, @prev := -1
) init
order by Score desc;
