select date_format(SALES_DATE,'%Y-%m-%d')as SALES_DATE,PRODUCT_ID,USER_ID,SALES_AMOUNT
from ONLINE_SALE
where date_format(SALES_DATE,'%Y-%m')='2022-03'

union

select date_format(SALES_DATE,'%Y-%m-%d')as SALES_DATE,PRODUCT_ID,NULL AS USER_ID,SALES_AMOUNT
from offline_sale
where date_format(SALES_DATE,'%Y-%m')='2022-03'

ORDER BY SALES_DATE , PRODUCT_ID , USER_ID