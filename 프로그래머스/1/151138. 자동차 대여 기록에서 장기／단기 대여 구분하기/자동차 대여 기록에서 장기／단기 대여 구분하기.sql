-- 코드를 입력하세요
SELECT HISTORY_ID,CAR_ID,date_format(START_DATE,"%Y-%m-%d") START_DATE, date_format(END_DATE,"%Y-%m-%d") end_date,
(
    case when datediff(end_date,start_date)<29 then '단기 대여' else '장기 대여' end
) RENT_TYPE
from car_rental_company_rental_history
where YEAR(start_date)=2022 and MONTH(start_date)=09
order by history_id desc