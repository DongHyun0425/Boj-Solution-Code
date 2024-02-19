-- 코드를 입력하세요
SELECT a.author_id,a.author_name,b.category, (sum(s.sales*b.price)) total_sales
from book_sales s join book b on s.book_id=b.book_id
join AUTHOR a ON b.AUTHOR_ID = a.AUTHOR_ID
where YEAR(sales_date)=2022 and MONTH(sales_date)=01
group by a.author_name,category
order by a.author_id, b.category desc