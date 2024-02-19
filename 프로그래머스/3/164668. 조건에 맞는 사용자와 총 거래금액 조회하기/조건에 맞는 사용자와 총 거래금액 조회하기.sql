-- 코드를 입력하세요
SELECT USER_ID,NICKNAME,sum(price) TOTAL_SALES
from used_goods_board b join used_goods_user u on b.writer_id=u.user_id
where STATUS="DONE"
group by user_id
having sum(price)>=700000
order by total_sales