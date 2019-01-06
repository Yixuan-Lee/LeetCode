# references:
#     https://leetcode.com/problems/department-highest-salary/discuss/199328/MySQL-268ms-accepted-solution


# Write your MySQL query statement below
select d.Name as 'Department', e.Name as 'Employee', e.Salary as 'Salary'
from (
    # find the maximum salary, and its corresponding department name and department id
    select d.Name, d.Id, max(e.Salary) as 'Salary'
    from Employee e
    left join Department d
    on e.DepartmentId = d.Id
    group by d.Name, d.Id
) d
inner join Employee e
on d.Salary = e.Salary
and d.Id = e.DepartmentId;
