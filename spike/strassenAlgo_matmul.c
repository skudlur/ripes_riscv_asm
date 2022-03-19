/**
 * Compute the product of two WxW matricies.
 * NOTE: In this program, we provide our own startup code and do not rely on any
 * C standard library features.
 * As such, this program compiles safely with the "-nostdlib" linker flag.
 */

asm("li sp, 0x100000");  // SP set to 1 MB
asm("jal main");         // call main
asm("mv a1, a0");        // save return value in a1
asm("li a7, 10");        // prepare ecall exit
asm("ecall");            // now your simulator should stop

#define W 2  // Matrix order

void mmul(const int a[W][W], const int b[W][W], int c[W][W])
{
    int m1, n1, m2, n2, i, j, k;
    static int i = 0, j = 0, k = 0;
 
    if (i >= m1)
    {
        return;
    }
    else if (i < m1)
    {
        if (j < n2)
        {
            if (k < n1)
            {
                c[i][j] += a[i][k] * b[k][j];
                k++;
                multiply(m1, n1, a, m2, n2, b, c);
            }
            k = 0;
            j++;
            multiply(m1, n1, a, m2, n2, b, c);
        }
        j = 0;
        i++;
        multiply(m1, n1, a, m2, n2, b, c);
    }
}

int main() {
    int A[W][W];
    int B[W][W];
    int C[W][W];
    mmul(A, B, C);
    return 0;
}
