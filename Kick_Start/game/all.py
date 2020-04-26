n = input()
for i in range(int(n)):
    temp = input()
    k = int(temp.split(" ")[0])
    m = int(temp.split(" ")[1])
    t = input()
    plist = t.split(" ")
    plist = sorted(plist)
    count = 0
    res = 0
    while m > 0:
        m -= int(plist[count])
        count += 1
        if m >= 0:
            res += 1
    print("Case #{}: {}".format(i+1, res))