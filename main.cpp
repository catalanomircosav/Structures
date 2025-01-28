#include "Array/Lista.h"
using namespace array;

int main(int argc, char** argv) {
    Lista<int> lista;

    lista.InsLista(10, 1);
    lista.InsLista(20, 2);
    lista.InsLista(30, 3);
    lista.InsLista(40, 4);
    
    std::cout << "La lista prima della cancellazione:\n";
    lista.StampaLista();

    std::cout << "La lista dopo aver cancellato un elemento:\n";    
    lista.CancLista(2);
    lista.StampaLista();

    system("pause");
    return 0;
}