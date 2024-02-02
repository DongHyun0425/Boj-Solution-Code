-- 코드를 입력하세요
SELECT CATEGORY, sum(s.sales) TOTAL_SALES 
from book b left join book_sales s on b.book_id = s.book_id
where YEAR(s.sales_date)=2022 and MONTH(s.sales_date)=1
group by category
order by category