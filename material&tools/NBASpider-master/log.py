#! /usr/bin/evn python

import time
import threading

DEBUG = False
DEBUG = True

logfile = None
logmutex = threading.Lock()



def init_log(logname):
    global logfile
    logfile = open("%s-%s.log" % (logname, time.strftime("%F")), "a+")
    


def log(string):
    s = "%s : %s\n" % (time.strftime('%Y-%m-%d %H:%M:%S'), string)
    logmutex.acquire()
    if DEBUG:
        print s,
    logfile.write(s)
    logfile.flush()
    logmutex.release()

