#! python3

'''
    @ Project : pythonLecture

    @ File Name : p6.py

    @ Author : CoconutIcy

    @ Created on : 2020-7-13   14:01

    @ Lasted edited on : 2020-7-18   22:55

    @ About : distribute process


'''


# task_master.py

import random, time, queue
from multiprocessing.managers import BaseManger

task_queue = queue.Queue()
result_queue = queue.Queue()


class QueueManager(BaseManger):
    pass


