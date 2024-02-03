-- 코드를 입력하세요
SELECT category, price MAX_PRICE, product_name
from food_product
where (category,price) in (select category,max(price) from food_product group by category) and (category like "%과자" or category like "%국" or category like "%김치" or category like "%식용유") 
order by price desc