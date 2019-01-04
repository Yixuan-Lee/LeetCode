# references:
#     https://leetcode.com/problems/combine-two-tables/discuss/52932/My-Solution-And-Question-With-Union


# Write your MySQL query statement below
select Person.FirstName, Person.LastName, Address.City, Address.State
from Person, Address
where Person.PersonId = Address.PersonId
union
select FirstName, LastName, null as City, null as State
from Person
where PersonId not in
    (select PersonId
     from Address
    );
