-- 코드를 입력하세요
SELECT ANIMAL_ID,NAME,(case when sex_upon_intake like "%Neutered%" then "O" when sex_upon_intake like "%Spayed%" then "O" else "X" end) 중성화
from animal_ins
order by animal_id,name,중성화