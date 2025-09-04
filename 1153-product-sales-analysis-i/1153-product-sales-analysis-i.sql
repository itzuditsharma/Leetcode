# Write your MySQL query statement below
SELECT p.product_name, s.year, s.price
FROM Sales s NATURAL JOIN Product p
