SELECT MAX(num) as num FROM
(SELECT num, (COUNT(num) = 1) as freq
FROM MyNumbers 
GROUP BY num) t
WHERE t.freq = 1