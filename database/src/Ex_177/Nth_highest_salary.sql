# references:
#     https://leetcode.com/problems/nth-highest-salary/discuss/180302/limit-and-offset-used
#     http://www.sqltutorial.org/sql-limit/  (great article for limit & offset clauses)


CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  set N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct Salary
      from Employee
      order by Salary desc
      limit 1
      offset N
  );
END
