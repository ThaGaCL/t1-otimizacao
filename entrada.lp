max: ganho - custo;

ganho = 100 toneladas;
ganho >= 0;

custo = custo_p1 + custo_p2;
custo >= 0; 

custo_p1 = 10 p_1;
p_1 >= 0;
custo_p2 = 20 p_2;
p_2 >= 0;


-5 <= rota_12 <= 5;
-2 <= rota_13 <= 2;
-5 <= rota_23 <= 5;
-2 <= rota_24 <= 2;
-5 <= rota_34 <= 5;

rota_12 = rota_24 + rota_23;
rota_13 = rota_34 + rota_23;
rota_23 = rota_34
tudo que tem como destino x é igual a tudo que tem como origem x
recebido = rota_24 + rota_34;
recebido = toneladas;

toneladas = rota_12 + rota_13;

/* rij = quantidade de i-ésimo recurso do pacote j*/
/*r_11 = 4;
r_21 = 2;
r_31 = 0;

r_12 = 5;
r_22 = 2;
r_32 = 1;
*/

/* sijk quantidade do i-ésimo recurso necessario para rota_ j,k*/

s_112 = 1;
s_212 = 1;
s_312 = 5;

s_113 = 2;
s_213 = 2;
s_313 = 0;

s_123 = 1;
s_223 = 2;
s_323 = 0;

s_124 = 2;
s_224 = 1;
s_324 = 0;

s_134 = 3;
s_234 = 4;
s_334 = 6;  

/* tij é  se a rota_ ij esta presente no trajeto

está em modulo pois as  variaveis binarias podem tomar qualquer valor se a quantidade de toneladas for < 0 */

modulo_rota_12 >= -rota_12;
modulo_rota_12 >= rota_12;
modulo_rota_13 >= -rota_13;
modulo_rota_13 >= rota_13;
modulo_rota_23 >= -rota_23;
modulo_rota_23 >= rota_23;
modulo_rota_24 >= -rota_24;
modulo_rota_24 >= rota_24;
modulo_rota_34 >= -rota_34;
modulo_rota_34 >= rota_34;

modulo_rota_12 <= 5 t_12;
modulo_rota_13 <= 5 t_13;
modulo_rota_23 <= 5 t_23;
modulo_rota_24 <= 5 t_24;
modulo_rota_34 <= 5 t_34;

/* com ajuda da variavel de existencia t_ij, na qual ij é o caminho de i até j, podemos indicar quantos recursos de cada tipo são necessários */

recurso_necessario_1 = 1 t_12 + 2 t_13 + 1 t_23 + 2 t_24 + 3 t_34;
recurso_necessario_2 = 1 t_12 + 2 t_13 + 2 t_23 + 1 t_24 + 4 t_34;
recurso_necessario_3 = 5 t_12 + 0 t_13 + 0 t_23 + 0 t_24 + 6 t_34;

/* a soma de todos os recursos de todas as rotas tem que ser menor do que o disponível nos pacotes comprados */

1 t_12 <= 4 p_1 + 5 p_2 - recurso_necessario_1 + 1 t_12;  
1 t_12 <= 2 p_1 + 2 p_2 - recurso_necessario_2 + 1 t_12;
5 t_12 <= 0 p_1 + 1 p_2 - recurso_necessario_3 + 5 t_12;

2 t_13 <= 4 p_1 + 5 p_2 - recurso_necessario_1 + 2 t_13;  
1 t_13 <= 2 p_1 + 2 p_2 - recurso_necessario_2 + 1 t_13;
0 t_13 <= 0 p_1 + 1 p_2 - recurso_necessario_3 + 0 t_13;

1 t_23 <= 4 p_1 + 5 p_2 - recurso_necessario_1 + 1 t_23;    
2 t_23 <= 2 p_1 + 2 p_2 - recurso_necessario_2 + 2 t_23;
0 t_23 <= 0 p_1 + 1 p_2 - recurso_necessario_3 + 0 t_23;

2 t_24 <= 4 p_1 + 5 p_2 - recurso_necessario_1 + 2 t_24;  
1 t_24 <= 2 p_1 + 2 p_2 - recurso_necessario_2 + 1 t_24;
0 t_24 <= 0 p_1 + 1 p_2 - recurso_necessario_3 + 0 t_24;

3 t_34 <= 4 p_1 + 5 p_2 - recurso_necessario_1 + 3 t_34;
4 t_34 <= 2 p_1 + 2 p_2 - recurso_necessario_2 + 4 t_34;
6 t_34 <= 0 p_1 + 1 p_2 - recurso_necessario_3 + 6 t_34;

/* aqui garantimos que os recursos necessários não ultrapassem a quantidade comprada */

recurso_necessario_1 <= recurso_comprado_1;
recurso_necessario_2 <= recurso_comprado_2;
recurso_necessario_3 <= recurso_comprado_3;

recurso_comprado_1 = 4 p_1 + 5 p_2;
recurso_comprado_2 = 2 p_1 + 2 p_2;
recurso_comprado_3 = 1 p_2;

bin t_12, t_13, t_23, t_24, t_34;
int rota_12, rota_13, rota_23, rota_24, rota_34;