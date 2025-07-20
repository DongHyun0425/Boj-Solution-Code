-- 코드를 입력하세요
SELECT a.TITLE, a.BOARD_ID, b.REPLY_ID, b.WRITER_ID, b.CONTENTS,
DATE_FORMAT(b.CREATED_DATE, '%Y-%m-%d') AS CRAETED_DATE 
from USED_GOODS_BOARD as a join USED_GOODS_REPLY as b on a.board_id = b.board_id 
where SUBSTR(a.CREATED_DATE,1,7) = '2022-10' order by b.CREATED_DATE asc, a.TITLE asc

