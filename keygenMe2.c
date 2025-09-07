#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

uint64_t custom_hash(const char* input) {
    uint64_t hash = 0xdeadbeefcafebabe;
    for (size_t i = 0; i < strlen(input); i++) {
        hash ^= (uint64_t)(input[i]) << ((i % 8) * 8);
        hash = ((hash << 13) | (hash >> (64 - 13))) + 0x1234;
    }
    return hash;
}

int validate(const char* name, const char* serial_str) {
    uint64_t serial = strtoull(serial_str, NULL, 16);
    uint64_t hash = custom_hash(name);
    return serial == ((hash ^ 0x1337133713371337ULL) & 0xFFFFFFFFFFFF);
}

int main() {
    char name[128];
    char serial[128];

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Enter your serial: ");
    fgets(serial, sizeof(serial), stdin);
    serial[strcspn(serial, "\n")] = 0;

    if (validate(name, serial)) {
        puts("✅ Correct Serial! Welcome!");
    } else {
        puts("❌ Invalid serial.");
    }

    return 0;
}

