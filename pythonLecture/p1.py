#! python3

'''
    @ Project : pythonLecture

    @ File Name : p1.py

    @ Author : CoconutIcy

    @ Created on : 2020-7-7   21:04

    @ Lasted edited on : 2020-7-7   21:04

    @ About : OBJECT-PYTHON
'''

class Student(object):
    '''
    在类里面直接定义的变量类似于static的变量可以在所有对象实例中共享
    通过self定义的变量是每个对象实例自己的，
    所以要注意，对象属性和类属性（变量）不要重名，否则会覆盖
    也就是说，py作为一个动态语言和静态语言不同之处在于，他的每个对象实例可能是
    拥有不同属性（变量）的
    '''
    school = "Fuxin Experiment Middle School"

    def __init__(self, name, score, sex):
        # public variable
        self.name = name
        self.score = score
        # private :
        self.__sex = sex
    '''
    需要注意的是，在Python中，变量名类似__xxx__的，也就是以双下划线开头，
    并且以双下划线结尾的，是特殊变量，特殊变量是可以直接访问的，不是private变量，
    所以，不能用__name__、__score__这样的变量名。
    有些时候，你会看到以一个下划线开头的实例变量名，比如_name，
    这样的实例变量外部是可以访问的，但是，按照约定俗成的规定，当你看到这样的变量时，
    意思就是，“虽然我可以被访问，但是，请把我视为私有变量，不要随意访问”。
    双下划线开头的实例变量是不是一定不能从外部访问呢？其实也不是。
    不能直接访问__name是因为Python解释器对外把__name变量改成了_Student__name，
    所以，仍然可以通过_Student__name来访问__name变量.
    但是强烈建议你不要这么干，因为不同版本的Python解释器可能会把__name改成不同的变量名。
    '''

    def printScore(self):
        print("{} {}".format(self.name, self.score))

    def set_sex(self, sex):
        if(sex == 'male' or sex == 'female'):
            self.sex = sex
        else:
            print('Check your input, and make sure is "male" or "female".')

class duck(object):

    def __init__(self):
        pass

    def printScore(self):
        print("I can use this function too.")


# In addition, python is a "duck" language, as 
# 'If you look like a duck, and run as a duck,
# YOU are a duck!'
def print_twice(item):
    item.printScore()
    item.printScore()

'''
那么，py是不是不能限制添加属性呢，当然不是，通过引入slot,可以解决这一问题
但是要注意子类并不受这一限制，除非子类也定义slot
'''
class pupil(object):
    __slots__ = {'age', 'name'}




if __name__ == "__main__":
    stu1 = Student('yzb', 5, 'male')
    stu2 = Student("coco", 4.5, 'female')
    stu1.printScore()
    stu2.name = 'Coco'
    print("{} {}".format(stu2.name, stu2.score))
    # private variables can not be accessed from outer
    # stu2.sex = 'male' # wrong
    # and if you write as that or like above : 
    # stu2.__sex = 'male'
    # the interpreter will not worn because it will 
    # create a new variable
    d1 = duck()
    print_twice(stu1)
    print_twice(d1)

    p = pupil()
    p.name = 'xiaoming'
    p.age = 12
    # p.score = 99 # wrong because score is not in the slots
