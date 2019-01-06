# references:
#     https://mattmazur.com/2017/03/26/exploring-ranking-techniques-in-mysql/
#     https://stackoverflow.com/questions/24118393/mysql-rank-with-ties


# Write your MySQL query statement below
select Score as 'Score', Rank as 'Rank'
from (
    select
       Score as 'Score',
        @prev := @curr,
        @curr := score,
        @rank := if(@prev = @curr, @rank, @rank + 1) as 'Rank'
    from Scores, (
        select
            @curr := null,
            @prev := null,
            @rank := 0,
            @i = 1
    ) r
    order by Score desc
) temp_table;
