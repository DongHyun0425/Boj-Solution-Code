-- 코드를 입력하세요
SELECT u.user_id, u.nickname, sum(b.price) total_sales
from  used_goods_user u left join used_goods_board b on b.writer_id=u.user_id
where status = "DONE"
group by u.user_id
having sum(b.price)>=700000
order by total_sales