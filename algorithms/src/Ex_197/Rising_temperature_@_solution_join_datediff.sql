# references:
#     https://leetcode.com/articles/rising-temperature/


# Write your MySQL query statement below
select Weather.id as 'Id'
from Weather
join Weather w on DATEDIFF(Weather.RecordDate, w.RecordDate) = 1
and weather.Temperature > w.Temperature;
