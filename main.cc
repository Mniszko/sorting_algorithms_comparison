#include "./other.h"

int main(){
    srand(time(NULL));

    Sorting new_sort;
    new_sort.insertion();
    new_sort.selection();
    new_sort.bubble();
    new_sort.quick();
    new_sort.mrge();
    new_sort.heap();
    std::cout << "k8" << std::endl;

    new_sort.write_down();
    return 0;
}

/*
kod czasem po skompilowaniu nie działa (błąd w segmentowaniu), ale zdarza się to nieczęsto, powtarzając włączanie programu błąd w pewnym momencie ustępuje

nie znalazłem rozwiązania tego problemu (występuje po otwarciu pliku can.txt), ale w celu generowania histogramu nie ma on znaczenia

generowaniem histogramu zajmuje się "histogram.m", "can.txt" jest tylko plikiem pośredniczącym między octave i a.out
/**/