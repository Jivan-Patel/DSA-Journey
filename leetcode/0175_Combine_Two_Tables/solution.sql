# Write your MySQL query statement below
SELECT firstName, lastName, city, state 
FROM Person p
left join Address a
on p.personId = a.personId;