# Write your MySQL query statement below
select Name as 'Customers'
from Customers
where not exists (
    select CustomerId
    from Orders
    where Customers.Id = Orders.CustomerId
);
