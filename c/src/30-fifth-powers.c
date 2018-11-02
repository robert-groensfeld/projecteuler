#include <stdio.h>
#include <math.h>

int get_digit_count(int number);
int get_fifth_power_of_digits_sum(int number, int digit_count);
int get_digit(int number, int digit_count, int digit_index);

int main(int argc, char* argv[]) {
    printf("Numbers that can be written as the sum\n");
    printf("of fifth powers of their digits: \n\n");

    int number = 1;
    int min_value;
    int max_sum;
    int sum_of_found_numbers = 0;

    do {
        number = number + 1;
        int digit_count = get_digit_count(number);

        // Minimal value of a number with the current digit count.
        min_value = pow(10, digit_count - 1);

        // Maximal value of the sum of fifth powers of the current digits.
        max_sum = digit_count * pow(9, 5);

        int digit_sum = get_fifth_power_of_digits_sum(number, digit_count);

        if (digit_sum == number) {
            printf("%d\n", number);
            sum_of_found_numbers = sum_of_found_numbers + number;
        }

    } while (max_sum >= min_value);

    printf("\nSum: %d\n", sum_of_found_numbers);

    return 0;
}

int get_digit_count(int number) {
    if (number < 10)
        return 1;
    else
        return 1 + get_digit_count(number / 10);
}

int get_fifth_power_of_digits_sum(int number, int digit_count) {
    int i;
    int sum = 0;
    for (i = 0; i < digit_count; ++i) {
        int digit = get_digit(number, digit_count, i);
        sum = sum + pow(digit, 5);
    }
    return sum;
}

int get_digit(int number, int digit_count, int digit_index) {
    // Remove following digits.
    int digit = number / pow(10, (digit_count - 1) - digit_index);
    // Remove preceding digits.
    return digit % 10;
}