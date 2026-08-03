# Write your MySQL query statement below
SELECT v.customer_id, COUNT(*) AS count_no_trans  FROM visits v
left join Transactions t on v.visit_id = t.visit_id
WHERE t.transaction_id is null
GROUP BY v.customer_id;