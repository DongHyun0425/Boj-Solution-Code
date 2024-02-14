-- 코드를 입력하세요
SELECT MEMBER_ID,MEMBER_NAME,GENDER, date_format(DATE_OF_BIRTH,"%Y-%m-%d") date_of_birth
from member_profile
where MONTH(date_of_birth)=03 and tlno is not null and gender="W"
order by member_id