#include <stdio.h>

int main(void)
{
    int i;

    SystemInit();

    while (1) {
        for (i = 0; i < 5; i++) {
            if (i < 2) {
                i++;
            }
        }
    }
}
