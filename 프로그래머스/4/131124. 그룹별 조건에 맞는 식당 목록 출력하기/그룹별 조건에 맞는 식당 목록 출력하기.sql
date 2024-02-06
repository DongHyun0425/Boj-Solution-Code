-- 코드를 입력하세요
SELECT MEMBER_NAME,REVIEW_TEXT,date_format(REVIEW_DATE,"%Y-%m-%d") review_date
from rest_review r left join member_profile p on r.member_id=p.member_id
where r.member_id = (
    select member_id from rest_review group by member_id order by count(*) desc limit 1
)
order by review_date , review_text