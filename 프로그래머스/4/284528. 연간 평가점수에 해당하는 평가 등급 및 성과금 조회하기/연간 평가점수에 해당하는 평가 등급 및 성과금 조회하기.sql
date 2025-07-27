-- 코드를 작성해주세요
select A.EMP_NO, A.EMP_NAME,
case when  SUM(B.SCORE)/2 >=96 then 'S'
      when      SUM(B.SCORE)/2 >=90 then 'A'
         when   SUM(B.SCORE)/2 >=80 then 'B'
            else 'C'
            end as GRADE
, Case when SUM(B.SCORE)/2 >=96  then A.SAL * 0.2
        when SUM(B.SCORE)/2 >=90 then A.SAL * 0.15
         when   SUM(B.SCORE)/2 >=80 then A.SAL * 0.1
            else 0
            end as BONUS
            
from HR_EMPLOYEES as A join HR_GRADE as B on A.EMP_NO = B.EMP_NO
group by A.EMP_NO
order by A.EMP_NO