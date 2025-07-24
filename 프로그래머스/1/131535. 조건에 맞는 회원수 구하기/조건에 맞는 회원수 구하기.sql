-- 코드를 입력하세요
SELECT COUNT(USER_ID)
from USER_INFO 
where JOINED like ("2021%") and Age between 20 and 29
