# references:
#     https://stackoverflow.com/questions/5360894/get-the-second-highest-value-in-a-mysql-table
#     https://stackoverflow.com/questions/12449899/returning-a-value-even-if-no-result


# Write your MySQL query statement below
select Salary SecondHighestSalary
from Employee
where (
    Salary = (
        select Salary
        from Employee
        group by Salary
        desc
        limit 1,1
    )
)
union
(select null)
limit 1;
