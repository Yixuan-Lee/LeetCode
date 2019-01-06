# references:
#     https://leetcode.com/articles/consecutive-numbers/


# Write your MySQL query statement below
select distinct Num as 'ConsecutiveNums'
from Logs, (
    select Id as 'id2', Num as 'num2'
    from Logs,(
        select Id as 'id1', Num as 'num1'
        from Logs
    ) as table1
    where Id = id1 + 1 and Num = num1
) as table2
where Id = id2 + 1 and Num = num2;
