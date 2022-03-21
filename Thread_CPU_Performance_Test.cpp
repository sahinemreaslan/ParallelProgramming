#include <iostream>
#include <ctime>
#include <pthread.h>
#include <unistd.h>
using namespace std;
int NUM_THREADS;

bool asalSayi(int sayi)
{
	if (sayi < 2) return false;
	int i = 2;
	int sinir = sayi/2;
	while(i <= sinir)
	{
		if (sayi % i == 0) return false;
		i++;
	}
}
void *AralikArama(void *args)
{
	int *limit = (int*) args;
	for(int i = limit[0]; i<= limit[1]; i++)
	{
		if(asalSayi(i))
		{
			//cout << " " << i << "";
		}
	}
}
int main () 
{
	cout << "Threading Numbers: (1,2,4,8,16,32,64)"; // Type a number and press enter
	cin >> NUM_THREADS; // Get user input from the keyboard
	time_t start, finish;
	pthread_t threads[NUM_THREADS];
	int toplam = 0;
	int aralik[2];
	aralik[0] = 0;
	aralik[1] = 1000000/NUM_THREADS;
	int arttir = aralik[1];
	for(int i = 0; i < NUM_THREADS; i++ ) 
	{
		start = clock();
		pthread_create(&threads[i], NULL, AralikArama, aralik);
		pthread_join(threads[i],NULL);
	  	finish = clock();
	  	//printf("%d.kanal",i);
	  	cout << " Kanal"<< i+1 <<"---> Harcanan Zaman = "<< difftime(finish,start) << " milisaniye\n";
	  	printf("\n");
	  	toplam += difftime(finish,start);
	  	//aralik deðerini ilerlet
		aralik[0] = aralik[1]+1;
		aralik[1] += arttir;
	}
	printf("%d",toplam);
	pthread_exit(NULL);
	return 0;
}
