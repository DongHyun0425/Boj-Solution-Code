-- 코드를 입력하세요
SELECT a.AUTHOR_ID, a.AUTHOR_NAME, b.CATEGORY,SUM(s.sales * b.price) TOTAL_SALES
from book_sales s join book b on s.book_id=b.book_id
join AUTHOR a ON b.AUTHOR_ID = a.AUTHOR_ID
where SALES_DATE LIKE '2022-01%'
group by a.author_name, b.category
order by a.author_id, b.category desc