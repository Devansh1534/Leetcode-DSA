# Write your MySQL query statement below
SELECT name
FROM Customer
WHERE  referee_id not exists (select* from Customer where refree_id not exists (select* from Customer where refree_id = 2))