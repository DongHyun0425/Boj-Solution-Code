-- 코드를 입력하세요
SELECT a.AUTHOR_ID,a.AUTHOR_NAME,b.CATEGORY,sum(b.price*sales) TOTAL_SALES
from book_sales s left join book b on s.book_id = b.book_id left join author a on b.author_id = a.author_id
where YEAR(sales_date)=2022 and month(sales_date)=01
group by author_id,category
order by a.author_id,b.category desc