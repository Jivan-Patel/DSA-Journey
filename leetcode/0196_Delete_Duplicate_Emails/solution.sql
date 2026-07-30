# Write your MySQL query statement below
delete p from Person p 
join Person q 
on p.email = q.email
where p.id > q.id;