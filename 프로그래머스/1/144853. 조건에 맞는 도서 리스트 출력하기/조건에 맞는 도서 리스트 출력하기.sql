-- 코드를 입력하세요
SELECT BOOK_ID,date_format(PUBLISHED_DATE,"%Y-%m-%d") published_date
from book
where YEAR(published_date)='2021' and category="인문"
order by published_date