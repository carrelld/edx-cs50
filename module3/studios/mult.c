/**
 * This function will multiply two numbers and return the product, recursively
 */
int mult(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }
    else
    {
        if(b > 0)
            return a + mult(a, b - 1);
        if(b < 0)
            return -a + mult(a, b + 1);
    }
    return 0;
}