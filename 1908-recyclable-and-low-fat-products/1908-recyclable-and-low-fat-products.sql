# Write your MySQL query statement below
SELECT product_id
FROM Products
GROUP BY product_id
HAVING SUM(CASE WHEN low_fats = 'Y' THEN 1 ELSE 0 END)
AND SUM(CASE WHEN recyclable = 'Y' THEN 1 ELSE 0 END)