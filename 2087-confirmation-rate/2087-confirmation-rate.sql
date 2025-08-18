# Write your MySQL query statement below
SELECT Signups.user_id, 
ROUND(ifnull(SUM(c.action = "confirmed") / COUNT(c.action), 0), 2) as confirmation_rate
FROM Signups LEFT JOIN Confirmations c
ON Signups.user_id = c.user_id
GROUP BY Signups.user_id