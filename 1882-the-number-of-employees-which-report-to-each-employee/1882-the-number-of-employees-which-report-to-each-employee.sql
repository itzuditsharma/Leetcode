-- -- # Write your MySQL query statement below
SELECT e2.employee_id, e2.name, 
COUNT(DISTINCT e1.employee_id) as reports_count,
ROUND(AVG(e1.age)) as average_age
FROM
Employees e1
LEFT JOIN Employees e2
ON e1.reports_to = e2.employee_id
WHERE e1.reports_to IS NOT NULL
GROUP BY e1.reports_to
ORDER BY e1.reports_to

-- SELECT * from 
-- Employees e1 LEFT JOIN Employees e2
-- ON e1.reports_to = e2.employee_id
-- WHERE 
--     e1.reports_to IS NOT NULL 

# Write your MySQL query statement below
-- SELECT 
--     e2.employee_id, 
--     e2.name, 
--     COUNT(DISTINCT e1.employee_id) AS reports_count, 
--     ROUND(AVG(e1.age)) AS average_age 
-- FROM 
--     Employees e1 
-- LEFT JOIN 
--     Employees e2 
-- ON 
--     e1.reports_to = e2.employee_id 
-- WHERE 
--     e1.reports_to IS NOT NULL 
-- GROUP BY 
--     e1.reports_to 
-- ORDER BY 
--     e1.reports_to;