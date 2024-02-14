-- 코드를 입력하세요
SELECT TITLE,b.BOARD_ID,REPLY_ID,r.WRITER_ID,r.CONTENTS,date_format(r.CREATED_DATE,"%Y-%m-%d") created_date
from used_goods_board b join used_goods_reply r on b.board_id= r.board_id
where YEAR(b.created_date)=2022 and MONTH(b.created_date)=10
order by created_date, title
