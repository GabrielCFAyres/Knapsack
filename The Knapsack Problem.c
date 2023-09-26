#include <stdio.h>

// Criando a função max para usarmos no momento da rodagem da função Knapsack, logo em seguida no código
int max(int first_number, int second_number) {
    return (first_number >= second_number) ? first_number : second_number;
}

int Knapsack(int number_items, int total_weight, int weight_item[], int matrix_values[], int complete_matrix[number_items + 1][total_weight + 1]) {
    for (int i = 0; i <= number_items; i++) {
        for (int j = 0; j <= total_weight; j++) {
            if (i == 0 || j == 0) {
                complete_matrix[i][j] = 0;
            } else if (weight_item[i - 1] <= j) {
                complete_matrix[i][j] = max(complete_matrix[i - 1][j], matrix_values[i - 1] + complete_matrix[i - 1][j - weight_item[i - 1]]);
            } else {
                complete_matrix[i][j] = complete_matrix[i - 1][j];
            }
        }
    }
    return complete_matrix[number_items][total_weight];
}

int main(void) {
    // Declarando as variáveis que nos serão dadas para que possamos, em breve, alocar valores de acordo com o input dado
    int capacity;
    int number_items;

    // Armazenando os valores dados em cada variável
    scanf("%d %d", &capacity, &number_items);

    // Declarando os arrays com os pesos de cada item, bem como com a quantidade de itens.
    int item_mass[number_items];
    int item_value[number_items];

    // Preenchendo os arrays de acordo com os inputs
    for (int n = 0; n < number_items; n++) {
        scanf("%d %d", &item_mass[n], &item_value[n]);
    }

    // Criando a matriz para armazenar os valores
    int filled_matrix[number_items + 1][capacity + 1];

    // Preenchendo a matriz para que possamos identificar o valor que nos é aguardado no programa.
    int melhor_escolha = Knapsack(number_items, capacity, item_mass, item_value, filled_matrix);

    // Imprimindo o resultado esperado na questão
    printf("%d\n", melhor_escolha);

    return 0;
}
