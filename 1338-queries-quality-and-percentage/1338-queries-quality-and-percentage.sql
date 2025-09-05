# Write your MySQL query statement below
SELECT query_name, 
ROUND(SUM(q.rating / q.position) / COUNT(q.query_name), 2) as quality,
ROUND((SUM(CASE WHEN q.rating < 3 THEN 1 else 0 END)) / COUNT(q.query_name)* 100, 2) as poor_query_percentage
FROM Queries q
GROUP BY query_name