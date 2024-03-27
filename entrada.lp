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


rota_12 = rota_23 + rota_24;
rota_13 = rota_34;


recebido = rota_24 + rota_34;

toneladas = rota_12 + rota_13;


mdl_rota_12 >= -rota_12;
mdl_rota_13 >= -rota_13;
mdl_rota_23 >= -rota_23;
mdl_rota_24 >= -rota_24;
mdl_rota_34 >= -rota_34;

mdl_rota_12 >= rota_12;
mdl_rota_13 >= rota_13;
mdl_rota_23 >= rota_23;
mdl_rota_24 >= rota_24;
mdl_rota_34 >= rota_34;


recurso_necessario_1 = 1 mdl_rota_12 + 2 mdl_rota_13 + 1 mdl_rota_23 + 2 mdl_rota_24 + 3 mdl_rota_34;
recurso_necessario_2 = 1 mdl_rota_12 + 2 mdl_rota_13 + 2 mdl_rota_23 + 1 mdl_rota_24 + 4 mdl_rota_34;
recurso_necessario_3 = 5 mdl_rota_12 + 0 mdl_rota_13 + 0 mdl_rota_23 + 0 mdl_rota_24 + 6 mdl_rota_34;

recurso_comprado_1 = 4 p_1 + 5 p_2;
recurso_comprado_2 = 2 p_1 + 2 p_2;
recurso_comprado_3 = 0 p_1 + 1 p_2;

recurso_nescessario_1 <= recurso_comprado_1;
recurso_nescessario_2 <= recurso_comprado_2;
recurso_nescessario_3 <= recurso_comprado_3;

int rota_12, rota_13, rota_23, rota_24, rota_34;

