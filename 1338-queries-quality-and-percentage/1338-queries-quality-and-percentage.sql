# Write your MySQL query statement below
SELECT query_name, 
ROUND(AVG(q.rating / q.position), 2) as quality,
ROUND(AVG(q.rating < 3) * 100, 2) as poor_query_percentage
FROM Queries q
GROUP BY query_name