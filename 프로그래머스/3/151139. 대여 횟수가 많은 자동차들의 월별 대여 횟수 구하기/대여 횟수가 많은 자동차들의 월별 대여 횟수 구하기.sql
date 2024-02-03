SELECT MONTH(START_DATE) MONTH,car_id, count(*) RECORDS
from car_rental_company_rental_history
where car_id in (select car_id from car_rental_company_rental_history 
where YEAR(START_DATE)=2022 and MONTH(START_DATE) between 8 and 10 group by car_id 
having count(*)>=5 ) and YEAR(START_DATE)=2022 and MONTH(START_DATE) between 8 and 10
group by MONTH(START_DATE),car_id
order by MONTH, car_id desc
                