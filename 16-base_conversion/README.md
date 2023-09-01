# Base Conversion

Converting between bases such as binary, hexadecimal, and decimal is a useful skill to have as a Computer Scientist. If you understand the process well enough, you should be able to convert between any two bases arbitrarily.

## Converting from base 10 to base 16

To convert from base 10 to base 16, we can use the following algorithm:

```
while the quotient is not equal to 0:
    divide the number by 16
    get the integer quotient for the next iteration
    get the remainder for the hex digit (0 - 15 maps to 0 - F)
```

## Generalizing to any base

We can generalize this process to convert from base 10 to any base. Since we only have 10 digits and 26 letters, we will limit our program to base 36. The algorithm is as follows:

```
while the quotient is not equal to 0:
    divide the number by the base
    get the integer quotient for the next iteration
    get the remainder for the digit (0 - (base - 1) maps to 0 - 9, A - Z)
```

## Converting from base 16 to base 10

Converting back to base 10 is much simpler. We can use the following algorithm:

```
for each digit in the number:
    multiply the digit by 16^i where i is the index of the digit
    add the result to the total
```

## Generalizing to any base

We can generalize this process to convert from any base to base 10. The algorithm is as follows:

```
for each digit in the number:
    multiply the digit by base^i where i is the index of the digit
    add the result to the total
```

## Converting from any base to any base

We can combine the two algorithms above to convert from any base to any base. The algorithm is as follows:

```
convert the number from the original base to base 10
convert the number from base 10 to the new base
```