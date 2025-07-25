select a.ID, a.GENOTYPE, b.GENOTYPE as PARENT_GENOTYPE
from ECOLI_DATA as a left join ECOLI_DATA as b on a.PARENT_ID = b.ID
where a.GENOTYPE & b.GENOTYPE = b.GENOTYPE
order by a.ID

#id 8이 1101
#id 6가 0101
#둘이 비트마스킹 -> 0101
# 값이 부모랑 동일하면 허용