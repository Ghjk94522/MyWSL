import collections

ans = [1, 2, 3, 5, 7, 8, 9, 11, 4, 6]
res = sorted(collections.Counter(ans).items())
print(res)