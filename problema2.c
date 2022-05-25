#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *function1();
void *function2();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int x;
int main(int argv, char* argc[])
{
 int rc1, rc2;

char* c=argc[1];
x=atoi(c);


 pthread_t thread1, thread2;
 /* creare thread-uri */
 if( (rc1=pthread_create( &thread1, NULL, &function1, NULL)) )
 {
 printf("Eroare de creare thread-uri! %d \n", rc1);
 }
 if( (rc2=pthread_create( &thread2, NULL, &function2, NULL)) )
 {
 printf("Eroare de creare thread-uri! %d\n", rc2);
 }
 pthread_join( thread1, NULL);
 pthread_join( thread2, NULL);
 printf("Sfarsit executie threaduri!\n");

}

void *function1()
{
 double imp;
 for(int i=1;i<=x/2;i++){
 pthread_mutex_lock( &mutex1 );
 imp=1/x;
 
 printf("Accesare 1/x de catre thread 1!\n");
 printf("Valoare 1/x = %lf\n",imp);
 pthread_mutex_unlock( &mutex1 );
 sleep(1);
}
}
void *function2()
{
 double imp;
 for(int i=1;i<=x/2;i++){
 pthread_mutex_lock( &mutex1 );
 imp=1/x;
 
 printf("Accesare 1/x de catre thread 2!\n");
 printf("Valoare 1/x = %lf\n",imp);
 pthread_mutex_unlock( &mutex1 );
 sleep(1);
}
}