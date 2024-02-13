-- 코드를 입력하세요
SELECT author.AUTHOR_ID,author.AUTHOR_NAME,book.CATEGORY,
sum(book_sales.sales*book.price) total_sales
from book join author on book.author_id = author.author_id join book_sales on book.book_id = book_sales.book_id
where YEAR(sales_date)=2022 and MONTH(sales_date)=01
group by book.category, author.author_name
order by author.author_id, book.category desc
