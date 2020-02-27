/*
 * change_return.c
 *
 * A simple program to figure out how many coins in change
 * to return a customer for an amount of cash given.
 *
 * This reflects Canadian currency, so there are no pennies.
 *
 * author: Ryan Morehouse
 * license: MIT
 *
 * Compile:
 * gcc -lm -o change_return.o change.return.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void error_msg() {
  printf("Usage: ./change_return.o [cost] [pay]\n");
  printf("[cost] is the cost of the purchase.\n");
  printf("[pay] is the amount paid b the customer.\n");
  printf("Do not use $ signs in the currency amount - use only numerical inputs.\n");
   1;
}

int main(int argc, char* argv[]) {
  // verify args exist
  if(argc < 3) {
    error_msg();
    return 1;
  }

  // verify args are positive
  float raw_cost = atof(argv[1]);
  float raw_pay = atof(argv[2]);
  if(raw_cost <= 0 || raw_pay <= 0) {
    error_msg();
    return 1;
  }

  // verify payment is greater than cost
  if(raw_pay < raw_cost) {
    printf("The payment is insufficient.\n");
    return 0;
  }

  float raw_change = raw_pay - raw_cost;

  // get natural currency values
  float f_dollars = floor(raw_change);
  float f_cents = raw_change - f_dollars;
  f_cents *= 100;
  f_cents = floor(f_cents);

  int change_dollars = (int)(f_dollars);
  int change_cents = (int)(f_cents);


  int coins = change_cents;
  int quarters = coins / 25;
  coins = coins % 25;
  int dimes = coins / 10;
  coins = coins % 10;
  int nickels = coins / 5;
  coins = coins % 5;
  // no pennies in Canada, round change to nickels
  if(coins > 2)
    nickels += 1;

  printf("Total Change Due: $%d.%d\n", change_dollars, change_cents);
  printf("Dollars: %d\n", change_dollars);
  printf("Quarters: %d\n", quarters);
  printf("Dimes: %d\n", dimes);
  printf("Nickels: %d\n", nickels);




  return 0;
}

