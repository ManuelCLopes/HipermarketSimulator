#pragma once
#include "Estruturas.h"
#include "stdconfig.h"
#include "ficheiros.h"
#include "gestao_hipermercado.h"

void main()
{
	STOCK_PRODUTOS*P = aloca_memoria_produtos(MAX_PRODUTOS);
	completar_stock_produtos(P);
	DADOS_CLIENTE*C = aloca_memoria_clientes(NUM_CLIENTES);
	completar_dados_cliente(C);
	FUNCIONARIO*F = aloca_memoria_funcionarios(NUM_FUNCIONARIOS);
	completar_dados_funcionario(F);

	CAIXA_PAGAMENTO *ca = aloca_memoria_CAIXAS(45);
	
int op, i;
	i = 0;
	GESTAO_HIPERMERCADO * H = HIPERMERCADO_NOVO_DIA(i);
	associar_turnos(F, ca);
	inicializar_caixas(ca);
	do {
		op = menu();
		switch (op)
		{
		case 1:menu_estatisticas(ca, H, P, C, F); break;
		case 2:i++;
			H = HIPERMERCADO_NOVO_DIA(i);
			simulacao_com_paragens(i, ca, H, P, C, F); 
			grava_csv(H);
			break;
		}
	} while (op != 0);
}