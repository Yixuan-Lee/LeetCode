# references:
#     https://leetcode.com/articles/delete-duplicate-emails/
#     https://www.w3schools.com/sql/sql_delete.asp


# Write your MySQL query statement below
#
# select the rows that we want to delete
# select t1.*
# from Person t1, Person t2
# where t1.Email = t2.Email and t1.Id > t2.Id
#
delete t1.* from Person t1, Person t2
where t1.Email = t2.Email and t1.Id > t2.Id;
