-- 코드를 입력하세요
SELECT info.REST_ID,info.REST_NAME,info.FOOD_TYPE,info.FAVORITES,info.ADDRESS, round(avg(review_score),2) SCORE
from rest_info info join rest_review review on info.rest_id=review.rest_id
where address like "서울%"
group by rest_id
order by score desc, info.favorites desc
