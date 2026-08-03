# Write your MySQL query statement below
SELECT machine_id, (
    ROUND(avg(
        CASE
            WHEN activity_type = 'start' THEN -timestamp*2
            WHEN activity_type = 'end' THEN timestamp*2
        END
    ), 3)
)  as processing_time FROM Activity 
GROUP BY machine_id;