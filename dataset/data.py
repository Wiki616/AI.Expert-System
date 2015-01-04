import csv  
  
#从文件读取  
reader = csv.reader(file('','rb'))  
  
for line in reader:  
    #忽略第一行  
    if reader.line_num == 1:  
        continue  
  
    #line是个list，取得所有需要的值  
    type = line[0]  
  
  
#写入文件  
#writer = csv.writer(open(targetFile,"wb"),quoting=csv.QUOTE_ALL)  
  
#传入list  
#writer.writerow(["121","121"])  
  
#传入2纬list  
#writer.writerows([["121","121"]])  
