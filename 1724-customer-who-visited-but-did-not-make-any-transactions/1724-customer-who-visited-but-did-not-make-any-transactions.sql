# Write your MySQL query statement below
SELECT v.customer_id, COUNT(v.customer_id) as count_no_trans
FROM Visits v LEFT JOIN Transactions t 
ON v.visit_id = t.visit_id
WHERE t.transaction_id is NULL
GROUP BY customer_id

-- | visit_id | customer_id | transaction_id | visit_id | amount |
-- | -------- | ----------- | -------------- | -------- | ------ |
-- | 1        | 23          | 12             | 1        | 910    |
-- | 2        | 9           | 13             | 2        | 970    |
-- | 4        | 30          | null           | null     | null   |
-- | 5        | 54          | 9              | 5        | 200    |
-- | 5        | 54          | 3              | 5        | 300    |
-- | 5        | 54          | 2              | 5        | 310    |
-- | 6        | 96          | null           | null     | null   |
-- | 7        | 54          | null           | null     | null   |
-- | 8        | 54          | null           | null     | null   |