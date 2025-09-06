#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int validate_serial(const char* name, const char* serial) {
    int sum = 0;
    int len = strlen(name);
    for (int i = 0; i < len; i++) {
        sum += name[i] ^ 0x55;
    }

    int serial_num = atoi(serial);
    if (serial_num == (sum * 1337 % 100000)) {
        return 1;
    }
    return 0;
}

int main() {
    char name[64];
    char serial[64];

    printf("Enter your name: ");
    fgets(name, 64, stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Enter your serial: ");
    fgets(serial, 64, stdin);
    serial[strcspn(serial, "\n")] = 0;

    if (validate_serial(name, serial)) {
        printf("✅ Correct serial! Welcome, %s.\n", name);
    } else {
        printf("❌ Invalid serial.\n");
    }

    return 0;
}

