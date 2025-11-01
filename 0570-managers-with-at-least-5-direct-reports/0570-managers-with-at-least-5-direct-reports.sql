# Write your MySQL query statement below
SELECT e1.name FROM Employee e1 
LEFT JOIN Employee e2
on e1.id = e2.managerId
GROUP BY e1.id
HAVING COUNT(e1.id) >= 5

-- | id  | name  | department | managerId | id   | name  | department | managerId |
-- | --- | ----- | ---------- | --------- | ---- | ----- | ---------- | --------- |
-- | 101 | John  | A          | null      | 106  | Ron   | B          | 101       |
-- | 101 | John  | A          | null      | 105  | Anne  | A          | 101       |
-- | 101 | John  | A          | null      | 104  | Amy   | A          | 101       |
-- | 101 | John  | A          | null      | 103  | James | A          | 101       |
-- | 101 | John  | A          | null      | 102  | Dan   | A          | 101       |
-- | 102 | Dan   | A          | 101       | null | null  | null       | null      |
-- | 103 | James | A          | 101       | null | null  | null       | null      |
-- | 104 | Amy   | A          | 101       | null | null  | null       | null      |
-- | 105 | Anne  | A          | 101       | null | null  | null       | null      |
-- | 106 | Ron   | B          | 101       | null | null  | null       | null      |