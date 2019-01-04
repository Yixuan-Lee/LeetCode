# references:
#     https://leetcode.com/articles/employees-earning-more-than-their-managers/


# Write your MySQL query statement below
select e1.Name as 'Employee'
from Employee as e1 join Employee as e2
on e1.Salary > e2.Salary and e1.ManagerId = e2.Id;
