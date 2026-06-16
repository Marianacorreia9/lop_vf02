#include <stdio.h>
#include <windows.h>

struct Funcionario {
    char nome[50];
	char cargo[100];
	float salario;
};
int main(){
	
	SetConsoleOutputCP(CP_UTF8);
	
	struct Funcionario funcionario[5] = {
		{"Ana Silva", "Gerente", 5000.00},
		{"Carlos Oliveira", "Analista", 3000.00},
		{"Maria Santos", "Assistente", 2000.00},
		{"Pedro Costa", "Supervisor", 4000.00},
		{"Joao Lima", "Diretor", 8000.00}
	};
	
	FILE *arquivo = fopen("funcionario.csv","w");
	
	if(arquivo == NULL) {
		printf("Erro ao gravar funcionario\n");
		return 1;
	}
	fprintf(arquivo,"Nome;Cargo;Salario\n");
	
	for(int i = 0; i < 5; i++){
		fprintf(arquivo,"%s; %s; %.2f\n",
		funcionario[i].nome, 
		funcionario[i].cargo,
		funcionario[i].salario);
}
	fclose(arquivo);
	
	printf("Arquivo criado com sucesso\n");
	
	getch();
	return 0;
}
