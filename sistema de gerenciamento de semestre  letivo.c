#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200

int totAlunos = 0;

typedef struct{
	float av1, av2, av3;
}materia;

typedef struct{
	int matricula;
	char nome[20];
	float score;
	materia calc;
	materia lp1;
	materia arq;
	materia sist;
	materia graf;
}Aluno;

int menu();
void cadastrar(Aluno[]);
void listar(Aluno[]);
void excluir(Aluno[]);
void editar(Aluno[]);
void calcularscore(Aluno[], int);

main(){
	Aluno vetordealuno[N];
	int i, opcao=-1;;
	while(opcao!=5){
		opcao = menu();
		system("cls");
		if(opcao == 1)
		   cadastrar(vetordealuno);
		if(opcao == 2)
			listar(vetordealuno);
		if(opcao == 3)
			excluir(vetordealuno);	
		if(opcao == 4)
			editar(vetordealuno);
		if(opcao == 5){
			printf("O programa esta sendo encerrado!");
			printf("ATENCAO, os seus dados NAO serao armazenados permanentemente!\n");
		}
	}
	system("pause");
	return 0;
}

int menu(){
	int opc;
	system("cls");
	printf("\t*****************MENU DE OPCOES*******************\n");
	printf("\t 1 - Cadastrar;\n");
	printf("\t 2 - Listar;\n");
	printf("\t 3 - Exluir;\n");
	printf("\t 4 - Editar;\n");
	printf("\t 5 - Sair do programa;\n");
	printf("\t Digite a opcao escolhida:\n\t");
	scanf("%d", &opc);	
	return opc;
	}
	
void cadastrar(Aluno Alunos[]){
	getchar();
	printf("\tInforme a matricula do aluno:\n\t");
	scanf("%d",&Alunos[totAlunos].matricula);
	printf("\tInforme o nome do aluno:\n\t");
	getchar();
	gets(Alunos[totAlunos].nome);
	printf("\tInforme as 3 notas da disciplina Calculo I:\n");
	scanf("%f%f%f", &Alunos[totAlunos].calc.av1, &Alunos[totAlunos].calc.av2, &Alunos[totAlunos].calc.av3);
	printf("\tInforme as 3 notas da disciplina LP1 i:\n");
	scanf("%f%f%f", &Alunos[totAlunos].lp1.av1, &Alunos[totAlunos].lp1.av2, &Alunos[totAlunos].lp1.av3);
	printf("\tInforme as 3 notas da disciplina Arq. Comp.:\n");
	scanf("%f%f%f", &Alunos[totAlunos].arq.av1, &Alunos[totAlunos].arq.av2, &Alunos[totAlunos].arq.av3);
	printf("\tInforme as 3 notas da disciplina Sit. Operac.:\n");
	scanf("%f%f%f", &Alunos[totAlunos].sist.av1, &Alunos[totAlunos].sist.av2, &Alunos[totAlunos].sist.av3);
	printf("\tInforme as 3 notas da disciplina Com. Grafica:\n");
	scanf("%f%f%f", &Alunos[totAlunos].graf.av1, &Alunos[totAlunos].graf.av2, &Alunos[totAlunos].graf.av3);
	calcularscore(Alunos, totAlunos);
	totAlunos++;
	system("cls");
	printf("\tCADASTRO REALIZADO COM SUCESSO!\n\t");
	system("pause");
}

void listar(Aluno Alunos[]){
	int i, op, id;
	printf("\t 1 - TODOS;\n");
	printf("\t 2 - ESPECIFICO;\n");
	printf("\t 3 - ALUNO COM MELHOR DESEMPENHO\n");
	printf("\t 4 - ALUNO COM PIOR DESEMPENHO\n");
	scanf("%d", &op);
	system("cls");
	if(op==1){
		if(totAlunos<=0)
			printf("\tNAO EXISTE ALUNOS CADASTRADOS\n");
		else
			printf("Nome:\t\t Matricula: \t Score:\t\n");
			for(i=0; i<totAlunos; i++){
				printf("%s\t\t",Alunos[i].nome);
				printf("%d\t",Alunos[i].matricula);
				printf("%f\t\n",Alunos[i].score);
		}
	}
	if(op==2){
		printf("\tInforme a matricula do aluno\n");
		scanf("%d", &id);
		for(i=0; i<totAlunos; i++){
			if(id==Alunos[i].matricula){
				printf("Nome:\t\t Matricula: \t Score:\t\n");
				printf("%s\t\t",Alunos[i].nome);
				printf("%d\t",Alunos[i].matricula);
				printf("%f\t\n",Alunos[i].score);
			}
		}
	}
	if(op==3){
		float melhor=Alunos[0].score;
		int posicao;
		for(i=0; i<totAlunos; i++){
			if(melhor<Alunos[i].score){
				melhor=Alunos[i].score;
				posicao=i;
			}
		}
		printf("Nome:\t\t Matricula: \t Score:\t\n");
		printf("%s\t\t",Alunos[posicao].nome);
		printf("%d\t",Alunos[posicao].matricula);
		printf("%f\t\n",Alunos[posicao].score);	
	}
	if(op==4){
		float pior=Alunos[0].score;
		int posicao;
		for(i=0; i<totAlunos; i++){
			if(pior>Alunos[i].score){
				pior=Alunos[i].score;
				posicao=i;
			}
		}
		printf("Nome:\t\t Matricula: \t Score:\t\n");
		printf("%s\t\t",Alunos[posicao].nome);
		printf("%d\t",Alunos[posicao].matricula);
		printf("%f\t\n",Alunos[posicao].score);	
		
	}
	printf("\t");
	system("pause");
}

void editar(Aluno Alunos[]){
	int id, i, j;
	if(totAlunos<=0)
		printf("\tNAO EXISTE ALUNOS CADASTRADOS\n");
	else
		printf("\tInforme a matricula do aluno\n");
		scanf("%d", &id);
		for(i=0; i<totAlunos; i++){
			if(id==Alunos[i].matricula){
				printf("\tInforme o nome do aluno:\n\t");
				getchar();
				gets(Alunos[i].nome);
				printf("\tInforme as 3 notas da disciplina Calculo I:\n");
				scanf("%f%f%f", &Alunos[i].calc.av1, &Alunos[i].calc.av2, &Alunos[i].calc.av3);
				printf("\tInforme as 3 notas da disciplina LP1 i:\n");
				scanf("%f%f%f", &Alunos[i].lp1.av1, &Alunos[i].lp1.av2, &Alunos[i].lp1.av3);
				printf("\tInforme as 3 notas da disciplina Arq. Comp.:\n");
				scanf("%f%f%f", &Alunos[i].arq.av1, &Alunos[i].arq.av2, &Alunos[i].arq.av3);
				printf("\tInforme as 3 notas da disciplina Sit. Operac.:\n");
				scanf("%f%f%f", &Alunos[i].sist.av1, &Alunos[i].sist.av2, &Alunos[i].sist.av3);
				printf("\tInforme as 3 notas da disciplina Com. Grafica:\n");
				scanf("%f%f%f", &Alunos[i].graf.av1, &Alunos[i].graf.av2, &Alunos[i].graf.av3);
				calcularscore(Alunos, i);
				printf("\t CADASTRO ATUALIZADO COM SUCESSO!\n");
				break;
			}
		}
	printf("\t");
	system("pause");
}

void excluir(Aluno Alunos[]){
	int id, i, j;
	if(totAlunos<=0)
		printf("\tNAO EXISTE ALUNOS CADASTRADOS\n");
	else
		printf("\tInforme a matricula do aluno\n");
		scanf("%d", &id);
		for(i=0; i<totAlunos; i++){
			if(id==Alunos[i].matricula){
				for(j=i; j<totAlunos; j++)//substitui o livro pelo proximo do vetor e corrige as demais posições
					Alunos[j]=Alunos[j+1];
				totAlunos--;
				printf("\t CADASTRO APAGADO COM SUCESSO!\n");
				break;
			}
		}
	printf("\t");
	system("pause");
}

void calcularscore(Aluno fazscore[], int c){
	float media=0;
	media = media + ((fazscore[c].calc.av1 + fazscore[c].calc.av2 + fazscore[c].calc.av3)/3);
	media = media + ((fazscore[c].lp1.av1 + fazscore[c].lp1.av2 + fazscore[c].lp1.av3)/3);
	media = media + ((fazscore[c].arq.av1 + fazscore[c].arq.av2 + fazscore[c].arq.av3)/3);
	media = media + ((fazscore[c].sist.av1 + fazscore[c].sist.av2 + fazscore[c].sist.av3)/3);
	media = media + ((fazscore[c].graf.av1 + fazscore[c].graf.av2 + fazscore[c].graf.av3)/3);
	fazscore[c].score = media/5;
}
