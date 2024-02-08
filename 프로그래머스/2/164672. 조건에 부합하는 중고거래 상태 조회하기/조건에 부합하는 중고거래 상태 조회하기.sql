-- 코드를 입력하세요
SELECT a.BOARD_ID,a.WRITER_ID,a.TITLE,a.price,(case a.status  when "DONE" then "거래완료" when "SALE" then "판매중" else "예약중" end ) STATUS
from used_goods_board a
where a.created_date like "%2022-10-05%"
order by a.board_id desc