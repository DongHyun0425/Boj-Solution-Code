-- 코드를 입력하세요
SELECT ingredient_type, sum(total_order) total_order
from icecream_info info left join first_half half on info.flavor=half.flavor
group by ingredient_type 