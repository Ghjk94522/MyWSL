#! python3

'''
    @ Project : pythonLecture

    @ File Name : p2.py

    @ Author : CoconutIcy

    @ Created on : 2020-7-7   22:19

    @ Lasted edited on : 2020-7-8   10:35

    @ About : advanced content of OBJECT-PYTHON
                - @property
                - multiple inheritance
                - special methods
                    * __str__
                    * __iter__


'''

# 书签：定制类  https://www.liaoxuefeng.com/wiki/1016959663602400/1017590712115904
# 书签：定制类的文档  https://docs.python.org/2/reference/datamodel.html#special-method-names


# @property
# @special methods
#    * __str__
class Student(object):

    # def __init__(self, score):
    #     self._score = score

    @property
    def score(self):
        return self._score

    @score.setter
    def score(self, value):
        if not isinstance(value, int):
            raise ValueError('score mest be an integer')
        if value < 0 or value > 100:
            raise ValueError('score must between 0~100')
        self._score = value

    # and if we only write getter but no setter
    # the property will be only read
    @property
    def birth(self):
        return self._birth
    
    @birth.setter
    def birth(self, value):
        self._birth = value

    # because the age can be cal from the birth
    # so it's only read
    @property
    def age(self):
        return 2020 - self._birth

    def __init__(self, name):
        self.name = name

    def __str__(self):
        return 'Student object (name: {})'.format(self.name)
    __repr__ = __str__
    '''
    直接显示变量调用的不是__str__()，而是__repr__()，两者的区别是__str__()返回用户看到的字符串，
    而__repr__()返回程序开发者看到的字符串，也就是说，__repr__()是为调试服务的。
    '''


# @mul inheritance
class Animal(object):
    pass

class Mammal(Animal):
    pass

class Bird(Animal):
    pass

class Dog(Mammal):
    pass

class Parrot(Bird):
    pass

class Flyable(object):
    def fly(self):
        pass

class Bat(Mammal, Flyable):
    pass


# @special methods
#    * __iter__
class Fib(object):
    def __init__(self):
        self.a, self.b = 0, 1

    def __iter__(self):
        return self

    def __next__(self):
        self.a, self.b = self.b, self.a + self.b
        if self.a > 100000:
            raise StopIteration()
        return self.a



if __name__ == "__main__":
    s = Student('jack')
    s.score = 60
    s.birth = 1999
    # s.score = 999 # wrong
    print(s.age)
    # s.age = 20 # wrong
    print(s)
    # the output above is : Student object (name: jack)
    # but if without __str__, it will be:
    # <__main__.Student object at 0x7f5c785d1b10>
    for n in Fib():
        print(n)
    # the output will be :
    '''
    1
    1
    2
    3
    5
    8
    13
    21
    34
    55
    89
    144
    233
    377
    610
    987
    1597
    2584
    4181
    6765
    10946
    17711
    28657
    46368
    75025
    '''