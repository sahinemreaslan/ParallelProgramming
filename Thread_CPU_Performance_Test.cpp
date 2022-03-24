//em re
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
void *AralikArama(void  )
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
struct yapi{
	int bas;
	int son;
};
int main () 
{
	cout << "Threading Numbers: (1,2,4,8,16,32,64)"; 
	cin >> NUM_THREADS; 
	time_t start, finish;
	
	int add = 400000/NUM_THREADS;
	yapi yapim[NUM_THREADS];
	
	pthread_t threads[NUM_THREADS];
	yapim[0].bas = 0;
	yapim[0].son = add;
	if(NUM_THREADS != 1)
	{
		for(int i = 1;i<NUM_THREADS;i++)
		{
			yapim[i].bas = yapim[i-1].son+1;
			yapim[i].son = add + yapim[i-1].son;
		}
	}
	start = clock();
	for(int i = 0; i < NUM_THREADS; i++ ) 
	{
		pthread_create(&threads[i], NULL, AralikArama, &yapim[i]);
	}
	for (int i = 0; i < NUM_THREADS; i++)
	{
		pthread_join(threads[i],NULL);
		//pthread_detach(threads[i]);
	}
	finish = clock();
	cout << " Kanal Sayisi = "<< NUM_THREADS <<"---> Harcanan Zaman = "<< difftime(finish,start) << " milisaniye\n";
	pthread_exit(NULL);
	return 0;
}
