# Write your MySQL query statement below
select  (
    select * from MyNumbers group by num having count(*) = 1
    order by num desc 
    limit 1
)  as num