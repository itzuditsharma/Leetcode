# Write your MySQL query statement below
SELECT St.student_id, St.student_name, Su.subject_name, COUNT(Ex.student_id) AS attended_exams
FROM Students St CROSS JOIN Subjects Su
LEFT JOIN Examinations Ex
ON St.student_id = Ex.student_id and Ex.subject_name = Su.subject_name
GROUP BY St.student_id, St.student_name, Su.subject_name
ORDER BY St.student_id, St.student_name