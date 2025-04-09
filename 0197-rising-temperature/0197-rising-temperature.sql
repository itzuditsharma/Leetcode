# Write your MySQL query statement below
SELECT a.id
FROM WEATHER a
JOIN WEATHER b
WHERE DATEDIFF(a.recordDate, b.recordDate) = 1
AND a.temperature > b.temperature
