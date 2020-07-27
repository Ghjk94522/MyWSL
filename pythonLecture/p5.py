#! python3

'''
    @ Project : pythonLecture

    @ File Name : p5.py

    @ Author : CoconutIcy

    @ Created on : 2020-7-13   14:01

    @ Lasted edited on : 2020-7-14   22:38

    @ About : process and thread
                - threading
                - Lock
                - ThreadLocal
                - process vs thread


'''


import time, threading

def loop():
    print('thread {} is running...'.format(threading.current_thread().name))
    n = 0
    while n < 5:
        n = n + 1
        print('Thread {} >> {}'.format(threading.current_thread().name, n))
        time.sleep(1)
    print("thread {} end.".format(threading.current_thread().name))

def threading_test():
    print("thread {} is running".format(threading.current_thread().name))
    t = threading.Thread(target=loop, name='LoopThread')
    t.start()
    t.join()
    print('thread {} end.'.format(threading.current_thread().name))

balance = 0
lock = threading.Lock()

def change(n):
    global balance
    balance = balance + n 
    balance = balance - n 

def run_wot_lock(n):
    for i in range(1000000):
        change(n)

def run_thread(n):
    for i in range(1000000):
        lock.acquire()
        try:
            change(n)
        finally:
            lock.release()

local_school = threading.local()

def process_student():
    std = local_school.student
    print("Hello {} (in {})".format(std, threading.current_thread().name))

def process_thread(name):
    local_school.student = name
    process_student()



if __name__ == '__main__':
    t1 = threading.Thread(target=process_thread, args=('Alice', ), name='Thread_A')
    t2 = threading.Thread(target=process_thread, args=('Bob',), name='Thread_B')
    t1.start()
    t2.start()
    t1.join()
    t2.join()
    print(balance)
