#coding=utf-8

import socket
import time
import traceback

from log import *
from util import *

ESPN_SCHEDULE = "http://espn.go.com/nba/team/schedule/_/name/{team}"

SCHEDULE_TIMEOUT = 60

from datetime import datetime


def espn_get_schedule(teamname):
    socket.setdefaulttimeout(SCHEDULE_TIMEOUT)

    url = ESPN_SCHEDULE.format(team=teamname)

    html = get_url(url, SCHEDULE_TIMEOUT)

    #parse for more url

    more_url = []
    try:
        div = html.xpath("//div[@class='mod-page-tabs mod-thirdnav-tabs']")[0]
        lis = div.xpath(".//li") 
        for li in lis:
            if li.attrib.get('class') != 'active':
                a = li.find('a');
                more_url.append(a.attrib['href'])    

    except Exception as e:
        log(traceback.format_exc())
        log('WARNING - parse error')    
        return

        
    htmls = [html]
    for url in more_url:
        htmls.append(get_url(url, SCHEDULE_TIMEOUT))
    
    
    alldata = []
    for html in htmls:
        try:
            alldata += espn_parse_schedule_html(html)
        except Exception as e:
            log(traceback.format_exc())
            log('WARNING - parse error')    



    
def espn_parse_schedule_html(html):
    content = html.xpath("//div[@class='mod-content']")[0]
    trs = content.xpath(".//tr")

    data = []
    for tr in trs:
        if 'team' in tr.attrib.get('class', 'n'):
            tmp = {}
            tds = tr.xpath(".//td")

            td = tds[0]
            
            now = datetime.now()
            date = datetime.strptime("Wed, Apr 15", "%a, %b %d")
            
            td = tds[1]
            try:
                tmp['game'] = td.find("ul/li").text + td.xpath(".//a")[-1].text
            except: # oppsize is not a nba team
                tmp['game'] = td.find("ul/li").text + td.findall("ul/li")[-1].text
            
            td = tds[2]
            if td.text:
                tmp['time'] = td.text
            else:
                tmp['result'] = td.find("ul/li/span").text + td.find("ul/li/a").text
            
            data.append(tmp)

    
    return data
    
    
    
    
    
   
