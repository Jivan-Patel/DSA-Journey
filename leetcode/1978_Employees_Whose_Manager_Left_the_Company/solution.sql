# Write your MySQL query statement below
SELECT e.employee_id from Employees e
LEFT JOIN Employees m
on e.manager_id = m.employee_id
WHERE e.salary < 30000 
AND e.manager_id is not null 
AND m.employee_id is null
ORDER BY e.employee_id;