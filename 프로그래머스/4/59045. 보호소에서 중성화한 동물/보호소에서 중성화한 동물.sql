-- 코드를 입력하세요
SELECT iin.animal_id, iin.animal_type,iin.name
from animal_ins iin join animal_outs oout on iin.animal_id = oout.animal_id
where iin.sex_upon_intake like "%Intact%" and (oout.sex_upon_outcome like "%Spayed%" or oout.sex_upon_outcome like "%Neutered%")
order by iin.animal_id
