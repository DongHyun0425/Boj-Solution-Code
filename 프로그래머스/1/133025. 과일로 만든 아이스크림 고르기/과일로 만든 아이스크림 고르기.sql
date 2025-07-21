-- 코드를 입력하세요
SELECT a.FLAVOR
from FIRST_HALF as a join ICECREAM_INFO as b on a.FLAVOR = b.FLAVOR
where a.TOTAL_ORDER > 3000 and b.INGREDIENT_TYPE like "fruit_based"
order by a.TOTAL_ORDER desc

# and b.INGREDIENT_TYPE like "fruit_based"