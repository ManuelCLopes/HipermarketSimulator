#include "ficheiros.h"

typedef char LinhaTexto[MAX_LINHA_FICHEIRO];
LinhaTexto LT;

STRING *Read_Split_Line_File(FILE *f, int n_campos_max, int *n_campos_lidos, const char *separadores)
{
	*n_campos_lidos = 0;
	if (!f) return NULL;
	if (fgets(LT, MAX_LINHA_FICHEIRO, f) != NULL)	// fgets lê uma linha do ficheiro de texto para a string LT
	{
		// "partir" a linha lida, usando os separadores definidos
		STRING *Res = (STRING *)malloc(n_campos_max * sizeof(STRING));  // alocação de um array com n_campos_max ponteiros para STRING
		char *pch = strtok(LT, separadores);
		int cont = 0;
		while (pch != NULL)
		{
			Res[cont] = (char *)malloc((strlen(pch) + 1) * sizeof(char)); // alocação do espaço necessário para guardar a string correspondente ao campo
			strcpy(Res[cont++], pch);
			pch = strtok(NULL, separadores);
		}
		*n_campos_lidos = cont;
		return Res;
	}
	return NULL;
}
void completar_dados_cliente(DADOS_CLIENTE* p)
{
	FILE *fic;
	int n_campos_lidos;
	int campos_max = 2;
	int x = 0;
	fic = fopen("clientes.txt", "r");
	while (!feof(fic))
	{
		if (fic == NULL)
			fprintf(stderr, "\nImpossivel abrir ficheiro!");
		else
		{
			STRING *U = Read_Split_Line_File(fic, campos_max, &n_campos_lidos, "\t\r\n");
			for (int i = 0; i < n_campos_lidos; i++)
			{
				(p+x)->codigo_cliente = atoi(U[i]);
				i++;
				strcpy((*(p + x)).nome_cliente, U[i]);
				(p + x)->estado = 0;
				(p + x)->preco = 0;
				(p + x)->tempo = 0;
				x++;
				
			}
			for (int i = 0; i < n_campos_lidos; i++)
				free(U[i]);
			free(U);
		}
	}
	fclose(fic);
}
void completar_dados_funcionario(FUNCIONARIO* p)
{
	FILE *fic;
	int n_campos_lidos;
	int campos_max = 2;
	int x = 0;
	fic = fopen("funcionarios.txt", "r");
	while (!feof(fic))
	{
		if (fic == NULL)
			fprintf(stderr, "\nImpossivel abrir ficheiro!");
		else
		{
			STRING *U = Read_Split_Line_File(fic, campos_max, &n_campos_lidos, "\t\r\n");
			for (int i = 0; i < n_campos_lidos; i++)
			{
				strcpy((*(p + x)).codigo, U[i]);
				i++;
				strcpy((*(p + x)).nome_funcionario, U[i]);
				x++;
			}
			for (int i = 0; i < n_campos_lidos; i++)
				free(U[i]);
			free(U);
		}
	}
	fclose(fic);
}
void completar_stock_produtos(STOCK_PRODUTOS* p)
{
	FILE *fic;
	int n_campos_lidos;
	int campos_max = 5;
	int x = 0;
	fic = fopen("produtos.txt", "r");
	while (!feof(fic))
	{
		if (fic == NULL)
			fprintf(stderr, "\nImpossivel abrir ficheiro!");
		else
		{
			STRING *U = Read_Split_Line_File(fic, campos_max, &n_campos_lidos, "\t\r\n");
			for (int i = 0; i < n_campos_lidos; i++)
			{
				strcpy((*(p + x)).codigo, U[i]);
				i++;
				strcpy((*(p + x)).nome, U[i]);
				i++;
				strcpy((*(p + x)).preco, U[i]);
				i++;
				strcpy((*(p + x)).tempo_de_compra, U[i]);
				i++;
				strcpy((*(p + x)).tempo_caixa, U[i]);
				x++;
			}
			for (int i = 0; i < n_campos_lidos; i++)
				free(U[i]);
			free(U);
		}
	}
	fclose(fic);
}
void grava_csv(GESTAO_HIPERMERCADO*h)
{
	//DIA       PRODUTOS VENDIDOS      VALOR EM VENDAS DIARIO
	FILE *historico = fopen("Historico.csv", "w");
	fprintf(historico, "%d;%d;%d;", h->dia, h->n_produtos_vendidos, h->total_vendas);
	fprintf(historico, "\n");
	fclose(historico);
}