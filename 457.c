#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define clrscr() system("cls")
#define sleep(ms) Sleep(ms * 0.5)
#else
#include <unistd.h>
#define clrscr() printf("\e[1;1H\e[2J")
#define sleep(ms) usleep(ms * 500) // usleep aceita microssegundos
#endif

typedef struct status{
    int *mochila;
    char nome [20];

} status;

void inicio (int *mochila);
void ernesto(status *jogador);
void vazio(status *jogador);
void bolado(status *jogador);
void novato(status *jogador);
void jamaicano(status *jogador);

void ordenar(int *vetor);
int busca(int *vetor, int item);
char leitura(FILE *arq);
void salvar_mochila(int *vetor);
status jogador;

int main (void){

    FILE *arq, *p;
    int menu;
    char c;
    
    printf ("  ██╗   ██╗███████╗██████╗      ██╗    ██╗  ██╗███████╗███████╗\n");
    printf ("  ██║   ██║██╔════╝██╔══██╗     ██║    ██║  ██║██╔════╝╚════██║\n");
    printf ("  ██║   ██║█████╗  ██████╔╝     ██║    ███████║███████╗    ██╔╝\n");
    printf ("  ██║   ██║██╔══╝  ██╔══██╗██   ██║    ╚════██║╚════██║   ██╔╝\n");
    printf ("  ╚██████╔╝███████╗██║  ██║╚█████╔╝         ██║███████║   ██║\n");
    printf ("   ╚═════╝ ╚══════╝╚═╝  ╚═╝ ╚════╝          ╚═╝╚══════╝   ╚═╝\n");
    printf ("--------------Seja aprovado ou morra tentando!!!--------------\n");
    
    printf ("\n1. Novo jogo\n2. Continuar\n3. Progresso\n");
    scanf("%d", &menu);
    getchar(); clrscr();
    
    while (menu != 1 && menu != 2 && menu!= 3){

        printf("Opção inválida.");
        getchar(); clrscr();

        printf ("\n1. Novo jogo\n2. Continuar\n3. Progresso\n");
        scanf("%d", &menu);
        getchar(); clrscr();
    }

    if (menu == 3){

        
    	p = fopen("save", "r");
        if (p == NULL) {

        printf("Save inexistente.\n");
        return 1;
        }
        while ((c = fgetc(p)) != EOF) {
            printf("%c", c);
        }
        getchar(); clrscr();
    	fclose(p);
    }

    else if (menu == 1){
        p = fopen("save", "w");
        fclose(p);

	arq = fopen("1main1.txt", "r");
        leitura(arq);
        fclose(arq);
    }
    
    else{
        arq = fopen("1main1.txt", "r");
        leitura(arq);
        fclose(arq);
    }
    
    printf("Qual o seu nome:");
    scanf("%s", jogador.nome);
    getchar(); clrscr();
  
    arq = fopen("1main2.txt", "r");
    
    leitura(arq);
    fclose(arq);

    printf("\n----------[OPÇÕES]----------");
    jogador.mochila = (int *) malloc (3 * sizeof (int));
    inicio(jogador.mochila);
    getchar(); clrscr();

    printf("%s: Legal, hora de ir.", jogador.nome);
    getchar(); clrscr();
  
    if(busca(jogador.mochila, 1) == 1){ // Sem oculos Ernesto
    
        ernesto(&jogador);
      
    }
    else{ // com oculos

        if(busca(jogador.mochila, 5) == 0) {// com GameBoy vazio
            vazio(&jogador);
        }
        else if(busca(jogador.mochila, 2) && busca(jogador.mochila, 4) == 0) { // bolado
            bolado(&jogador);
        } 
        else if(busca(jogador.mochila, 3) && busca(jogador.mochila, 4) == 0){ // Novato
            novato(&jogador);
        }
        else {// jamaicano (1, 2, 3)
            jamaicano(&jogador);
        }
    }
    return 0;
}

void inicio (int *mochila){
    printf("\nEscolha três itens:\n[1] - Oculos\n[2] - Agua\n[3] - Sanduiche\n[4] - Celular\n[5] - GameBoy ");
    
    for(int u = 1; u < 4; u++){
        
        printf("\nEscolha o %dº item ", u);
        scanf("%d", &mochila[u-1]);
    }
    ordenar(mochila);
    salvar_mochila(mochila);  
}

void ernesto(status *jogador){
    FILE *p;
    p = fopen("save", "a");
    fprintf (p, "Motorista:\n");
    fprintf(p, "Ernesto\n");

    int resposta;

    FILE *arq;
    arq = fopen("ernesto.txt", "rt");
    leitura(arq);
    fclose(arq);
    
    printf("[0] - Entregar a varinha \n[1] - Não entregar a varinha\n");
    scanf("%d", &resposta);
    getchar(); clrscr();
    
    if (resposta == 0){
        fprintf(p, "Entregou a varinha\n");
    	arq = fopen("ernesto_sim.txt", "rt");
    	leitura(arq);
    	fclose(arq);
    }
    
    else{ 
        fprintf(p, "Não entregou a varinha\n");
    	arq = fopen("ernesto_nao.txt", "rt");
    	leitura(arq);
    	fclose(arq);
    }
    fclose(p);
}
void vazio(status *jogador){

    FILE *p;
    p = fopen("save", "a");
    fprintf (p, "Motorista:\n");
    fprintf(p, "Do ônibus vazio\n");

    int resposta_1, resposta_2;

    FILE *arq;
    arq = fopen("vazio.txt", "rt");
    leitura(arq);
    fclose(arq);

    printf("[0] - Sentar na frente \n[1] - Sentar no fundo\n");
    scanf("%d", &resposta_1);
    getchar(); clrscr();
    while (resposta_1 != 0 && resposta_1 != 1){

    	printf("Opção inválida.");
    	getchar(); clrscr();
    	
    	printf("[0] - Sentar na frente \n[1] - Sentar no fundo\n");
    	scanf("%d", &resposta_1);
    	getchar(); clrscr();
    }

    if (resposta_1 == 0){
        fprintf (p, "Você sentou na frente\n");
        arq = fopen("vazio_frente.txt", "rt");
	    leitura(arq);
	    fclose(arq);

        printf("[0] - Entrega o Game Boy \n[1] - Não Entrega o Game Boy\n");
        scanf("%d", &resposta_2);
        getchar(); clrscr();

        while(resposta_2 != 0 && resposta_2 != 1){
            printf("Opção inválida.");
    	    getchar(); clrscr();
    	
    	    printf("[0] - Entrega o Game Boy \n[1] - Não Entrega o Game Boy\n");
            scanf("%d", &resposta_2);
            getchar(); clrscr();
        }
    
	    if (resposta_2 == 0){
            fprintf (p, "Você entregou o Game Boy\n");
	        arq = fopen("vazio_frente_sim.txt", "rt");
	        leitura(arq);
    	    fclose(arq);
	    }

	    else{

            fprintf (p, "Você não entregou o Game Boy\n");
	        arq = fopen("vazio_frente_nao.txt", "rt");
	        leitura(arq);
    	    fclose(arq);
	    }
    
    }

    else{
        fprintf (p, "Você sentou no fundo\n");
	    arq = fopen("vazio_fundo.txt", "rt");
	    leitura(arq);
	    fclose(arq);

	    printf("[0] - Desiste de tentar \n[1] - Continua tentando\n");
        scanf("%d", &resposta_2);
        getchar(); clrscr();

        while(resposta_2 != 0 && resposta_2 != 1){

            printf("Opção inválida.");
    	    getchar(); clrscr();
    	
    	    printf("[0] - Desiste de tentar \n[1] - Continua tentando\n");
            scanf("%d", &resposta_2);
            getchar(); clrscr();
        }
	    
	if (resposta_2 == 0){
            fprintf (p, "Você desistiu de pegar o pokemom\n");
	    arq = fopen("vazio_fundo_nao.txt", "rt");
	    leitura(arq);
	    fclose(arq);
	}

	else{
            fprintf (p, "Você continuo tentando pegar o pokemom\n");
	    arq = fopen("vazio_fundo_sim.txt", "rt");
	    leitura(arq);
	    fclose(arq);
	}
    fclose(p);
    }
}

void bolado(status *jogador){
    FILE *p;
    p = fopen("save", "a");
    fprintf (p, "Motorista:\n");
    fprintf(p, "Bolado\n");

    int resposta_1, resposta_2;

    FILE *arq;
    arq = fopen("bolado.txt", "rt");
    leitura(arq);
    fclose(arq);
    
    printf("----- Filmar briga ----- \n[0] - Não \n[1] - Sim \n");
    scanf("%d", &resposta_1);
    getchar(); clrscr();
    
    while (resposta_1 != 0 && resposta_1 != 1){

    	printf("Opção inválida.");
    	getchar(); clrscr();
    	
    	printf("[0] - Não \n[1] - Sim \n");
    	scanf("%d", &resposta_1);
    	getchar(); clrscr();
    }
    
    if (resposta_1 == 0){
	
        fprintf(p, "Não filmou a briga\n");
    	arq = fopen("bolado_n.txt", "rt");
    	leitura(arq);
    	fclose(arq);
	    
    	while (resposta_2 != 0 && resposta_2 != 1){

    		printf("Opção inválida");
    		getchar(); clrscr();
    
    		printf("----- Dirigir ônibus ----- \n[0] - Não \n[1] - Sim \n");
    		scanf("%d", &resposta_2);
    		getchar(); clrscr();
	    }
    	
    	if (resposta_2 == 0){
            fprintf(p, "Não dirigiu o ônibus\n");
    	    arq = fopen("bolado_sucesso2.txt", "rt");
    	    leitura(arq);
    	    fclose(arq);
    	}
    	
    	else {
            fprintf(p, "Dirigiu o ônibus\n");
    	    arq = fopen("bolado_fracasso2.txt", "rt");
    	    leitura(arq);
    	    fclose(arq);
    	    }
        }
    	
    else {
        fprintf(p, "Filmou a briga\n");
    	arq = fopen("bolado_s.txt", "rt");
    	leitura(arq);
    	fclose(arq);
    
    	printf("----- Ir ao hospital ----- \n[0] - Não \[1] - Sim \n");
    	scanf("%d", &resposta_2);
    	getchar(); clrscr();
    
    	while (resposta_2 != 0 && resposta_2 != 1){

    		printf("Opção inválida");
    		getchar(); clrscr();
    
    		printf("----- Ir ao Hospital ----- \n[0] - Não \n[1] - Sim \n");
    		scanf("%d", &resposta_2);
    		getchar(); clrscr();
    	}
    
    	if (resposta_2 == 0){
            fprintf(p, "Não foi para o hospital\n");
    	    arq = fopen("bolado_fracasso1.txt", "rt");
    	    leitura(arq);
    	    fclose(arq);
    	}
    
    	else{
            fprintf(p, "Foi para o hospital\n");
            arq = fopen("bolado_sucesso1.txt", "rt");
    	    leitura(arq);
    	    fclose(arq);
    	}
    }
    fclose(p);
}

void novato(status *jogador){

    FILE *p;
    p = fopen("save", "a");
    fprintf (p, "Motorista:\n");
    fprintf(p, "Novato\n");

    int resposta_1, resposta_2;

    FILE *arq;
    arq = fopen("novato.txt", "rt");
    leitura(arq);
    fclose(arq);
    
    printf("----- Emprestar o Celular ----- \n[0] - Não \n[1] - Sim \n");
    scanf("%d", &resposta_1);
    getchar(); clrscr();
    
    while (resposta_1 != 0 && resposta_1 != 1){

        printf("Opção inválida.\n");
        getchar(); clrscr();
        
        printf("----- Emprestar o Celular ----- \n[0] - Não \n[1] - Sim \n");
        scanf("%d", &resposta_1);
        getchar(); clrscr();
    }
    
    if (resposta_1 == 0){
        
        fprintf(p, "Não emprestou o celular\n");
        arq = fopen("novato_nao.txt", "rt");
        leitura(arq);
        fclose(arq);
        
        printf("----- Descer do ônibus ----- \n[0] - Não \n[1] - Sim \n");
        scanf("%d", &resposta_2);
        getchar(); clrscr();
        
        while(resposta_2 != 0 && resposta_2 != 1){
            
	    printf("Opção inválida.");
            getchar(); clrscr();
            
            printf("----- Descer do ônibus ----- \n[0] - Não \n[1] - Sim \n");
            scanf("%d", &resposta_2);
            getchar(); clrscr();
        }
        
        if (resposta_2 == 0){

            fprintf(p, "Não desceu do ônibus\n");
    	    arq = fopen("novato_nao_nao.txt", "rt");
    	    leitura(arq);
    	    fclose(arq);
	    }

        else{

            fprintf(p, "Desceu do ônibus\n");
    	    arq = fopen("novato_nao_sim.txt", "rt");
    	    leitura(arq);
    	    fclose(arq);     
        } 
    }

    else{  
        fprintf(p, "Emprestou o celular\n");
    	arq = fopen("novato_sim.txt", "rt");
    	leitura(arq);
    	fclose(arq);
        
        printf("----- Ir pra UERJ ----- \n[0] - Não \n[1] - Sim \n");
        scanf("%d", &resposta_2);
        getchar(); clrscr();
        
        while(resposta_2 != 0 && resposta_2 != 1){

            printf("Opção inválida.");
            getchar(); clrscr();
            
            printf("----- Ir pra UERJ ----- \n[0] - Não \n[1] - Sim \n");
            scanf("%d", &resposta_2);
            getchar(); clrscr();
        }
        
        if (resposta_2 == 0){

            fprintf(p, "Não foi para a UERJ\n");
	    arq = fopen("novato_sim_nao.txt", "rt");
    	    leitura(arq);
    	    fclose(arq);
        }

        else{

            fprintf(p, "Foi para a UERJ\n");
    	    arq = fopen("novato_sim_sim.txt", "rt");
    	    leitura(arq);
    	    fclose(arq);
        }
    }
    fclose(p);
}

void jamaicano(status *jogador){
    FILE *p;
    p = fopen("save", "a");
    fprintf (p, "Motorista:\n");
    fprintf(p, "Jamaicano\n");

    int resposta_1, resposta_2;
	
    FILE *arq;
    arq = fopen("jamaicano.txt", "rt");
    leitura(arq);
    fclose(arq);
    
    printf("[0] - Troca o sanduíche \n[1] - Fica com o sanduíche\n");
    scanf("%d", &resposta_1);
    getchar(); clrscr();
    
    while (resposta_1 != 0 && resposta_1 != 1){

        printf("Opção inválida.");
        getchar(); clrscr();
            
        printf("[0] - Sim \n[1] - Não\n");
        scanf("%d", &resposta_1);
        getchar(); clrscr();
    }
    
    if (resposta_1 == 0){

        fprintf(p, "Trocou o sanduiche\n");
    	arq = fopen("jamaicano_s.txt", "rt");
    	leitura(arq);
    	fclose(arq);
        printf("[0] - Sim \n[1] - Não\n");
        scanf("%d", &resposta_2);
        getchar(); clrscr();
        
        while (resposta_2 != 0 && resposta_2 != 1){

            printf("Opção inválida.");
            getchar(); clrscr();  
            printf("[0] - Sim \n[1] - Não\n");
            scanf("%d", &resposta_2);
            getchar(); clrscr();
        }
        
        if (resposta_2 == 0){  

            fprintf(p, "Foi ao bandeijão\n");
    	    arq = fopen("jamaicano_fracasso1.txt", "rt");
    	    leitura(arq);
    	    fclose(arq);
        }
        
        else{

            fprintf(p, "Não foi ao bandeijão\n");
	    arq = fopen("jamaicano_sucesso1.txt", "rt");
    	    leitura(arq);
    	    fclose(arq);
	    }
    }
    
    else{
    	fprintf(p, "Não trocou o sanduiche\n");
	arq = fopen("jamaicano_n.txt", "rt");
    	leitura(arq);
    	fclose(arq);
	    
        printf("[0] - Sim \n[1] - Não\n");
        scanf("%d", &resposta_2);
        getchar(); clrscr();
        
        while (resposta_2 != 0 && resposta_2 != 1){

            printf("Opção inválida.");
            getchar(); clrscr();

            printf("[0] - Sim \n[1] - Não\n");
            scanf("%d", &resposta_2);
            getchar(); clrscr();
        }
        
        if (resposta_2 == 0){

            fprintf(p, "Bebeu água do bebedouro\n");
    	    arq = fopen("jamaicano_fracasso2.txt", "rt");
    	    leitura(arq);
    	    fclose(arq);
        }
    
        else{
            
            fprintf(p, "Apresentou o trabalho com sede\n");
	    arq = fopen("jamaicano_sucesso2.txt", "rt");
    	    leitura(arq);
    	    fclose(arq);
	    }
    }
    fclose(p);
}

void ordenar(int *vetor){

    int key, j;
    
    for(int i =1; i<3; i++){

        key = vetor[i];
        j = i-1;
        while( key < vetor[j] && j >=0){

            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j+1] = key;
    } 
}

int busca(int * vetor, int item){
    
    for(int i = 0; i<3; i++){

        if(vetor[i] == item){

            return 0;
        }
    }
    return 1;
}


char leitura(FILE *arq){

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    char c;
    while ((c = fgetc(arq)) != EOF){

        if (c == '@'){
            c = ' ';
            printf ("%s", jogador.nome);
        }
        
        printf("%c", c); // Imprime o caractere
        fflush(stdout);  // Garante que o caractere seja mostrado imediatamente
        sleep(30);      // Delay de 100 milissegundos entre cada caractere
        if (c == '\n') {
            getchar(); // Espera pelo Enter do usuário
            clrscr();
        }
    }
    return 0;
}

void salvar_mochila(int *vetor)
{
    FILE *p;
    p = fopen("save", "a");
    fprintf (p, "\nJogador: %s\nMochila:\n", jogador.nome);
    
    for(int i =0; i <3; i++){
        
        switch(vetor[i]){
            case 1:
                fprintf(p, "óculos\n");
                break;
            case 2:
                fprintf(p, "água\n");
                break;
            case 3:
                fprintf(p, "Sanduiche\n");
                break;
            case 4:
                fprintf(p, "Celular\n");
                break;
            case 5:
                fprintf(p, "GameBoy\n");
                break;    
        }
    }
    fprintf(p, "\n");
    fclose (p);
}
