#include <stdio.h>
#include <windows.h>
int main() {
    int h, m, s;
    int delay = 1000;
    printf("set time:");
    scanf("%d%d%d", &h, &m, &s);

    if (h > 12 || m > 60 || s > 60) {
        printf("you are stupid:)");
        return 0;  // end code
    }

    while (1) {
        if (s == 0 && m == 0 && h == 0) {
            printf("stoppppp!");
            return 0;
        }

        printf("%02d:%02d:%02d", h, m, s);  // form as 00:00:00
        // count down
        if (s > 0) {
            s--;
        } else if (s ==0 && m != 0) {//== is determination sign
            m--;
            s = 59;
        }

        if ((m == 0) && (s == 0) && (h > 0)) {
            h--;
            m = 59;
            s = 59;
        }

        Sleep(delay);  // delay the speed of loop excute
        system("cls");
    }
}
