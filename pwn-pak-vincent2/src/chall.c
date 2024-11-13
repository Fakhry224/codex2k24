#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void setup() {
  setvbuf(stdin, 0LL, 2, 0LL);
  setvbuf(stdout, 0LL, 1, 0LL);

  gid_t gid = getegid();
  setresgid(gid, gid, gid);

  fflush(stdout);
}

void teleport();
void win();

int main() {
  setup();

  char key1[32];
  char key2[64];

  printf("Pak Vincent, nih ada hadiah buat Bapak\n");
  printf("Tapi sebutin dulu kunci ke-1 nya apa? ");
  gets(key1);

  if(strcmp(key1, "cosmos") == 0) {
    printf("Jangan curang pak :P\n");
    return  0;
  }

  printf("Sekarang kunci ke-2 nya apa? ");
  gets(key2);

  if(strcmp(key1, "cosmos") == 0 && strcmp(key2, "candidateOfaWinner") == 0){
    printf("WOW... Pak Vincent berhasil menjawab kedua kuncinya!\n");
    teleport();

    printf("Yaudah nih hadiah buat Pak Vincent :D");
  } else {
    printf("Yah... kuncinya masih salah pak TT\n");
    printf("Coba lagi ya Pak..");
  }

  return 0;

}

void teleport() {
  char buffer[64];

  puts("Pak Vincent mau flag gak? ");
  gets(buffer);
}

void read_flag() {
  char flag[64];
  
  FILE *file = fopen("flag.txt", "r");
  if (file == NULL) {
    printf("flag.txt is missing! please create file flag.txt first\n");

    exit(0);
  }

  fgets(flag, sizeof(flag), file);
  printf("Flag: %s\n", flag);

  fclose(file);

  exit(0);
}

void win() {
  printf("Yeay, Selamat Pak Vincent berhasil mendapatkan flag :D, ini flag buat Pak Vincent:\n");

  read_flag();

  return 0;
}
