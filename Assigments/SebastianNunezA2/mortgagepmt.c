/* NAME: Sebastian Nunez
 * STUDENT ID: 6358289
 * CLASS: COP4338 (Assignment 2)
 * DATE: 09/18/22
 *
 * AFFIRMATION OF ORIGINALITY:
 * I affirm that I wrote this program myself
 * without any help from any other people or
 * sources from the internet.
 *
 * PROGRAM DESCRIPTION:
 * This program will calculate the monthly payments of a morgage.
 * Using commandline arguments, the program will calculate the monthly payment
 * based on:
 * 1. Loan amount ($USD)
 * 2. Anual Interest rate (%)
 * 3. Loan term (years)
 * 4. Downpayment ($USD)
 * 5. PMI ($USD)
 */
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// global constants
const double PMI_RATE = 0.01;              // PMI amount to be added (decimal)
const double MIN_DOWNPAYMENT_RATE = 0.20;  // minimum downpayment rate (decimal) needed to not have a PMI added
const short SHORT_LOAN_TERM = 15;          // short term loan
const short LONG_LOAN_TERM = 30;           // long term loan
const double MIN_INTEREST_RATE = 0.03;     // mim interest rate
const double MAX_INTEREST_RATE = 0.10;     // max interest rate

// function prototypes
double calculatePMI(double price, double downpayment);
bool isValidRate(double rate);
bool isValidDownpayment(double price, double downpayment);
double calculateMonthlyPayment(double price, double rate, short loanTerm, double downpayment, double pmi);

/**
 * Usage: mortgagepmt [-s] -r rate [-d downpayment] price
 *
 * Main Entry to our program:
 * 1. Parses the commandline arguments
 * 2. Validates the arguments
 * 3. Passes on the arguments in order to calculate the monthly payments
 *
 * Monthly payment output format:
 * The payment on a loan of $###,###.## with an interest rate of #.###% for a
 * term of ## years will be $##,###.##
 */
int main(int argc, char* argv[]) {
  extern char* optarg;
  extern int optind;
  int c, err = 0;

  int sflag = 0, rflag = 0, dflag = 0;
  char *rateArg, *downpaymentArg = "0";  // 0 is the default downpayment
  static char usage[] = "usage: %s [-s] -r rate [-d downpayment] price\n";

  // "sr:d:" are the allowed flags. ':' -> previous flag takes an argument
  while ((c = getopt(argc, argv, "sr:d:")) != -1) {
    switch (c) {
      case 's':
        sflag = 1;
        break;
      case 'r':
        rflag = 1;
        rateArg = optarg;
        break;
      case 'd':
        dflag = 1;
        downpaymentArg = optarg;
        break;
      case '?':
        err = 1;
        break;
    }
  }

  if (rflag == 0) {  // -r was mandatory
    fprintf(stderr, "%s: missing -r option\n", argv[0]);
    fprintf(stderr, usage, argv[0]);
    exit(1);
  } else if ((optind + 1) > argc) {
    // need at least 1 argument (price)
    printf("optind = %d, argc=%d\n", optind, argc);
    fprintf(stderr, "%s: missing price\n", argv[0]);
    fprintf(stderr, usage, argv[0]);
    exit(1);
  } else if (err) {
    fprintf(stderr, usage, argv[0]);
    exit(1);
  }

  // see what we have
  // printf("sflag = %d\n", sflag);
  // printf("rflag = %d\n", rflag);
  // printf("dflag = %d\n", dflag);
  // printf("rate = \"%s\"\n", rateArg);
  // printf("downpayment = \"%s\"\n", downpaymentArg);

  // these are the arguments after the command-line options
  // if (optind < argc) {
  //   for (; optind < argc; optind++)
  //     printf("argument: \"%s\"\n", argv[optind]);
  // } else {
  //   printf("no arguments left to process\n");
  // }

  // variables (using values from the cmd line)
  short loanTerm = (sflag) ? SHORT_LOAN_TERM : LONG_LOAN_TERM;  // loan term (years) -> sflag indicates SHORT_LOAN_TERM
  double rate = strtod(rateArg, NULL) / 100;                    // interest rate (decimal)
  double downpayment = strtod(downpaymentArg, NULL);            // downpaymnet ($USD)
  double price = strtod(argv[optind], NULL);                    // first argument after the flags should be the price
  double pmi = calculatePMI(price, downpayment);                // private morgage insurance
  double monthlyPayment = -1;                                   // initial monthly payment (-1 indicates error)

  // printf("loan term: %hd\n", loanTerm);
  // printf("rate: %lf\n", rate);
  // printf("downpayment: %f\n", downpayment);
  // printf("price: %lf\n", price);
  // printf("pmi: %lf\n", pmi);

  // validate rate
  if (!isValidRate(rate)) {
    printf("Interest rate should be between %.3lf%% and %.3lf%%\n", MIN_INTEREST_RATE * 100.0,
           MAX_INTEREST_RATE * 100.0);
    exit(1);
  }

  // validate downpayment
  if (!isValidDownpayment(price, downpayment)) {
    printf("The downpayment can't exceed the price of the home and it must be at least zero!\n");
    exit(1);
  }

  // determine monthly payment
  monthlyPayment = calculateMonthlyPayment(price, rate, loanTerm, downpayment, pmi);

  // final output
  char* outputFormat =
      "The payment on a loan of $%.2lf with an interest rate of %.3lf%% for a term of %hd years will be $%.2lf";
  printf(outputFormat, price, rate * 100, loanTerm, monthlyPayment);

  exit(0);
}

/**
 * Calculates the PMI amount of a loan. PMI is added if:
 * - The down payment is less than 20% of the price of the home
 *
 * NOTE: PMI is based on (price / 12) * PMI_RATE
 */
double calculatePMI(double price, double downpayment) {
  double minDownpayment = price * MIN_DOWNPAYMENT_RATE;  // minimum downpayment based on MIN_DOWNPAYMENT_RATE
  // printf("min downpayment: %lf\n", minDownpayment);

  if (downpayment < minDownpayment) {
    return (price / 12.0) * PMI_RATE;
  }

  return 0.0;
}

/**
 * Determines if the interest rate valid. Criteria:
 * - Interest rate: should be between MIN_INTEREST_RATE and MAX_INTEREST_RATE
 *
 * Parameters:
 * - Rate: double signifiying the interest rate as a decimal (not %)
 */
bool isValidRate(double rate) {
  return rate >= MIN_INTEREST_RATE && rate <= MAX_INTEREST_RATE;
}

/**
 * Determines if the downpayment is valid. Criteria:
 * - the downpayment must be smaller than the price of the home (and greater than or equal to zero)
 */
bool isValidDownpayment(double price, double downpayment) {
  return downpayment >= 0 && downpayment <= price;
}

/**
 * Determines the monthly payment using the following algorithm:
 * 1. convert annual interest rate to a monthly interest rate by dividing by 12
 * 2. add 1 to the monthly rate
 * 3. multiply the number of years in the term of the mortgage by 12
 * 4. raise the result of 1 plus the monthly rate to the negative power of the number of monthly payments
 * 5. subtract that result from 1
 * 6. divide the monthly rate by the result
 * 7. multiply the result by the amount you want to borrow (price - downpayment)
 * 8. add the pmi
 *
 */
double calculateMonthlyPayment(double price, double rate, short loanTerm, double downpayment, double pmi) {
  double monthlyPayment = 0.0;
  double monthlyRate = (rate / 12.0);  // step 1
  double temp1 = 1.0 + monthlyRate;    // step 2
  int numPayments = 12 * loanTerm;     // step 3

  double temp2 = 1 - pow(temp1, -1.0 * numPayments);  // step 4 and 5
  double temp3 = monthlyRate / temp2;                 // step 6

  monthlyPayment = (price - downpayment) * temp3;  // step 7
  monthlyPayment += pmi;                           // step 8

  return monthlyPayment;
}
