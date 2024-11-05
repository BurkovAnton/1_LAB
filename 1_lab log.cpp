////--------------------------------------№1
//#define _crt_secure_no_warnings
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//#include <time.h>
//
//#define size 5 
//
//int main() {
//
//    setlocale(LC_ALL, "Russian");
//
//    int a[size];
//
//    srand(time(NULL));
//
//    for (int i = 0; i < size; i++) {
//        a[i] = rand() % 20 + 1; 
//    }
//    printf("массив: ");
//
//    for (int i = 0; i < size; i++) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//
//    int max = a[0];
//    int min = a[0];
//
//    for (int i = 1; i < size; i++) {
//        if (a[i] > max) {
//            max = a[i];
//        }
//        if (a[i] < min) {
//            min = a[i];
//        }
//    }
//
//    int ras = max - min;
//    printf("разница между макс. и мин.: %d\n", ras);
//
//    return 0;
//}

////------------------------------------------------------№2
//
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//#include <time.h>
//
//#define size 10 
//
//int main() {
//
//    setlocale(LC_ALL, "Russian"); 
//
//    int a[size];
//    srand(time(NULL)); 
//
//    for (int i = 0; i < size; i++) {
//        a[i] = rand() % 100; 
//    }
//
//    printf("Случайные числа массива: ");
//    for (int i = 0; i < size; i++) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//
//    return 0;
//}

////--------------------------------------------№3
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <locale.h>
//#include <stdlib.h>
//
//int main() {
//
//    setlocale(LC_ALL, "Russian");
//
//    int n;
//    printf("Размер массива: ");
//    scanf("%d", &n);
//
//    int* a = (int*)malloc(n * sizeof(int));
//
//    printf("Элементы %d массива: ", n);
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &a[i]);
//    }
//
//    printf("Maccив: ");
//    for (int i = 0; i < n; i++) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//
//    free(a); 
//    return 0;
//}

//-------------------------------------------№4
//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//#include <time.h>
//
//int main() {
//
//    setlocale(LC_ALL, "Russian");
//
//    int r, c;
//
//    printf("Введите количество строк: ");
//    scanf("%d", &r);
//    printf("Введите количество столбцов: ");
//    scanf("%d", &c);
//
//    int** a = (int**)malloc(r * sizeof(int*));
//    for (int i = 0; i < r; i++) {
//        a[i] = (int*)malloc(c * sizeof(int));
//    }
//
//    srand(time(NULL));
//
//    printf("Сгенерированный массив:\n");
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < c; j++) {
//            a[i][j] = rand() % 10 + 1; 
//            printf("%d ", a[i][j]);
//        }
//        printf("\n");
//    }
//
//    printf("Суммы строк:\n");
//    int row_sum;
//    for (int i = 0; i < r; i++) {
//        row_sum = 0;
//        for (int j = 0; j < c; j++) {
//            row_sum += a[i][j];
//        }
//        printf("Сумма строки %d: %d\n", i + 1, row_sum);
//    }
//
//    printf("Суммы столбцов:\n");
//    int col_sum;
//    for (int j = 0; j < c; j++) {
//        col_sum = 0;
//        for (int i = 0; i < r; i++) {
//            col_sum += a[i][j];
//        }
//        printf("Сумма столбца %d: %d\n", j + 1, col_sum);
//    }
//
//    for (int i = 0; i < r; i++) {
//        free(a[i]);
//    }
//    free(a);
//
//    return 0;
//}

//-------------------------------------------№5
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <string.h>

struct student {
    char famil[20];
    char name[20];
    char facult[20];
    int Nomzach;
};

int main() {
    setlocale(LC_ALL, "Russian");

    int searchNomzach;
    char searchFamil[20];
    char searchName[20];

    struct student stud[4] = {
        {"Pichaev", "Ivan", "СС", 12345},
        {"Kochegin", "Valera", "ББ", 54321},
        {"Chuprakov", "Serega", "ВВ", 67890},
        {"Burkov", "Anton", "АА", 54712}
    };

    int choice;
    printf("Выберите способ поиска:\n1. По фамилии и имени\n2. По номеру зачетной книжки\n");
    scanf("%d", &choice);

    int found = 0;

    if (choice == 1) {
        printf("Введите фамилию: ");
        scanf("%s", searchFamil);
        printf("Введите имя: ");
        scanf("%s", searchName);

        for (int i = 0; i < 4; i++) {
            if (strcmp(stud[i].famil, searchFamil) == 0 && strcmp(stud[i].name, searchName) == 0) {
                printf("Студент %s %s, Факультет: %s, ID: %d\n",
                    stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        printf("Введите номер зачетной книжки: ");
        scanf("%d", &searchNomzach);

        for (int i = 0; i < 4; i++) {
            if (stud[i].Nomzach == searchNomzach) {
                printf("Студент %s %s, Факультет: %s, ID: %d\n",
                    stud[i].famil, stud[i].name, stud[i].facult, stud[i].Nomzach);
                found = 1;
                break;
            }
        }
    } else {
        printf("Неверный выбор. Пожалуйста, выберите 1 или 2.\n");
        return 1;
    }

    if (!found) {
        if (choice == 1) {
            printf("Студент с фамилией %s и именем %s не найден.\n", searchFamil, searchName);
        } else {
            printf("Студент с номером зачетной книжки %d не найден.\n", searchNomzach);
        }
    }

    return 0; 
}




