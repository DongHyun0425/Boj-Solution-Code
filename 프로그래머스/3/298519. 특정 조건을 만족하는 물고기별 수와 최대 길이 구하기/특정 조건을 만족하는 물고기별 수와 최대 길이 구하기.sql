-- 코드를 작성해주세요
#1번 서브쿼리를 통해서 평균이 30이 넘는애들의 FISH_TYPE을 구한다.
#2번, 본쿼리에서 FISH_TYPE을 기준으로 GROUP BY떄리고 MaxLENGTH를 구한다.

select COUNT(*) as FISH_COUNT, MAX(LENGTH) as MAX_LENGTH, FISH_TYPE
from  FISH_INFO 
where FISH_TYPE in (
select FISH_TYPE
from (
   select ID,FISH_TYPE,ifnull(LENGTH,10) as LENGTH,TIME
    from FISH_INFO
) as FISH_INFO
group by FISH_TYPE
having SUM(LENGTH) / COUNT(ID) >= 33
    )
    
group by FISH_TYPE
order by FISH_TYPE

