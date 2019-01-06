# references:
#     https://leetcode.com/problems/department-highest-salary/discuss/201053/248ms-Ans-beats-99-and-illustration  (great illustraion)


# Write your MySQL query statement below
select d.Name as 'Department', a.Name as 'Employee', a.Salary
from Department d
join (
    # find the max salary and id of each department and its employee name and
    select e.Name, e.Salary, e.DepartmentId
    from Employee e
    where (e.DepartmentId, e.Salary) in (
        # find the max price and id of each department
        select e.DepartmentId, max(e.Salary)
        from Employee e
        group by e.DepartmentId
    )
) as a
on d.Id = a.DepartmentId;
