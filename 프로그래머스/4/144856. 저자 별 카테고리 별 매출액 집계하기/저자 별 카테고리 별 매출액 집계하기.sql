-- 코드를 입력하세요
SELECT a.AUTHOR_ID, AUTHOR_NAME, CATEGORY,SUM(sales * price) TOTAL_SALES
from book_sales s join book b on s.book_id=b.book_id
join AUTHOR a ON b.AUTHOR_ID = a.AUTHOR_ID
WHERE YEAR(S.SALES_DATE) = 2022 AND MONTH(S.SALES_DATE) = 1
group by a.author_name, b.category
order by a.author_id, b.category desc