use chenht_University_Mis
go
create rule cht_Rule_sex as @Value in ('F','M')
go
exec SP_bindrule cht_Rule_sex,'chenht_Teacher.[cht_Tsex]'
