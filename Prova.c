#include <stdio.h>
#include <windows.h>

struct Funcionario
{
	char nome[50];
	char cargo[30];
	float salario;
};

int main()
{
	FILE *arquivo;
	
	struct Funcionario funcionario[100];
	
	int total = 0;
	float somaSalarios = 0;
	float salarioMedio;
	
	char cabecalho[100];
	
	arquivo = fopen("funcionarios.csv", "r");
	
	if (arquivo == NULL)
	{
		printf("Erro ao abrir o arquivo!");
		return 1;
	}
	
	fgets(cabecalho, 100, arquivo);
	
	while (fscanf(arquivo,"%49[^;];%29[^;];%f",
	                 funcionario[total].nome,
					 funcionario[total].cargo,
					 &funcionario[total].salario) == 3)
	{
		somaSalarios += funcionario[total].salario;
		total++;
	}
	
	fclose(arquivo);
	
	printf("RELATORIO DE FUNCIONARIOS\n\n");
	
	for (int i = 0; i < total; i++)
	{
		printf("Nome: %s\n", funcionario[i].nome);
		printf("Cargo: %s\n", funcionario[i].cargo);
		printf("Salario: R$ %.2f\n", funcionario[i].salario);
	}
	
	salarioMedio = somaSalarios / total;
	
	printf("Total de funcionarios: %d\n", total);
	printf("Salario medio: R$ %.2f\n", salarioMedio);
	
	return 0;
	
}