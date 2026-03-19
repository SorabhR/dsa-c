#include <stdio.h>

int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int isPrime(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int reverse(int n) {
    int rev = 0;
    while (n) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

int isPalindrome(int n) {
    int original = n, rev = 0;

    while (n) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }

    return original == rev;
}

int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

#include <stdio.h>

void fibonacci(int n) {
    int a = 0, b = 1, next;

    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        next = a + b;
        a = b;
        b = next;
    }
}

int countDigits(int n) {
    int count = 0;
    while (n) {
        count++;
        n /= 10;
    }
    return count;
}

#include <math.h>
//Armstrong is that sum of each digit ^ no. of digits is the number
int isArmstrong(int n) {
    int original = n, sum = 0, digits = 0;

    int temp = n;
    while (temp) {
        digits++;
        temp /= 10;
    }

    temp = n;
    while (temp) {
        int d = temp % 10;
        sum += pow(d, digits);
        temp /= 10;
    }

    return sum == original;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int isEven(int n) {
    return (n & 1) == 0;
}

int sumDigits(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int power(int base, int exp) {
    int result = 1;

    while (exp > 0) {
        if (exp & 1)
            result *= base;

        base *= base;
        exp >>= 1;
    }

    return result;
}
