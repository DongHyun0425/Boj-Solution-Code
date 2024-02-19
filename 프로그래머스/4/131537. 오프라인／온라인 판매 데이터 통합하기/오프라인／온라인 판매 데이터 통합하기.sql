-- 코드를 입력하세요
SELECT date_format(SALES_DATE,'%Y-%m-%d') sales_date,PRODUCT_ID,USER_ID,SALES_AMOUNT
from online_sale
where YEAR(sales_date)=2022 and MONTH(sales_date)=03

union

SELECT date_format(SALES_DATE,'%Y-%m-%d') sales_date,PRODUCT_ID,NULL as USER_ID,SALES_AMOUNT
from offline_sale
where YEAR(sales_date)=2022 and MONTH(sales_date)=03

order by sales_date, product_id, user_id