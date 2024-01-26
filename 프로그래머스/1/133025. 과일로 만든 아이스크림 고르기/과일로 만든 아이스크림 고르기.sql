-- 코드를 입력하세요
SELECT F.FLAVOR from FIRST_HALF as F left join ICECREAM_INFO as I on F.FLAVOR=I.FLAVOR where F.TOTAL_ORDER>3000 and I.INGREDIENT_TYPE = "fruit_based"