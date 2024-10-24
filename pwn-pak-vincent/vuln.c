#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main() {
    unsigned int amount;
    int count = 0;

    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    puts("Pak vincent, nasi berapa berapa pak?");
    scanf("%u", &amount);

    count += amount;
    printf("Nasi nya %d lah Pak Vincent\n", count);

    if (count == 0xdeadbeef) {
        win();
    }

    return 0;
}

void win() {
    char flag[64];
    char *flag_ptr = flag;

    puts("Hey how did u get here??? \n");

    FILE *file = fopen("flag.txt", "r");
    if (file == NULL) {
        printf("flag.txt is missing! please create file flag.txt first\n");
        exit(0);
    }

    fgets(flag, sizeof(flag), file);
    printf("Here's your Flag Pak Vincent: %s\n", flag);

    fclose(file);

    exit(0);
}
