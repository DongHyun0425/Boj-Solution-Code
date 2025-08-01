-- 코드를 입력하세요
SELECT YEAR(A.SALES_DATE)as YEAR ,MONTH(A.SALES_DATE) as MONTH ,B.GENDER,COUNT(Distinct(A.USER_ID)) USERS
from ONLINE_SALE as A join USER_INFO as B on A.USER_ID = B.USER_ID
where B.GENDER is not NULL
group by YEAR(A.SALES_DATE),MONTH(A.SALES_DATE),B.GENDER
order by YEAR,MONTH,B.GENDER