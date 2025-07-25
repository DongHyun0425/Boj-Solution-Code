-- 코드를 작성해주세요
select count(*) as COUNT
from ECOLI_DATA 
where GENOTYPE & 2 = 0
and (GENOTYPE & 4 = 4 or GENOTYPE & 1 =1)

# 1번 & 1 = 1 3번 & 4 = 4 &2 =0