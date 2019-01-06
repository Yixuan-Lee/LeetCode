# references:
#     https://leetcode.com/problems/rank-scores/discuss/213023/row_number()-%2B-GROUP-BY-%2B-JOIN-(T-SQL)-651-ms


/* Write your T-SQL query statement below */
select s.Score, r.Rank
from Scores s
join (
    /* get ranking in distinct scores */
    select gr.Score, row_number() over (order by gr.Score desc) as 'Rank'
    from (
        select Score
        from Scores
        group by Score
    ) gr
) r
on r.Score = s.Score
order by r.Rank;
