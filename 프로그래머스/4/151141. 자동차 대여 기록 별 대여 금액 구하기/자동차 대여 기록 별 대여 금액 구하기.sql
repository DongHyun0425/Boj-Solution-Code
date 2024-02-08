-- 코드를 입력하세요
SELECT h.history_id,    round(DAILY_FEE * (DATEDIFF(h.END_DATE,h.START_DATE)+1)
    * (case 
    when DATEDIFF(END_DATE,START_DATE)+1 < 7 then 1
    when DATEDIFF(END_DATE,START_DATE)+1 < 30 then 0.95
    when DATEDIFF(END_DATE,START_DATE)+1 < 90 then 0.92
    else 0.85 end)) as "FEE"
from car_rental_company_rental_history h left join car_rental_company_car car on h.car_id = car.car_id
where car.car_type="트럭"
order by fee desc,h.history_id desc