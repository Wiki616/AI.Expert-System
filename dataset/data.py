import csv  
  
#���ļ���ȡ  
reader = csv.reader(file('','rb'))  
  
for line in reader:  
    #���Ե�һ��  
    if reader.line_num == 1:  
        continue  
  
    #line�Ǹ�list��ȡ��������Ҫ��ֵ  
    type = line[0]  
  
  
#д���ļ�  
#writer = csv.writer(open(targetFile,"wb"),quoting=csv.QUOTE_ALL)  
  
#����list  
#writer.writerow(["121","121"])  
  
#����2γlist  
#writer.writerows([["121","121"]])  
