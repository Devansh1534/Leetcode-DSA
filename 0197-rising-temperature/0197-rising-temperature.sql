SELECT w1.id
FROM Weather AS w1
JOIN Weather AS w2
ON w1.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY)
WHERE w1.temperature > w2.temperature;