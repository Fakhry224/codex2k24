#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void setup() {
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);

  gid_t gid = getegid();
  setresgid(gid, gid, gid);
}

int main() {
  setup();

  char key1[32];
  char key2[32];

  printf("Pak Vincent, nih ada hadiah buat Bapak\n");
  printf("Tapi sebutin dulu kunci ke-1 nya apa? ");
  gets(key1);

  if(strcmp(key1, "codex") == 0) {
    printf("Jangan curang pak :P\n");
    return  0;
  }

  printf("Sekarang kunci ke-2 nya apa? ");
  gets(key2);

  if(strcmp(key1, "codex") == 0 && strcmp(key2, "candidateOfaWinner") == 0){
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

void win() {
  printf("Yeay, Selamat Pak Vincent berhasil mendapatkan flag :D, ini flag buat Pak Vincent: CODEX2K24{PLACEHOLDER}\n");

  return 0;
}
