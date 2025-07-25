-- 코드를 작성해주세요
select ID, "LOW"  as SIZE
from ECOLI_DATA 
where id in (
    select id from ECOLI_DATA
    where SIZE_OF_COLONY<=100
)

union all 

select ID, "MEDIUM"  as SIZE
from ECOLI_DATA 
where id in (
    select id from ECOLI_DATA
    where SIZE_OF_COLONY<=1000 && SIZE_OF_COLONY>100
)

union all

select ID, "HIGH" as SIZE
from ECOLI_DATA 
where id in (
    select id from ECOLI_DATA
    where SIZE_OF_COLONY>1000
)

order by ID