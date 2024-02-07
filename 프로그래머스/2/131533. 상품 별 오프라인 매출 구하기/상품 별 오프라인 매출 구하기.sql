-- 코드를 입력하세요
SELECT product_code, sum(sales_amount*price) sales
from offline_sale off left join product p on off.product_id = p.product_id
group by product_code
order by sales desc, product_code