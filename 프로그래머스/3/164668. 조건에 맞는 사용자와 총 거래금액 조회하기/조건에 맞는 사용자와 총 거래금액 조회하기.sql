-- 코드를 입력하세요
SELECT user_id, nickname, sum(price) total_sales
from used_goods_user user left join used_goods_board board on user.user_id = board.writer_id
where status = "DONE"
group by user_id
having total_sales >=700000
order by total_sales