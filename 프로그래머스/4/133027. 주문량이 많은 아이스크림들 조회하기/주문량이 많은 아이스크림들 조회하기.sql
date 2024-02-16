-- 코드를 입력하세요
SELECT half.flavor
from first_half half join july on half.flavor = july.flavor
group by half.flavor
order by sum(half.total_order)+sum(july.total_order) desc
limit 3
