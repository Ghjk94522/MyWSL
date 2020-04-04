#! /usr/bin/python3

def dealWord(src):
    res = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for i in src:
        res[ord(i)-ord('a')] += 1
    res = tuple(res)
    return res

def main():
    pw = 'wo yi yue du guan yu chao xi de shuo ming'
    n = input() # n is nothing but placeholder
    src = input()
    slist = sorted(src.split(' '))
    rlist = {}

    for i in range(len(slist)):
        tup = dealWord(slist[i])
        if tup in rlist.keys():
            rlist[tup][0] += 1
        else:
            rlist[tup] = [1, slist[i]]
    
    num = 0
    res = []
    dst = sorted(rlist.items(), key=lambda item: item[1][1])
    for i in range(len(dst)):
        if dst[i][1][0] > 1:
            res.append(dst[i][1][1])
            num += 1
    print(pw)
    print(num)
    for i in range(len(res)):
        print(res[i])

if __name__ == "__main__":
    main()