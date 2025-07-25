-- 코드를 작성해주세요
select ROUND(SUM(a.LENGTH)/COUNT(*),2) as AVERAGE_LENGTH
from (
    select ID, ifnull(LENGTH,10)as LENGTH
    from FISH_INFO 
)as a
