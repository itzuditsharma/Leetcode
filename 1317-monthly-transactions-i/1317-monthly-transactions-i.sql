# Write your MySQL query statement below
SELECT substr(trans_date,1, 7) as month, 
country, 
COUNT(id) as trans_count,
SUM(IF(state = 'approved',1 ,0)) as approved_count,
SUM(amount) AS trans_total_amount, 
SUM(IF(state = 'approved', amount, 0)) as approved_total_amount
FROM Transactions
GROUP BY substr(trans_date, 1, 7), country