#include <stdio.h>
#include <string.h>

struct dados_cont {
	char nome[102];
	char email[52];
	char sexo;
	char fone[22];
	int idade; 
	float p, h;

} contato[1000], troc;

void ad_cont()
{

	printf("****ADICIONAR CONTATO****\n");
	int i= 0,x;
	struct dados_cont inserccontato;
	
	printf("Digite o nome do contato completo:\n");

		fgets(inserccontato.nome,102,stdin);
		contato[i].nome[strlen(contato[i].nome)-1] ='\0';

	printf("Digite o telefone (formato: (XX) XXXX-XXXX):\n");

		fgets(inserccontato.fone,22,stdin);
		contato[i].fone[strlen(contato[i].fone)-1] ='\0';

	printf("Digite o e-mail:\n");

		fgets(inserccontato.email,52,stdin);
		contato[i].email[strlen(contato[i].email)-1] ='\0';

	printf("Digite o sexo:\n");	
		scanf("%c", &inserccontato.sexo);

	printf("Digite a idade:\n");
		scanf("%d", &inserccontato.idade);

	printf("Digite o peso:\n");
		scanf("%f", &inserccontato.p);

	printf("Digite a altura:\n");
		scanf("%f",&inserccontato.h);
		for(i=0; i < 1000; i++){
			if(strcmp(contato[i].nome,"")==0){
				x = i;
				break;
			}
		}
	
	strcpy(contato[x].nome,inserccontato.nome);
	strcpy(contato[x].fone,inserccontato.fone);
	strcpy(contato[x].email,inserccontato.email);
	contato[x].sexo=inserccontato.sexo;
	contato[x].idade=inserccontato.idade;
	contato[x].p=inserccontato.p;
	contato[x].h=inserccontato.h;
}

void ex_contato(){
	int j;
	char exclusao[102];

	printf("****EXCLUIR CONTATO****\n");
	printf("Digite o nome da exclusão:\n");
//	getchar();
		fgets(exclusao,102,stdin);
	//exclusao[strlen(exclusao)-1] = '\0';
	int achou = 0;
		for(j=0; j<1000; j++)
			if (strcmp(exclusao,contato[j].nome)==0)
			{
				strcpy(contato[j].nome,"");
				strcpy(contato[j].fone,"");
				strcpy(contato[j].email,"");
				contato[j].sexo='\0';
				contato[j].idade='\0';
				contato[j].p='\0';
				contato[j].h='\0';
				achou = 1;
			}
		if(achou==0){
			printf("****Nome não encontrado!****\n");
			    }

}
//definindo funçao para pequisar contato
void pes_cont(){
	int g;
	char pesquisar[102];
	int busca = 0;

	printf("****PESQUISAR CONTATO****\n");
	printf("Digite o nome da busca:\n");
		fgets(pesquisar,102,stdin);

		for(g=0; g<1000; g++)
			if (strcmp(pesquisar,contato[g].nome)==0)	
			{
				//strcpy(contato[g].nome,"");
				printf("%s\n",contato[g].nome);
			
				//strcpy(contato[g].fone,"");
				printf("%s\n",contato[g].fone);
				
				//strcpy(contato[g].email,"");
				printf("%s\n",contato[g].email);
				
				//contato[g].sexo='\0';
				printf("%c\n",contato[g].sexo);
				
				//contato[g].idade='\0';
				printf("%d\n",contato[g].idade);
				
				//contato[g].p='\0';
				printf("%.2f\n",contato[g].p);
				
				//contato[g].h='\0';
				printf("%.2f\n",contato[g].h);
				
				busca = 1;
				
			}

		if(busca==0)
			{
				printf("****Nome não encontrado!****\n");
			 }
}

// definindo função para visualizar contato
void vis_cont(){
	int l, k, visualizar=0;

/*no laço a seguir irei rodar todo o vetor "contatos",
farei uma comparação do que esta armazenado em posição qualquer, com o que esta armazenado na posição seguinte,
caso seja maior, farei uma troca dos dois valores, farei isso ate que sejam trocados todos os mil valores (caso seja preciso)*/
	for (l=0; l<999; l++){
		for (k=l+1; k<1000; k++){
			if(strcmp(contato[l].nome,contato[k].nome)>0) {
				troc=contato[l]; //usei essa variavel troca só pra guardar o valor temporariamente pra mim não perdela
				contato[l] = contato[k]; //trocando uma pela outra
              contato[k] = troc;  //recuperando oq tava em troc a variavel troc esta definida após o nome da struct, exemplo: {}ctt[1000],troc;
			}
		}
	}

/*vou percorrer todo o vetor procurando uma posição que seja diferente de vazio, ou seja, tenha algo adicionado.
caso encontre vou ativar a variavel de controle para decidir oq fazer logo abaixo*/
	for (l=0;l<1000;l++){
		if (contato[l].nome[0]!='\0'){
			visualizar=1;
	}
		}

	if (visualizar==1){ // se encontrou algo adicionado ira mostrar todos os contatos
	printf ("****VISUALIZAR TODOS OS CONTATOS****\n");
	for (l=0; l<1000; l++){
		if (contato[l].nome[0]!='\0'){
			printf("%s",contato[l].nome);
			printf("%s",contato[l].fone);
			printf ("%s",contato[l].email);
			printf ("%c\n",contato[l].sexo);
			printf ("%d\n",contato[l].idade);
			printf ("%.2f\n",contato[l].p);
			printf ("%.2f\n",contato[l].h);
		}
	}
}
	if (visualizar==0){  //se este laço for "rodado" significa que não foi encontrando nada alem de NULL no cadastro
		printf ("****VISUALIZAR TODOS OS CONTATOS****\n****AGENDA VAZIA!****\n"); //então informa o usuario que a agenda esta vazia
	}
}







		
int main() {
	int i, cont_contato;
	for(i=0; i<1000; i++)
		strcpy(contato[i].nome,"");
		

	do {
		printf("****MENU AGENDA ELETRONICA****\n");// escolher opcoes da agenda
		printf("1: Adicionar contato\n");
		printf("2: Excluir contato\n");
		printf("3: Pesquisar contato\n");
		printf("4: Visualizar todos os contatos\n");
		printf("0: Sair!\n");
	
		scanf("%d",&cont_contato);
		getchar();
	
	switch(cont_contato){
		case 1:
		ad_cont();
		break;

		case 2:
		ex_contato();
		break;

		case 3:
		pes_cont();
		break;

		case 4:
		vis_cont();
		break;

		case 0:

		break;

		default:
		printf("****Opção Inválida, tentar novamente**** ");
		printf("\n");
		break;
			}
	}while(cont_contato!=0);
	
 return 0;
}
