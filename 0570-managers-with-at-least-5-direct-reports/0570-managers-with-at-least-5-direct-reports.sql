# Write your MySQL query statement below
SELECT e.name FROM Employee e
INNER JOIN Employee e2 on e.id = e2.managerId
GROUP BY e.id
HAVING COUNT(e.id) >=5