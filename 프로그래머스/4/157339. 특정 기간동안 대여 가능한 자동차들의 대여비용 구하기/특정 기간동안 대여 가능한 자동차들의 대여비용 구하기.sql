-- 코드를 입력하세요
SELECT distinct(car.CAR_ID),car.CAR_TYPE, ROUND(DAILY_FEE * 30 - (DAILY_FEE * 30 * (DISCOUNT_RATE/100))) as fee
from car_rental_company_car car join car_rental_company_rental_history history on car.car_id=history.car_id join car_rental_company_discount_plan plan on car.car_type=plan.car_type
where (car.car_type="SUV" or car.car_type="세단") and car.car_id not in( select car_id from car_rental_company_rental_history where
    start_date between '2022-11-01' and '2022-11-30' or  end_date between '2022-11-01' and '2022-11-30' or (start_date<='2022-11-01' and end_date>='2022-11-01')
) and duration_type="30일 이상" and ROUND(DAILY_FEE * 30 - (DAILY_FEE * 30 * (DISCOUNT_RATE/100))) between 500000 and 2000000
order by fee desc,car.car_type,car.car_id desc