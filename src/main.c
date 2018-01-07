int main(void)
{
    int i;

    SystemInit();

    while (1) {
        for (i = 0; i < 5; i++) {
            __asm volatile ("NOP");
        }
    }
}
