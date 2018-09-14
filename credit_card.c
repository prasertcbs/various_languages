#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CARD_DIGITS 16

int addDigit(int n) {
    return n / 10 + n % 10;
}

char boolString(bool b) {
    return (char) (b ? 'T' : 'F');
}

void calculationSteps(char *barcode) {
//     ref: https://en.wikipedia.org/wiki/International_Article_Number#Calculation_examples
    printf("%15s%5s", "position", "");
    for (int i = 0; i < CARD_DIGITS - 1; ++i) {
        printf("%2d ", i);
    }
    printf("\n");
    printf("%15s%5s", "code", "");
    for (int i = 0; i < CARD_DIGITS - 1; ++i) {
        printf("%2d ", barcode[i] - '0');
    }
    printf("\n");
    printf("%15s%5s", "weight", "");
    for (int i = 0; i < CARD_DIGITS - 1; ++i) {
        printf("%2d ", i % 2 == 0 ? 2 : 1);
    }
    printf("\n");
    printf("%15s%5s", "partial sum", "");
    int sum = 0;
    for (int i = 0; i < CARD_DIGITS - 1; ++i) {
        int a = (i % 2 == 0 ? 2 : 1) * (barcode[i] - '0');
        sum += addDigit(a);
        printf("%2d ", a);
    }
    printf("\n");
    printf("%15s%5s", "add digits", "");
    for (int i = 0; i < CARD_DIGITS - 1; ++i) {
        int a = (i % 2 == 0 ? 2 : 1) * (barcode[i] - '0');
        printf("%2d ", addDigit(a));
    }
    printf("\n");
    printf("check sum   = %2d\n", sum);
    int r = sum % 10;
    printf("check digit = %2d\n", (r == 0) ? 0 : 10 - r);
}

int checkDigit(char *barcode) {
    int n, mult;
    int sum = 0;
    if (strlen(barcode) < CARD_DIGITS - 1) { // need at least first 15 digits to calc the check digit (16th digit)
        return -1;
    }
    for (int i = 0; i < CARD_DIGITS - 1; ++i) {  // use first 12 digits to calc
        n = barcode[i] - '0';
        mult = i % 2 == 0 ? 2 : 1;
        sum += addDigit(n * mult);
    }
    int r = sum % 10;
    return (r == 0) ? 0 : 10 - r;
}

bool isValidCardNumber(char *cardNumber) {
    int chkdigit = checkDigit(cardNumber);
    return chkdigit == cardNumber[CARD_DIGITS - 1] - '0' ? true : false;
}

int main() {
    char *cardNumber = "5404123456789016";
//    char *cardNumber = "4006087085455";
//    char *cardNumber = "8806173430161";
    calculationSteps(cardNumber);
    printf("cardNumber = %s, check digit = %d\n", cardNumber, checkDigit(cardNumber));
    printf("cardNumber = %s, valid = %c\n", cardNumber, boolString(isValidCardNumber(cardNumber)));
}