#! /usr/bin/env python
#coding=utf-8

import threading

from log import *
from const import *
from espn import *


def get_team_schedule(teamname):
    log("[INFO] - Getting %s schedule" % teamname)
    data = espn_get_schedule(teamname)
        



def schedule_spider():
    for team in TEAMLDICT.values():
        t = threading.Thread(target=get_team_schedule, args=(team,))
        t.start()

        
def main():
    init_log("schedule_spider")
    schedule_spider()



if __name__ == "__main__":
    main()
