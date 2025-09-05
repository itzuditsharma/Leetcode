# Write your MySQL query statement below
SELECT SUBSTR(trans_date,1, 7) as month, country, 
COUNT(id) as trans_count,
SUM(CASE WHEN state = 'approved' THEN 1 else 0 END) as approved_count,
SUM(amount) as trans_total_amount,
SUM(CASE WHEN state = 'approved' THEN amount else 0 END) as approved_total_amount
FROM Transactions
GROUP BY DATE_FORMAT(trans_date, '%y-%m'), country