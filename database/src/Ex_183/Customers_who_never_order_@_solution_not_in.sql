# references:
#     https://leetcode.com/articles/customers-who-never-order/


# Write your MySQL query statement below
select Customers.Name as 'Customers'
from Customers
where Customers.Id not in (
    select CustomerId
    from Orders
);
