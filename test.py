'''
Author: Coconut
Date: 2020-09-10 21:26:21
LastEditTime: 2020-09-18 20:19:12
LastEditors: Coconut
Description: 
FilePath: /myFile/myWSL/test.py
可以输入预定的版权声明、个性签名、空行等
'''
import collections

ans = [1, 2, 3, 5, 7, 8, 9, 11, 4, 6]
res = sorted(collections.Counter(ans).items())
print(res)