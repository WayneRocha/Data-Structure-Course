#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// Função que recebe um parâmetro por valor
void passByValue(int x) {
    x = x * 2;
    std::cout << "Dentro da função passByValue: " << x << std::endl;
}

// Função que recebe um parâmetro por referência
void passByReference(int &y) {
    y = y * 2;
    std::cout << "Dentro da função passByReference: " << y << std::endl;
}

int main_hello_world()
{
    std::cout << "Hello World" << std::endl;
    return 0;
}

int main_math_operations()
{
    float o1;
    float o2;

    std::cout << std::endl << "1º operando: ";
    std::cin >> o1;
    std::cout << std::endl << "2º operando: ";
    std::cin >> o2;

    std::cout << o1 << " mais " << o2 <<  " = " << o1 + o2 << std::endl;
    std::cout << o1 << " menos " << o2 <<  " = " << o1 - o2 << std::endl;
    std::cout << o1 << " vezes " << o2 <<  " = " << o1 * o2 << std::endl;
    std::cout << o1 << " divido por " << o2 <<  " = " << o1 / o2 << std::endl;
    std::cout << "Resto da dívisão (módulo) de " << o1 << " divido por " << o2 <<  " = " << ((int)o1 % (int)o2) << std::endl;

    return 0;
}

int main_condicional_operations()
{
    char answer;

    std::cout << std::endl << "Gosta de estrutura de dados? [S/n]: ";
    std:cin >> answer;

    if (tolower(answer) == 's'){
        std::cout << std::endl << "Que bom! Continue estudando :)";
    } else if (tolower(answer) == 'n') {
        std::cout << std::endl << "Mas é importante, então vá estudar";
    } else {
        std::cout << std::endl << "Que resposta é essa??? Bom não vou ficar REPETINDO até você dizer o que quero ouvir... Adeus";
    }

    return 0;
}

int main_repetition()
{
    char answer;

    while (tolower(answer) != 's' && tolower(answer) != 'n') {
        std::cout << std::endl << "Você gosta de estrutura de dados? [S/n]: ";
        std:cin >> answer;

        if (tolower(answer) == 's'){
            std::cout << std::endl << "Que bom! Continue estudando :)";
        } else if (tolower(answer) == 'n') {
            std::cout << std::endl << "Mas é importante, então vá estudar";
        } else {
            std::cout << std::endl;
            
            for (size_t i = 0; i < 3; i++)
            {
                std::cout << ". ";
                std::chrono::seconds sleepDuration(1);
                std::this_thread::sleep_for(sleepDuration);
            }
            
            std::cout << std::endl << "Que tipo de resposta é essa??? responde direito!";
            std::chrono::seconds sleepDuration(2);
            std::this_thread::sleep_for(sleepDuration);
        }
    }

    return 0;
}

int main_pass_by_value_and_reference()
{
    // Exemplo de passagem por valor
    int a = 5;
    std::cout << "Antes da chamada da função passByValue: " << a << std::endl;
    passByValue(a);
    std::cout << "Depois da chamada da função passByValue: " << a << std::endl;

    std::cout << std::endl;

    // Exemplo de passagem por referência
    int b = 5;
    std::cout << "Antes da chamada da função passByReference: " << b << std::endl;
    passByReference(b);
    std::cout << "Depois da chamada da função passByReference: " << b << std::endl;

    return 0;
}

int main_pointers()
{

    // Declaração de uma variável inteira
    int variavelInteira = 42;

    // Declaração de um ponteiro para inteiro
    int *ponteiroInteiro;

    // Inicialização do ponteiro com o endereço da variável
    ponteiroInteiro = &variavelInteira;

    // Imprime o valor da variável usando o ponteiro
    std::cout << "Valor usando ponteiro: " << *ponteiroInteiro << std::endl;

    // Alocação estática de um array
    int arrayEstatico[5] = {1, 2, 3, 4, 5};

    // Imprime os valores do array
    std::cout << "Valores do array estático: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << arrayEstatico[i] << " ";
    }
    std::cout << std::endl;

    // Alocação dinâmica de um array
    int tamanhoArrayDinamico = 3;
    int *arrayDinamico = new int[tamanhoArrayDinamico];

    // Inicializa valores no array dinâmico
    for (int i = 0; i < tamanhoArrayDinamico; ++i) {
        arrayDinamico[i] = i * 10;
    }

    // Imprime os valores do array dinâmico
    std::cout << "Valores do array dinâmico: ";
    for (int i = 0; i < tamanhoArrayDinamico; ++i) {
        std::cout << arrayDinamico[i] << " ";
    }
    std::cout << std::endl;

    // Libera a memória alocada dinamicamente
    delete[] arrayDinamico;

    return 0;
}

int main()
{
    char program;
    
    try
    {

        std::cout << "********PROGRAMAS********"  << std::endl;
        std::cout << "1 - Hello World"  << std::endl;
        std::cout << "2 - Operações Mátemáticas"  << std::endl;
        std::cout << "3 - Operações Condícionais"  << std::endl;
        std::cout << "4 - Repetição"  << std::endl;
        std::cout << "5 - Parâmetro por valor e referência"  << std::endl;
        std::cout << "6 - Ponteiros"  << std::endl;
        std::cout << "Qual programa execultar? [1-6]: ";
        std::cin >> program;

        if (program == '1') {
            return main_hello_world();
        } else if (program == '2') {
            return main_math_operations();
        } else if (program == '3') {
            return main_condicional_operations();
        } else if (program == '4') {
            return main_repetition();
        } else if (program == '5') {
            return main_pass_by_value_and_reference();
        } else if (program == '6') {
            return main_pointers();
        } else {
            return 0;
        }
    }
    catch(const std::exception& e)
    {
        std::cout << "The Program Failed"  << std::endl;
        std::cerr << e.what() << '\n';
        return 1;
    }
    

    return 0;
}
