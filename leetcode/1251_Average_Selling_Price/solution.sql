# Write your MySQL query statement below
select p.product_id, 
(
    CASE
        when sum(u.units) is null then 0
        when sum(u.units) = 0 then 0
        else round(sum(u.units * p.price)/sum(units), 2) 
    END
) as average_price
from Prices p
left join UnitsSold u
on u.product_id = p.product_id and 
u.purchase_date between p.start_date and p.end_date
group by product_id;