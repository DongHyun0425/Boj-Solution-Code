-- 코드를 작성해주세요
select b.YEAR,(a.K-b.Y)as YEAR_DEV,b.ID

from (

select YEAR(DIFFERENTIATION_DATE)as YEAR, MAX(SIZE_OF_COLONY) as K
from ECOLI_DATA 
group by YEAR(DIFFERENTIATION_DATE)
) as a join (
select YEAR(DIFFERENTIATION_DATE)as YEAR, SIZE_OF_COLONY as Y, ID
from ECOLI_DATA
    ) as b
    on a.YEAR = b.YEAR
order by a.YEAR, YEAR_DEV