int main(void)
{
    int i;

    for (i = 0; i < 5; i++) {
        __asm volatile ("NOP");
    }
}
