#include <stdio.h>

void main(){
        int tab[50]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49};
	int low = 0;
	int high = 49;
	int key = 2;
	int mid = (low+high)/2;
	
	while(tab[mid]!=key){
		if(tab[mid]>key){
			high = mid-1;
			mid = (low+high)/2;   
		}
		else if(tab[mid]<key){
			low = mid+1;
			mid = (low+high)/2;
		}
		else{
			printf("Le chiffre n'est pas dans le tableau \n");
		}
	}
	printf("le chiffre %d est à l'index : %d \n",key, mid);
}
