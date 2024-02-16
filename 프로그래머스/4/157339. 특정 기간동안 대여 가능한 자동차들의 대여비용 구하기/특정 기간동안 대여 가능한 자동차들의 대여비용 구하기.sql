-- 코드를 입력하세요
SELECT distinct(c.car_id),c.car_type, ROUND(DAILY_FEE * 30 - (DAILY_FEE * 30 * (DISCOUNT_RATE/100))) fee
from  CAR_RENTAL_COMPANY_RENTAL_HISTORY h left join CAR_RENTAL_COMPANY_CAR c on h.car_id = c.car_id left join  CAR_RENTAL_COMPANY_DISCOUNT_PLAN p on p.car_type = c.car_type
where (c.car_type = "SUV" or c.car_type ="세단") and
(
    c.car_id not in (
        select car_id from CAR_RENTAL_COMPANY_RENTAL_HISTORY
        where start_date between "2022-11-01" and "2022-11-30" or
        end_date between "2022-11-01" and "2022-11-30" or
        (start_date <="2022-11-01" and end_date>="2022-11-30")
    )
)
and ROUND(DAILY_FEE * 30 - (DAILY_FEE * 30 * (DISCOUNT_RATE/100))) BETWEEN 500000 AND 2000000
and duration_type = "30일 이상"

order by fee desc, c.car_type,c.car_id desc