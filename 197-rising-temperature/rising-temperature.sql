# Write your MySQL query statement below
#SELF JOIN
#w1 -> represents ( today)
#w2 -> respresents (yesterday)
SELECT w1.id 
FROM Weather w1 
JOIN WEATHER w2
WHERE datediff(w1.recordDate , w2.recordDate) = 1
AND w1.temperature > w2.temperature;

