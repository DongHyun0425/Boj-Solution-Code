-- 코드를 입력하세요
SELECT mcdp_cd 진료과코드, count(apnt_no) 5월예약건수 from appointment where YEAR(APNT_YMD)=2022 and MONTH(APNT_YMD)=05 group by mcdp_cd order by 5월예약건수,진료과코드