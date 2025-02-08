import random

MINN = 200
MAXN = 200

MINL = 200
MAXL = 200

n = random.randint(MINN, MAXN)
print(n)
for i in range(n):
    length = random.randint(MINL, MAXL)
    s = ""
    for j in range(length):
        s += chr(ord('a') + random.randint(0, 25))
    print(f"{len(s)} {s}")
L = [chr(ord('a') + i) for i in range(0, 26)]
random.shuffle(L)
L = "".join(L)
print(L)