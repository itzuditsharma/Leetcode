SELECT p.product_id, 
ROUND(ifnull(SUM(p.price * u.units) / SUM(u.units) , 0),2) as average_price
FROM Prices p
LEFT JOIN UnitsSold u
on u.product_id = p.product_id and u.purchase_date BETWEEN p.start_date and p.end_date
GROUP BY p.product_id