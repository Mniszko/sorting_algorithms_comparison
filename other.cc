#include "other.h"
/*
mało wydajne ale działające rozwiązanie określa z góry tablicę 1000x300 permutacji na której działają sorty
/**/
/*
zliczania odbywają się przez dodawanie do odpowiedniej dwukrotki jedynki, na koniec liczby wpisywane są do pliku obsługiwanego przez octave
/**/
void Sorting::change_val(int *a, int *b){
    int non = *a;
    *a=*b;
    *b=non;
    return;
}

void Sorting::change_arval(int* arr, int pos1,int pos2){
    int chngr = arr[pos2];
    arr[pos2]=arr[pos1];
    arr[pos1]=chngr;
    return;
}

void Sorting::permutation(){
    for (auto& raw : this->permutations){
        for (int i=299 ; i>-1 ; --i){
            int pos = rand()%(i+1);
            this->change_val(&(this->temp[i]),&(this->temp[pos]));
        //losowanie permutacji
        }
        for (int i=0 ; i<300 ; ++i){
            raw[i] = this->temp[i];
            this->temp[i] = i+1;
        //powracanie do podstawowej formy temp oraz przepisanie na macierz permutacji
        }
    }
}

Sorting::Sorting(){
    for (int i=0 ; i<1000 ; ++i){
        for (int k=0 ; k<300 ; ++k){
            this->permutations[i][k] = 301;
        }
    }
        this->selection_sort=new int[1000];
        this->insertion_sort=new int[1000];
        this->bubble_sort=new int[1000];
        this->quick_sort=new int[1000];
        this->merge_srt=new int[1000];
        this->heap_sort=new int[1000];

        this->selection_sort1=new int[1000];
        this->insertion_sort1=new int[1000];
        this->bubble_sort1=new int[1000];
        this->quick_sort1=new int[1000];
        this->merge_srt1=new int[1000];
        this->heap_sort1=new int[1000];
    for(int i=0 ; i<1000 ; ++i){
        selection_sort[i]=0;
        selection_sort1[i]=0;
    }
    for(int i=0 ; i<1000 ; ++i){
        this->insertion_sort[i]=0;
        this->insertion_sort1[i]=0;
    }
    for(int i=0 ; i<1000 ; ++i){
        this->bubble_sort[i]=0;
        this->bubble_sort1[i]=0;
    }
    for(int i=0 ; i<1000 ; ++i){
        this->quick_sort[i]=0;
        this->quick_sort1[i]=0;
    }
    for(int i=0 ; i<1000 ; ++i){
        this->merge_srt[i]=0;
        this->merge_srt1[i]=0;
    }
    for(int i=0 ; i<1000 ; ++i){
        this->heap_sort[i]=0;
        this->heap_sort1[i]=0;
    }
    
    for (int i=0 ; i<300 ; ++i){
        this->temp[i] = i+1;
    }
    this->permutation();
    //inicjalizuje tablicę permutacji i wszystkie krotki na dane sortowań
}

void Sorting::write_down(){
    std::ofstream File("can.txt");
    for(int i=0 ; i<1000 ; ++i){
        File << selection_sort[i] << '\t';
    }
    File << std::endl;
    for(int i=0 ; i<1000 ; ++i){
        File << selection_sort[i] << '\t';
    }
    File << std::endl;
    for(int i=0 ; i<1000 ; ++i){
        File << selection_sort1[i] << '\t';
    }
    File << std::endl;
    for(int i=0 ; i<1000 ; ++i){
        File << insertion_sort[i] << '\t';
    }
    File << std::endl;
    for(int i=0 ; i<1000 ; ++i){
        File << insertion_sort1[i] << '\t';
    }

    File << std::endl;
    for(int i=0 ; i<1000 ; ++i){
        File << bubble_sort[i] << '\t';
    }
    File << std::endl;
    for(int i=0 ; i<1000 ; ++i){
        File << bubble_sort1[i] << '\t';
    }
    File << std::endl;
    
    for(int i=0 ; i<1000 ; ++i){
        File << quick_sort[i] << '\t';
    }
    File << std::endl;
    for(int i=0 ; i<1000 ; ++i){
        File << quick_sort1[i] << '\t';
    }
    File << std::endl;
    for(int i=0 ; i<1000 ; ++i){
        File << merge_srt[i] << '\t';
    }
    File << std::endl;
    for(int i=0 ; i<1000 ; ++i){
        File << merge_srt1[i] << '\t';
    }
    File << std::endl;
    for(int i=0 ; i<1000 ; ++i){
        File << heap_sort[i] << '\t';
    }
    File << std::endl;
    for(int i=0 ; i<1000 ; ++i){
        File << heap_sort1[i] << '\t';
    }
    File << std::endl;
    File.close();
}



/*
sortowanie selekcją
/**/
void Sorting::selection(){
    int changer_pos;
    int k=0;
    for (auto& raw : this->permutations){
        ++k;
        for (int i=0 ; i<300 ; ++i){
            int changer=0;

            for (int j=i ; j<300 ; ++j){
                int new_one = raw[j];
                this->selection_sort[k]+=1;
                if(changer<new_one){
                    changer = new_one;
                    changer_pos=j;
                }
            }
            this->change_arval(raw,changer_pos,i);
            this->selection_sort1[k]+=1;
        }
    }
    this->permutation();
}


/*
sortowanie wsadowe
/**/
void Sorting::subins(int* arr,int num,int j){
    if(num==0){
        return;
    }
    this->insertion_sort[j]+=1;
    if(arr[num]>arr[num-1]){        
        change_arval(arr,num,num-1);
        this->insertion_sort1[j]+=1;
        subins(arr,num-1,j);
    }
    return;
}
void Sorting::insertion(){
    int j=0;
    for (auto& raw : this->permutations){
        ++j;
        for (int i=1 ; i< 300 ; ++i){
            subins(raw,i,j);
        }
    }
}

/*
sortowanie bąblowe
/**/
void Sorting::bubble(){
    while(true){
    int counter = 1;
    int f=0;
    for (auto& raw : this->permutations){
        ++f;
        for (int i=0 ; i<300-1 ; ++i){
            this->bubble_sort[f]+=1;
            if (raw[i+1]>raw[i]){
                change_arval(raw,i,i+1);
                this->bubble_sort1[f]+=1;
            }
            else {
                ++counter;
            }
            if (counter == 300){
                return;
            }

            }
        }
    }
    this->permutation();
}


/*
sortowanie szybkie
/**/
void Sorting::quick_intra(int *arr, int left, int right,int number){

	if(right <= left) return;
	
	int i = left - 1, j = right + 1, 
	pivot = arr[(left+right)/2];
	
	while(1)
	{
		while(pivot>arr[++i]);
		while(pivot<arr[--j]);
        this->quick_sort[number]+=1;
		if( i <= j){
			change_arval(arr,i,j);
            this->quick_sort1[number]+=1;
        }
		else{
			break;
        }
	}

	if(j > left){   
	quick_intra(arr, left, j,number);
    }
	if(i < right){
	quick_intra(arr, i, right,number);
    }
}
void Sorting::quick(){
    int number=0;
    for (auto& raw : this->permutations){
        ++number;
        this->quick_intra(raw,0,300-1,number);
    }
    this->permutation();
}


/*
sortowanie scalaniem
/**/
void Sorting::merge(int *arr, int low, int high, int mid,int f)
{
    int i, j, k;
    int * c = new int[50];
    std::cout << std::endl; //bez tej linijki pojawia się błąd w mallocu, nie umiem stwierdzić z jakiego powodu.
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            this->merge_srt[f]+=1;
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
    delete [] c;
}
void Sorting::merge_sort(int *arr, int low, int high,int f)
{
    int mid;
    if (low < high){
        mid=(low+high)/2;
        merge_sort(arr,low,mid,f);
        merge_sort(arr,mid+1,high,f);
        this->merge_srt1[f]+=1;
        merge(arr,low,high,mid,f);
    }
}
void Sorting::mrge(){
    int f=0;
    for (auto& raw : this->permutations){
        ++f;
        merge_sort(raw,0,300,f);
    }
    this->permutation();
}


/*
sortowanie kopcowe
/**/
void Sorting::heap_part(int *arr, int n, int i,int f){
    int big = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    this->heap_sort[f]+=1;
    if (l < n && arr[l] > arr[big])
        big = l;
    this->heap_sort[f]+=1;
    if (r < n && arr[r] > arr[big])
        big = r;
    if (big != i) {
        change_arval(arr, i, big);
        this->heap_sort1[f]+=1;
        heap_part(arr, n, big, f);
    }
}
 
void Sorting::heap(){
    int f=0;
    for (auto& raw : this->permutations){
        ++f;
        for (int i = 300 / 2 - 1; i >= 0; i--)
            heap_part(raw, 300, i,f);
        for (int i = 300 - 1; i > 0; i--) {
            change_arval(raw, i, 0);
            heap_part(raw, i, 0,f);
        }
    }
    this->permutation();
}

