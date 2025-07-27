-- 코드를 작성해주세요
select B.DEPT_ID, B.DEPT_NAME_EN, ROUND(AVG(A.SAL))as AVG_SAL
from HR_EMPLOYEES as A join HR_DEPARTMENT as B on A.DEPT_ID = B.DEPT_ID
group by DEPT_ID
order by AVG_SAL desc
