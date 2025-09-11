-- 코드를 작성해주세요
select A.ID, COUNT(B.PARENT_ID) as CHILD_COUNT
from ECOLI_DATA as A left join ECOLI_DATA as B on A.ID = B.PARENT_ID
group by A.ID
order by A.ID