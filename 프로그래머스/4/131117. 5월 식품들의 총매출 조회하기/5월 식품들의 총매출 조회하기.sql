-- 코드를 입력하세요
SELECT product.product_id,product.product_name, sum(amount*price) as total_sales
from food_order join food_product product on food_order.product_id=product.product_id
where YEAR(produce_date)='2022' and MONTH(produce_date)='05'
group by product.product_name,product.product_id
order by total_sales desc , product.product_id 
