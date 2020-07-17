#include "stdio.h"
#include "time.h"
#include "math.h"
#include "pthread.h"
#include "stdlib.h" 



void* estimativaPi (void *NrPontos_ptr) {

  int *NrPontos = (int*) (NrPontos_ptr); 
  
  /* Corresponde as coordenadas do eixo cartesiano */
  double x,y;                    
  
  /* Aproximação ao valor de  π */
  double estimativaPI;

  /* Corresponde ao raio do círculo */
  double raio = 1;     

  double comprimento;
  int circle_count = 0;      

 /* Gerador de números aleatórios */

	srandom((unsigned)time(NULL)); 
	for (int i = 0; i <= *NrPontos; i++) {

		/* x ∈ [-1,1] ???? */ 
		/* y ∈ [-1,1] ???? */
		x = ((double)(random())/(double)(RAND_MAX)*1.0 );  
		y = ((double)(random())/(double)(RAND_MAX)*1.0 );  

		comprimento = sqrt((pow((x-raio),2)) + (pow((y-raio),2)));
		
		if(comprimento <= raio) 
			circle_count++;     
		
	}             

  estimativaPI = (double) 4*circle_count/(*NrPontos) ; 

  	

  	printf("------- Thread Nr: %d -------\n",(int) pthread_self());

	printf("π :%lf  	Estimativa de π : %lf\n\n",M_PI,estimativaPI); 

 /* Provoca a terminação da thread e a libertação dos recursos que esta está a consumir */	
	pthread_exit (NULL);  	
}



int main (int argc, char **argv) {

	/* Corresponde ao número de Threads sendo que o seu valor é passado no stdin */
	int NrThreads = atoi (argv[1]);
	
	/* Corresponde ao número de Pontos sendo que o seu valor é passado no stdin */
	 int NrPontos = atoi (argv[2]);

printf("-------------------------------------------------------------------------------\n");  
  printf("Número de Threads : %i\n", NrThreads);
  printf("Número de Pontos  : %i\n\n", NrPontos);
  
  pthread_t Threads[NrThreads];  // identinficador de nova Thread

 /*	Calcular o tempo de  execução */
	clock_t TempoInicial,TempoFinal;  //Declarar o tempo inicail e tempo final
    double TempoExecucao;
    TempoInicial = clock();

	for(int i=0; i<NrThreads; i++)
  		pthread_create(Threads+i, NULL,estimativaPi,&NrPontos); 


	for(int i=0; i<NrThreads; ++i)
		pthread_join(Threads[i],NULL); 
	
     TempoFinal = clock(); 

     /* Corresponde ao tempo de execução em millisegundo */
    TempoExecucao = ((TempoFinal - TempoInicial)/(CLOCKS_PER_SEC/1000.)); 
    printf("Tempo de execução: %g ms.\n", TempoExecucao); 

printf("-------------------------------------------------------------------------------\n");  


  return 0;
}
