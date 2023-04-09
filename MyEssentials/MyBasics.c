//! ========================== Swap advanced ==========================  //
void Swap_Advanced(int *num1, int *num2) // with no temp variable
{
    *num1 = *num1 + *num2; // add x and y and store in x
    *num2 = *num1 - *num2; // subtract y from x and store in y // x = x + y - y = x
    *num1 = *num1 - *num2; // subtract y from x and store in x // y = x + y - x = y
}
//! ========================== Swap ===================================  //
void Swap(int *num1, int *num2) // using temp variable
{
    int temp;
    temp = *num1;  // save the value of num1
    *num1 = *num2; // assign the value of num2 to num1
    *num2 = temp;  // assign the saved value of num1 to num2
}
//! ========================== isPowerOfTwo ============================  //
int isPowerOfTwo(int n) // time complexity: O(log n)
{
    if (n == 0) // 0 is not a power of 2
    {
        return 0;
    }
    while (n != 1) // while number is not 1
    {
        if (n % 2 != 0) // if number is odd
        {
            return 0;
        }

        n /= 2; // divide number by 2
    }
    return 1;
}
//! ========================== isPowerOfTwo_Advanced ===================  //
int isPowerOfTwo_Advanced(int num)
{
    if (num <= 0)
        return 0;

    if ((num & (num - 1)) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}