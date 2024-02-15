-- 코드를 입력하세요
SELECT date_format(SALES_DATE,"%Y-%m-%d") sales_date, PRODUCT_ID,USER_ID,SALES_AMOUNT
from online_sale
where year(sales_date)=2022 and month(sales_date)=03

union

select  date_format(SALES_DATE,"%Y-%m-%d") sales_date,PRODUCT_ID, NULL user_id,SALES_AMOUNT
from offline_sale
where year(sales_date)=2022 and month(sales_date)=03
order by sales_date, product_id, user_id 