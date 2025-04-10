# Write your MySQL query statement below
SELECT E.name, B.bonus FROM Employee E LEFT JOIN Bonus b 
ON E.empId = B.empId
WHERE B.bonus < 1000 or B.bonus IS NULL