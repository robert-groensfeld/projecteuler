#include <stdio.h>
#include <stdlib.h>

enum Coin {
	ONE_PENCE = 1,
	TWO_PENCE = 2,
	FIVE_PENCE = 5,
	TEN_PENCE = 10,
	TWENTY_PENCE = 20,
	FIFTY_PENCE = 50,
	ONE_POUND = 100,
	TWO_POUNDS = 200,
};

void print_usage();
int ways_to_pay(int amount);
enum Coin next_lower_coin(enum Coin c);
int ways_to_pay_with_coins_up_to(int amount, enum Coin max_coin);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		print_usage();
	} else {
		int amount = atoi(argv[1]);
		int ways = ways_to_pay(amount);
		printf("There are %d ways to pay %d ", ways, amount);
		printf("pence with British coins.\n");
	}
	
	return 0;
}

void print_usage() {
	printf("Type \"coins AMOUNT\" to get the possibilities to\n");
	printf("pay an amount of AMOUNT pence with British coins.\n");
}

int ways_to_pay(int amount) {
	return ways_to_pay_with_coins_up_to(amount, TWO_POUNDS);
}

int ways_to_pay_with_coins_up_to(int amount, enum Coin max_coin) {
	if (max_coin == ONE_PENCE)
		return 1;

	enum Coin next = next_lower_coin(max_coin);

	if (amount < max_coin) {
		return ways_to_pay_with_coins_up_to(amount, next);
	} else if (amount == max_coin) {
		return 1 + ways_to_pay_with_coins_up_to(amount, next);
	} else if (amount > max_coin) {
		int rest = amount - max_coin;
		int ways_rest = ways_to_pay_with_coins_up_to(rest, max_coin);
		int ways_lower = ways_to_pay_with_coins_up_to(amount, next);
		return ways_rest + ways_lower;
	}
}

enum Coin next_lower_coin(enum Coin c) {
	switch (c) {
		case TWO_POUNDS: return ONE_POUND;
		case ONE_POUND: return FIFTY_PENCE;
		case FIFTY_PENCE: return TWENTY_PENCE;
		case TWENTY_PENCE: return TEN_PENCE;
		case TEN_PENCE: return FIVE_PENCE;
		case FIVE_PENCE: return TWO_PENCE;
		case TWO_PENCE: return ONE_PENCE;
		case ONE_PENCE:
			fprintf(stderr, "No lower coin than one pence.\nAborting...\n");
			exit(EXIT_FAILURE);
		default: 
			fprintf(stderr, "Invalid value for British ");
			fprintf(stderr, "coin: %d\nAborting...\n", c);
			exit(EXIT_FAILURE);
	}
}
