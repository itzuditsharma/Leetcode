# Write your MySQL query statement below
SELECT r.contest_id, ROUND(COUNT(DISTINCT r.user_id) * 100 / (SELECT COUNT(*) FROM Users),2) as percentage
FROM Users u
LEFT JOIN Register r
ON u.user_id = r.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC, contest_id ASC
