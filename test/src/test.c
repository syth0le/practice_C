/*
 ============================================================================
 Name        : test.c
 Author      : sythole
 Version     :
 Copyright   : my and only my
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>

#include <locale.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct element
{
    char *task;
    struct element *next;
};

typedef struct element LIST;

void freeList(struct element* head);
void convert_vector_to_str_vector(int size, int *vector_1, int *vector_2, float *vector_result, char *vector_1_str, char *vector_2_str, char *vector_result_str);
//void add_to_list(LIST *head, LIST *current, char *line);

void freeList(LIST *head)
{
    LIST *tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }

}

void add_to_list(LIST *head, LIST *current, char *line)
{
    LIST *node = malloc(sizeof(LIST));
    node->task = strdup(line); //note : strdup is not standard function
    node->next = NULL;

    if (head == NULL)
    {
        current = head = node;
    }
    else
    {
        current = current->next = node;
    }
}


void convert_vector_to_str_vector(int size, int *vector_1, int *vector_2, float *vector_result, char *vector_1_str, char *vector_2_str, char *vector_result_str)
{
    // выводим результат
    int cur_pos=0;
    int i=0;
    memset(vector_1_str, 0, 255);
    memset(vector_2_str, 0, 255);
    memset(vector_result_str, 0, 255);
    // пишем значения 1 вектора через пробел

    for (i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            cur_pos += sprintf(&vector_1_str[cur_pos], "%d ", vector_1[i]);
        }
        else
        {
            cur_pos += sprintf(&vector_1_str[cur_pos], "%d", vector_1[i]);
        }
    }
    cur_pos=0;

    for (i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            cur_pos += sprintf(&vector_2_str[cur_pos], "%d ", vector_2[i]);
        }
        else
        {
            cur_pos += sprintf(&vector_2_str[cur_pos], "%d", vector_2[i]);
        }
    }

    cur_pos=0;


    for (i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            cur_pos += sprintf(&vector_result_str[cur_pos], "%.2f ", vector_result[i]);
        }
        else
        {
            cur_pos += sprintf(&vector_result_str[cur_pos], "%.2f)", vector_result[i]);
        }
    }
    printf("\n");
}


int main(void)
{
    char line[128];
    LIST *in_current, *in_head;
    LIST *out_current, *out_head;
    char operation_type = 0; // в эту переменную сохранится тип операции.
    char data_type = 0; // в эту переменную сохраним какой тип данных содержится в файле после того как его прочитаем
    int i = 0; // переменная, которую будем использовать как счетчик, для операций
    // начинаем работать с файлами
    // сначала нужно объявить файловые дескрипторы для входного и выходного файла. Файловый дескриптор - это просто число, по которому система находит файл и может из него читать или писать в него
    FILE *in_file;
    FILE *out_file; // дескриптор выходного файла (куда запишем результат)

    setlocale(LC_ALL, "Russian"); // включаем поддержку русских букв в консоли, т.к. консолью будем пользоваться для вывода всяких полезных сообщений

    in_head = in_current = NULL;
    out_head = out_current = NULL;
    in_file = fopen("input.txt", "r");
    out_file = fopen("output.txt", "w");
    memset(line, 0, sizeof(line));

    while (fgets(line, sizeof(line), in_file))
    {
        //add_to_list(in_head, in_current, line);

        LIST *in_node = malloc(sizeof(LIST));
        in_node->task = strdup(line); //note : strdup is not standard function
        in_node->next = NULL;

        if (in_head == NULL)
        {
            in_current = in_head = in_node;
        }
        else
        {
            in_current = in_current->next = in_node;
        }

    }
    fclose(in_file);

    for (in_current = in_head; in_current; in_current = in_current->next)
    {
        printf("Current task: %s\n", in_current->task);
        LIST *out_node = malloc(sizeof(LIST));

        sscanf(in_current->task, "%c %c", &operation_type, &data_type);

        printf("operation_type= %c\n", operation_type);
        printf("data_type= %c\n", data_type);

        switch (data_type)
            // теперь смотрим, какой же у нас тип данных в файле, который мы вычитали
        {
            case 's': // значит у нас обычные числа в файле
            {
                int number_1; // теперь говорим, что в нашей программе будет использоваться переменная number_1 типа int (integer, т.е. целое число. Целое число это 1,2,3,4,5..N)
                int number_2; // в нашей программе будет переменная number_2
                float result; // в эту переменную сохраним результат операции. Она типа float - десятичное ну или дробное число, например "2.342"

                sscanf(&in_current->task[0] + 4, "%d %d", &number_1, &number_2);

                switch (operation_type)
                {
                    case '+':
                        result = number_1 + number_2; // складываем два числа и пишем в переменную result
                        // функция fprintf работает точно так же как функция printf, только выводит результат не в консоль, а в файл, поэтому в нее нужно передать дескриптор на файл, куда хотим записать информацию
                        memset(line, 0, sizeof(line));
                        sprintf(line, "результат: %d + %d = %f \n", number_1, number_2,
                                result);
                        //add_to_list(out_head, out_current, line);
                        out_node->task = strdup(line); //note : strdup is not standard function
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }
                        break;
                    case '-':
                        result = number_1 - number_2;
                        memset(line, 0, sizeof(line));
                        sprintf(line, "результат: %d - %d = %f \n", number_1, number_2,
                                result);
                        //add_to_list(out_head, out_current, line);
                        out_node->task = strdup(line); //note : strdup is not standard function
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    case '*':
                        result = number_1 * number_2;
                        memset(line, 0, sizeof(line));
                        sprintf(line, "результат: %d * %d = %f \n", number_1, number_2,
                                result);
                        //add_to_list(out_head, out_current, line);
                        out_node->task = strdup(line); //note : strdup is not standard function
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    case '/':
                        result = number_1 / number_2;
                        memset(line, 0, sizeof(line));
                        sprintf(line, "результат: %d / %d = %f \n", number_1, number_2,
                                result);
                        //add_to_list(out_head, out_current, line);
                        out_node->task = strdup(line); //note : strdup is not standard function
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    case '^':
                        result = 1; // нужно задать значение result, чтобы не испортить первый шаг цикла

                        for (i = 0; i < number_2; i++)
                        {
                            result = result * number_1;
                        }
                        memset(line, 0, sizeof(line));
                        sprintf(line, "результат: %d ^ %d = %f \n", number_1, number_2,
                                result);
                        //add_to_list(out_head, out_current, line);
                        out_node->task = strdup(line); //note : strdup is not standard function
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }
                        break;
                    case '!':
                        if (number_1 == 0) // если number == 0, то факториал считать не нужно, ответ 1
                        {
                            result = 1;
                        }
                        else // если number != 0
                        {
                            result = 1;
                            for (i = 1; i <= number_1; i++)
                            {
                                result = result * i;
                            }
                        }
                        memset(line, 0, sizeof(line));
                        sprintf(line, "результат: %d! = %f \n", number_1, result);
                        //add_to_list(out_head, out_current, line);
                        out_node->task = strdup(line); //note : strdup is not standard function
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    default:
                        puts(
                                "Ошибка - введен недопустимый символ операции. Исправте файл и попробуйте снова");
                        break;
                }
                break; // break относится к "case 's':", т.е. выходим из него
            }
            case 'v': // значит у нас векторы в файле
            {
                int *vector_1; // указатель на первый вектор. В этой переменной хранится адрес начала массива
                int *vector_2;// указатель на второй вектор. В этой переменной хранится адрес начала массива
                float *vector_result;// указатель на вектор, содержащий результат. В этой переменной хранится адрес начала массива
                char *vector_1_str; // указатель на первый вектор. В этой переменной хранится адрес начала массива
                char *vector_2_str;// указатель на второй вектор. В этой переменной хранится адрес начала массива
                char *vector_result_str;// указатель на вектор, содержащий результат. В этой переменной хранится адрес начала массива
                int size = 0;// размер всех векторов. Прочитаем его из файла

                sscanf(&in_current->task[0] + 4, "%d", &size);

                // выделяем память под векторы
                vector_1 = calloc(size, sizeof(int));// функция calloc выделяет память для вектора. size - количество элементов, sizeof(int) - размер одного элемента
                vector_2 = calloc(size, sizeof(int));// функция calloc выделяет память для вектора. size - количество элементов, sizeof(int) - размер одного элемента
                vector_result = calloc(size, sizeof(float));// функция calloc выделяет память для вектора. size - количество элементов, sizeof(int) - размер одного элемента
                vector_1_str = calloc(255, sizeof(char));// функция calloc выделяет память для вектора. size - количество элементов, sizeof(int) - размер одного элемента
                vector_2_str = calloc(255, sizeof(char));// функция calloc выделяет память для вектора. size - количество элементов, sizeof(int) - размер одного элемента
                vector_result_str = calloc(255, sizeof(char));// функция calloc выделяет память для вектора. size - количество элементов, sizeof(int) - размер одного элемента

                // читаем значения 1 вектора из файла
                for (i = 0; i < size; i++)
                {
                    sscanf(&in_current->task[0] + 6, "%d ", &vector_1[i]);
                }

                for (i = 0; i < size; i++)
                {
                    printf("vector_1[%d] = %d ", i, vector_1[i]);
                }
                printf("\n");

                // читаем значения 2 вектора из файла
                for (i = 0; i < size; i++)
                {
                    sscanf(&in_current->task[0] + 6+size+1, "%d ", &vector_2[i]);
                }

                for (i = 0; i < size; i++)
                {
                    printf("vector_2[%d] = %d ", i, vector_2[i]);
                }
                printf("\n");

                // оператор switch сравнивает значение внутри (operation_type) с каждым из case. И если оно совпало, то идет в эту ветку
                switch (operation_type)
                {
                    case '+':
                        // выполняем сложее векторов
                        for (i = 0; i < size; i++)
                        {
                            vector_result[i] = vector_1[i] + vector_2[i];
                        }

                        convert_vector_to_str_vector(size,vector_1,vector_2,vector_result,vector_1_str,vector_2_str,vector_result_str);

                        memset(line, 0, sizeof(line));
                        sprintf(line, "(%s) + (%s) = (%s) \n", vector_1_str, vector_2_str, vector_result_str);
                        //add_to_list(out_head, out_current, line);
                        LIST *out_node = malloc(sizeof(LIST));
                        out_node->task = strdup(line); //stdrdup функция создающая копию (нестандартная функция)
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    case '-':
                        // выполняем вычитание векторов
                        for (i = 0; i < size; i++)
                        {
                            vector_result[i] = vector_1[i] - vector_2[i]; // складываем два числа и пишем в переменную result
                        }

                        convert_vector_to_str_vector(size,vector_1,vector_2,vector_result,vector_1_str,vector_2_str,vector_result_str);

                        memset(line, 0, sizeof(line));
                        sprintf(line, "(%s) + (%s) = (%s) \n", vector_1_str, vector_2_str, vector_result_str);
                        out_node->task = strdup(line); //stdrdup функция создающая копию (нестандартная функция)
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    case '*':
                        // выполняем умножение векторов
                        for (i = 0; i < size; i++)
                        {
                            vector_result[i] = vector_1[i] * vector_2[i];
                        }

                        convert_vector_to_str_vector(size,vector_1,vector_2,vector_result,vector_1_str,vector_2_str,vector_result_str);

                        memset(line, 0, sizeof(line));
                        sprintf(line, "(%s) + (%s) = (%s) \n", vector_1_str, vector_2_str, vector_result_str);
                        //add_to_list(out_head, out_current, line);
                        out_node->task = strdup(line); //stdrdup функция создающая копию (нестандартная функция)
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    case '/':
                        // выполняем деление векторов
                        for (i = 0; i < size; i++)
                        {
                            vector_result[i] = vector_1[i] / vector_2[i]; // складываем два числа и пишем в переменную result
                        }

                        convert_vector_to_str_vector(size,vector_1,vector_2,vector_result,vector_1_str,vector_2_str,vector_result_str);

                        memset(line, 0, sizeof(line));
                        sprintf(line, "(%s) + (%s) = (%s) \n", vector_1_str, vector_2_str, vector_result_str);
                        //add_to_list(out_head, out_current, line);
                        out_node->task = strdup(line); //stdrdup функция создающая копию (нестандартная функция)
                        out_node->next = NULL;

                        if (out_head == NULL)
                        {
                            out_current = out_head = out_node;
                        }
                        else
                        {
                            out_current = out_current->next = out_node;
                        }

                        break;
                    default:
                        puts(
                                "Ошибка - введен недопустимый символ операции. Исправте файл и попробуйте снова");
                        break;
                }
                // free - освобождает память, которую выделили, используя calloc
                free(vector_1);
                free(vector_2);
                free(vector_result);
                free(vector_1_str);
                free(vector_2_str);
                free(vector_result_str);

                break; // break относится к "case 'v':"
            }
            default:
                puts("Ошибка - неправильно введен тип данных в файле");
                break;
        }

    }

    for (out_current = out_head; out_current; out_current = out_current->next)
    {
        fprintf(out_file, "%s", out_current->task); // пишем значение с пробелом в конце. %.2f означает, что нужно записать тип float, но только 2 знакак после '.'
    }
    fclose(out_file);
    freeList(in_head);
    freeList(out_head);
    return 0;
}
