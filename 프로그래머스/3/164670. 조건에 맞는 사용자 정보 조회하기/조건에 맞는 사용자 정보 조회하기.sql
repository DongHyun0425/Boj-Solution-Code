-- 코드를 입력하세요
SELECT u.user_id, u.nickname, concat(u.city," ",u.street_address1," ",u.street_address2) "전체주소", CONCAT(SUBSTRING(U.TLNO, 1, 3), '-', SUBSTRING(U.TLNO, 4, 4), '-', SUBSTRING(U.TLNO, 8)) AS 전화번호
from used_goods_board b left join used_goods_user u on b.writer_id = u.user_id
where b.writer_id in (
    select writer_id from used_goods_board group by writer_id having count(*) >=3
)
group by u.user_id
order by u.user_id desc