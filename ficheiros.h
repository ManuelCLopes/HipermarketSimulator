#pragma once
#include "stdconfig.h"
#include "Estruturas.h"

STRING *Read_Split_Line_File(FILE *, int, int *, char *);
void completar_dados_cliente(DADOS_CLIENTE*);
void completar_dados_funcionario(FUNCIONARIO*);
void completar_stock_produtos(STOCK_PRODUTOS*);
void grava_csv(GESTAO_HIPERMERCADO*);
