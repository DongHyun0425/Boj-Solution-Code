-- 코드를 입력하세요
SELECT concat("/home/grep/src/",b.board_id,"/",f.file_id,f.file_name,f.file_ext) file_path
from used_goods_board b left join used_goods_file f on b.board_id = f.board_id
where b.board_id = (select b.board_id from
used_goods_board b
order by b.views desc
limit 1
)
order by file_id desc