-- 코드를 작성해주세요
select id, 
    case when T.R >= 0.75 then "CRITICAL"
    when T.R >=0.5 then "HIGH"
    when T.R >=0.25 then "MEDIUM"
    else "LOW"
    end as COLONY_NAME
from (select id, PERCENT_RANK() over (ORDER BY SIZE_OF_COLONY) as R
from ECOLI_DATA) T 
order by id