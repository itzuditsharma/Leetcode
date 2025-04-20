# Write your MySQL query statement below
select p.product_id, ROUND(IFNULL(SUM(p.price*u.units)/SUM(u.units),0),2) as average_price
FROM Prices p
LEFT JOIN UnitsSold u
on p.product_id = u.product_id 
AND u.purchase_date BETWEEN p.start_date and p.end_date
GROUP BY p.product_id;
