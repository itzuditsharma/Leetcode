# Write your MySQL query statement below
-- Visits 
-- Transactions

SELECT v.customer_id, COUNT(customer_id) as count_no_trans
FROM Visits v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
WHERE t.transaction_id iS NULL
GROUP BY v.customer_id