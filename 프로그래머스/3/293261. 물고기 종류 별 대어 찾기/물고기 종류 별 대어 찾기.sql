-- 코드를 작성해주세요
select A.id, B.FISH_NAME, A.LENGTH 
from FISH_INFO as A join FISH_NAME_INFO  as B on A.FISH_TYPE = B.FISH_TYPE
where (A.FISH_TYPE, A.LENGTH) in (
select FISH_TYPE, MAX(LENGTH)
from FISH_INFO 
group by FISH_TYPE)
order by id