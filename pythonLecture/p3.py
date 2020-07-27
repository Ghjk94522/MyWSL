#! python3

'''
    @ Project : pythonLecture

    @ File Name : p3.py

    @ Author : CoconutIcy

    @ Created on : 2020-7-7   22:29

    @ Lasted edited on : 2020-7-10   22:09

    @ About : lamda function in PYTHON
              enum class
              meta class
              list comprehension
'''

# 书签 ： 元类 metaclass : https://www.liaoxuefeng.com/wiki/1016959663602400/1017592449371072

from enum import Enum

q = list(map(lambda x : x * x, [1, 2, 3, 5, 7, 8, 9]))

# the default value starts from 1
Month = Enum('Month', ('Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jly', 'Aug', \
            'Sep', 'Oct', 'Nov', 'Dec'))

# if wanna a more advanced enum class :
class Day(Enum):
    Sun = 0
    Mon = 1
    Tue = 2
    Wed = 3
    Thu = 4
    Fri = 5
    Sat = 6

# use type() to define a class
def fn(self, name='world'):
    print('Hello {}'.format(name))
# pay attention to the tuple of object which has only one element
HellO = type('Hello', (object, ), dict(hello=fn))


# meta class must inheriant from type and metaclass' name must end with 'Metaclass'
class ListMetaclass(type):
    
    def __new__(cls, name, bases, attrs):
        attrs['add'] = lambda self, value : self.append(value)
        return type.__new__(cls, name, bases, attrs)

class MyList(list, metaclass=ListMetaclass):
    '''
    当我们传入关键字参数metaclass时，魔术就生效了，它指示Python解释器在创建MyList时，
    要通过ListMetaclass.__new__()来创建，在此，我们可以修改类的定义，比如，加上新的方法，
    然后，返回修改后的定义。
    '''
    pass

'''
__new__()方法接收到的参数依次是：

当前准备创建的类的对象；
类的名字；
类继承的父类集合；
类的方法集合。
'''

matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
flat = [x for row in matrix for x in row]
# flat = [1, 2, 3, 4, 5, 6, 7, 8, 9]
square = [[x ** 2 for x in row] for row in matrix]
# square = [[1, 4, 9], [16, 25, 36], [49, 64, 81]]





if __name__ == "__main__":
    print(q)
    for name, member in Month.__members__.items():
        print(name, '=>', member, ',', member.value)
    for name, member in Day.__members__.items():
        print(name, '=>', member, ',', member.value)

    day1 = Day.Mon
    day2 = Day['Mon']
    day3 = Day(1)
    h = HellO()
    h.hello()
    l = MyList()
    l.add(1)
    ll = list()
    # ll.add(1) # wrong because normal list doesn't have add
