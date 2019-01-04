# references:
#     https://leetcode.com/articles/duplicate-emails/


# Write your MySQL query statement below
select Email
from (
    select Email, count(Email) as 'num'     # alias of column name can add ''
    from Person
    group by Email
) as statistic                              # table name cannot add ''
where num > 1;
