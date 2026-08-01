# Write your MySQL query statement below
-- SELECT d.name, e.name, e.salary 

SELECT d.name as Department, e.name as Employee, e.salary as Salary from Employee e
LEFT JOIN Department d 
ON d.id = e.departmentId
WHERE e.salary = (
    SELECT max(salary) from Employee
    WHERE e.departmentId = departmentId
);