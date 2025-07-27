select A.FISH_COUNT,B.FISH_NAME
from (
    select COUNT(*) as FISH_COUNT,FISH_TYPE
    from FISH_INFO 
    group by FISH_TYPE
) as A
left join FISH_NAME_INFO as B
on A.FISH_TYPE = B.FISH_TYPE
order by A.FISH_COUNT desc