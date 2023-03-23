#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// #include "print_module.h"

// int print_char(char ch)
// {
//     return putchar(ch);
// }

// /*
//     input:  printchar-callback, log message
//     output: void
//     result: "Log_prefix HH:MM:SS message"
// */
// void print_log(char (*print) (char), char* message);

// Печатаем текущую дату и время в C
int main(void) {
    // переменные для хранения компонентов даты и времени
    int hours, minutes, seconds;

    // `time_t` - арифметический тип времени
    time_t now;

    // Получить текущее время
    // `time()` возвращает текущее время системы как значение `time_t`
    time(&now);

    // Преобразование в местный формат времени и вывод на стандартный вывод
    // printf("Today is %s", ctime(&now));

    // localtime преобразует значение `time_t` в календарное время и
    // возвращает указатель на структуру `tm` с ее членами
    // заполняется соответствующими значениями
    struct tm *local = localtime(&now);

    hours = local->tm_hour;   // получаем часы с полуночи (0-23)
    minutes = local->tm_min;  // получить минуты, прошедшие после часа (0-59)
    seconds = local->tm_sec;  // получаем секунды, прошедшие через минуту (0-59)

    // печатаем местное время
    if (hours) {  // до полудня
        printf("%02d:%02d:%02d am\n", hours, minutes, seconds);
    }
    // else {    // после полудня
    //     printf("%02d:%02d:%02d pm\n", hours - 12, minutes, seconds);
    // }

    return 0;
}