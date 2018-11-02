#include <digits.h>

int main(int argc, char* argv[]) {
    unsigned int limit = 1000000;
    printf("Numbers under %u that are palindromic in base 2 and base 10:\n", limit);

    unsigned int sum = 0;
    for (unsigned int i = 1; i < limit; ++i)
        if (isPalindrome((int) i) && isBase2Palindrome(i)) {
            printf("%u ", i);
            sum += i;
        }

    printf("\nSum of all palindromic numbers: %u", sum);
    return 0;
}