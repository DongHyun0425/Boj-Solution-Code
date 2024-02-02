-- 코드를 입력하세요
SELECT board.writer_id,user.NICKNAME, sum(board.price) TOTAL_SALES 
from used_goods_board board left join used_goods_user user on user.user_id=board.writer_id 
where board.status="DONE"
group by board.writer_Id having total_sales>=700000  
ORDER BY TOTAL_SALES