SELECT s.product_id, s.year as first_year, s.quantity, s.price
FROM Sales s 
JOIN 
(SELECT product_id, MIN(year) as first_year
FROM Sales 
GROUP BY product_id) t
on s.product_id = t.product_id and s.year = t.first_year