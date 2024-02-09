-- 코드를 입력하세요
SELECT APNT_NO,PT_NAME,p.PT_NO,a.MCDP_CD,DR_NAME,APNT_YMD
from appointment a left join doctor d on a.mddr_id=d.dr_id left join patient p on a.pt_no = p.pt_no
where YEAR(a.apnt_ymd)=2022 and MONTH(a.apnt_ymd)=04 and DAY(a.apnt_ymd)=13 and a.apnt_cncl_yn like "%N" and a.mcdp_cd like "%CS"
order by APNT_YMD