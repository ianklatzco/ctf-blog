# from 0x1640 region in memory
from_mem = [0x90,0x69,0x42,0x37,0x13,0x08,0x10,0x09,0x08,0x07]

# from ghidra decompilation

keylist = [0xde, 0x49, 0x05, 0x58, 0x7d, 0x72, 0x71, 0x65, 0x6d, 0x7d]
 
a = [ chr(x ^ y)  for x,y in zip(from_mem, keylist)]

print(a)
print(''.join(a))
	