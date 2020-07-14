#! python3

'''
    @ Project : pythonLecture

    @ File Name : p4.py

    @ Author : CoconutIcy

    @ Created on : 2020-7-10   16:48

    @ Lasted edited on : 2020-7-13   13：18

    @ About : process and thread
                - fork
                - Process
                - Pool
                - subprocess
                - communicate between processes


'''

# 书签 ： 进程间通信 ： https://www.liaoxuefeng.com/wiki/1016959663602400/1017628290184064


import os
'''
如果使用Linux系统那么可以直接使用os库来调用fork()函数，
但是win系统不支持fork函数，所以可以使用跨平台库multiprocessing
'''
from multiprocessing import Process, Queue
import time
import random
from multiprocessing import Pool
import subprocess


def LinuxMethod():
    # Linux method:
    print('Process {} starts.'.format(os.getpid()))
    pid = os.fork()
    if pid == 0:
        print('I am child process {} and my father is {}'.format(os.getpid(), os.getppid()))
    else:
        print('I ({}) just created a child process ({})'.format(os.getpid(), pid))

def run_proc(name):
    print('Run child process {} ({})'.format(name, os.getpid()))

def WinMethod():
    # Win method:
    print('Parent process : {}'.format(os.getpid()))
    p = Process(target=run_proc, args=('test', ))
    print('Child process will start.')
    p.start()
    p.join()
    print('Child process end.')


# pay attention to the print function format and ()behand the function name
# and maybe try this on the real mechine to find the result
def long_time_task(name):
    print('Run task {} ({})'.format(name, os.getpid()))
    start = time.time()
    time.sleep(random.random() * 3)
    end = time.time()
    print('Task {} runs {:.2f} seconds.'.format(name, (end - start)))

def pool_test():
    print('Parent process {}'.format(os.getpid()))
    # the default pool args is equal to the num of cores of the cpu
    p = Pool()
    for i in range(5):
        p.apply_async(long_time_task, args=(i, ))
    print("Wait for all subprocess done.")
    p.close()
    p.join()
    print("All subprocess done")

def subprocess_test():
    '''
    相当于在命令行执行命令nslookup，然后手动输入:
    set q=mx
    python.org
    exit
    '''
    print('$ nslookup ')
    p = subprocess.Popen(['nslookup'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, 
                            stderr=subprocess.PIPE)
    output, err = p.communicate(b'set q=mx\npython.org\nexit\n')
    print(output.decode('utf-8'))
    print('Exit code : ', p.returncode)
    # print('$ nslookup www.python.org')
    # r = subprocess.call(['nslookup', 'www.python.org'])
    # print('Exit code : ', r)

def write(q):
    print("Process to write {}".format(os.getpid()))
    for value in ['A', 'B', 'C']:
        print('Put {} to queue.'.format(value))
        q.put(value)
        time.sleep(random.random())

def read(q):
    print('Process to read {}'.format(os.getpid()))
    while True:
        value = q.get(True)
        print('Get {} from queue'.format(value))

def commute_test():
    q = Queue()
    pw = Process(target=write, args=(q, ))
    pr = Process(target=read, args=(q, ))
    pw.start()
    pr.start()
    pw.join()
    pr.terminate()


if __name__=='__main__':
    pool_test()