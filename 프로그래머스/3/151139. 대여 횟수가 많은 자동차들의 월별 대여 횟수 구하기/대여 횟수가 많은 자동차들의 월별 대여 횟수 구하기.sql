-- 코드를 입력하세요
SELECT MONTH(START_DATE) MONTH,car_id, count(*) RECORDS
from car_rental_company_rental_history
where car_id in (select car_id from car_rental_company_rental_history 
where START_DATE between '2022-08-01' and '2022-10-31' group by car_id 
having count(*)>=5 ) and START_DATE between '2022-08-01' and '2022-10-31' 
group by MONTH(START_DATE),car_id
order by MONTH, car_id desc