print("输入一个形如 a+b 的算式:")
s = str(input())
cnt = 0
a = [0, 0]
op = ''
lens = len(s);
for i in range(0, lens) :
    if s[i].isdigit() :
        a[cnt] = a[cnt] * 10 + int(s[i])
    else :
        op = s[i]
        cnt = cnt + 1;
if op == '+' :
    print(a[0] + a[1])
elif op == '-' :
    print(a[0] - a[1])
elif op == '*' :
    print(a[0] * a[1])
elif op == '/' :
    print(a[0] / a[1])
elif op == '%' :
    print(a[0] % a[1])
elif op == '&' :
    print(a[0] & a[1])
elif op == '|' :
    print(a[0] | a[1])
elif op == '^' :
    print(a[0] ^ a[1])
else :
    print("计算失败！！")