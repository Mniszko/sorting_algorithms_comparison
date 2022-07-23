#ifndef OTHER_
#define OTHER_
#include <iostream>
#include <random>
#include <fstream>


//[1] odnosi się do zliczeń dostępów, [2] do zliczeń zamian, wszystko zapisywane jest w "can.txt" w tej formule według kolejności w której deklarowane są sortowania
class Sorting{
    private:
        int temp[300];
        int permutations[1000][300];
        int *selection_sort; 
        int *insertion_sort;
        int *bubble_sort;
        int *quick_sort;
        int *merge_srt;
        int *heap_sort;
        int *selection_sort1; 
        int *insertion_sort1;
        int *bubble_sort1;
        int *quick_sort1;
        int *merge_srt1;
        int *heap_sort1;

        void change_val(int*, int*);
        void change_arval(int*,int,int);
        void subins(int*,int,int);
        void quick_intra(int*,int,int,int);
        void merge(int*, int, int, int,int);
        void merge_sort(int*, int, int,int);
        void heap_part(int*, int, int,int);
        //funkcje wyżej są wykorzystywane obok właściwych, ich definicje znajdują się obok funkcji właściwych sortowań dla czytelności
    public:
        Sorting();
        ~Sorting(){};
        void permutation();
        void selection();
        void insertion();
        void bubble();
        void quick();
        void mrge();
        void heap();
        void write_down();
        //funkcje właściwe
};






#endif