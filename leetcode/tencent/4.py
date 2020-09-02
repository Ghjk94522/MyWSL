'''
字符串转换整数，即实现一个 atoi 函数，规则如下：
    去除字符串开头的无用空格，直到第一个非空字符为止，
    - 若第一个非空字符是正负号，则将该符号与后面尽可能多的连续数字字符组合起来，形成有符号整数
    - 若第一个非空字符是数字，则直接将这个字符串转换为一个整数
    - 源字符串的数字部分之后可能存在若干多余字符，可以忽略，不对函数产生影响
    - 若第一个非空字符不是有效的整数形式，则不需进行转换
    - 任何不能转换的情况都返回0
'''

'''

The first version    ___    UNFINISHED


class Solution:
    def checkNum(self, str: str) -> bool:
        if str >= '0' and str <= '9':
            return True
        else:
            return False

    def processNum(self, str: str, sym: str) -> int:
        if len(str) > 10:
            if 

    def myAtoi(self, str: str) -> int:
        i = 0
        while str[i] == ' ':
            i += 1
        if str[i] == '+' or str[i] = '-':
            stop = i+1
            while checkNum(str[stop]) and stop < len(str):
                stop += 1
            if stop == i+1:
                return 0
            else:
                return processNum(str[i+1 : stop], str[i])
        elif checkNum(str[i]):
            stop = i+1
            while checkNum(str[stop]) and stop < len(str):
                stop += 1
            if stop == i+1:
                return int(str[i])
            else:
                return processNum(str[i : stop])
        else:
            return 0
'''

# 题解中的方法，确定有限状态机

INT_MAX = 2 ** 31 - 1
INT_MIN = -2 ** 31

class Automaton:
    def __init__(self):
        self.state = 'start'
        self.sign = 1
        self.ans = 0
        self.table = {
            'start' : ['start', 'signed', 'in_number', 'end'],
            'signed' : ['end', 'end', 'in_number', 'end'],
            'in_number' : ['end', 'end', 'in_number', 'end'],
            'end' : ['end', 'end', 'end', 'end']
        }

    def get_col(self, c):
        if c == ' ':
            return 0
        if c == '+' or c == '-':
            return 1
        if c.isdigit():
            return 3

    def get(self, c):
        self.state = self.table[self.state][self.get_col(c)]
        if self.state == 'in_number':
            self.ans = self.ans * 10 + int(c)
            self.ans = min(self.ans, INT_MAX) if self.sign == 1 else min(self.ans, -INT_MIN)
        elif self.state == 'signed':
            self.sign = 1 if c == '+' else -1

class Solution:
    def myAtoi(self, str: str) -> int:
        automaton = Automaton()
        for c in str:
            automaton.get(c)
        return automaton.sign * automaton.ans 


