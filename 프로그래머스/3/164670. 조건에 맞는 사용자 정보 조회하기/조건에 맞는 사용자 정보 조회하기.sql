-- 코드를 입력하세요
SELECT USER_ID,NICKNAME,concat(CITY," ",STREET_ADDRESS1," ",STREET_ADDRESS2) 전체주소, concat(substring(tlno,1,3),"-",substring(tlno,4,4),"-",substring(tlno,8,4)) 전화번호
from used_goods_user
where user_id in (
    select writer_id from used_goods_board group by writer_id having count(*)>=3
)
order by user_id desc