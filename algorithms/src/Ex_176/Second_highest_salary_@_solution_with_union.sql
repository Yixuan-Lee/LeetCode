# references:
#     https://stackoverflow.com/questions/5360894/get-the-second-highest-value-in-a-mysql-table
#     https://stackoverflow.com/questions/12449899/returning-a-value-even-if-no-result


# Write your MySQL query statement below
select Salary SecondHighestSalary
    from Employee
    where Salary = (
        select max(salary)
        from Employee
        where Salary < (
            select max(salary)
            from employee
        )
    )
union
select null   # return null if only one line in the table
limit 1;
