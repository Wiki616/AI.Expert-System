#coding=utf-8

import socket
import urllib
import traceback

from lxml import etree

from log import *


def get_url(url, sleeptime):
    while 1:
        html = get_page_by_urllib(url)
        if html:
            return html
        time.sleep(sleeptime)



def get_page_by_urllib(url):
    try:
        fp = urllib.urlopen(url)
        html = etree.parse(fp, etree.HTMLParser())
        fp.close()
        return html
    except Exception as e:
        log(traceback.format_exc())
        return None

