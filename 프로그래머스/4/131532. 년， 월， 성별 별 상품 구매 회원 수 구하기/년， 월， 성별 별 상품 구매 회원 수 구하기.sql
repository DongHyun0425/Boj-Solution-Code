-- 코드를 입력하세요
SELECT YEAR(sales_date) year,MONTH(sales_date) month,gender,count(distinct(s.user_id)) users
from online_sale s join user_info i on s.user_id = i.user_id
where gender is not null 
group by YEAR(sales_date),MONTH(sales_date), gender
order by year,month,gender