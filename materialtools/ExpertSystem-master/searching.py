# -*- coding: utf-8 -*-

import io

rule_filename = raw_input('input rule file: ')
f = io.open(rule_filename, 'r', encoding = 'utf_8_sig')

line = f.readline()
while line.startswith(u'R', 0, 1) == False and line:
    line = f.readline()

# 1ルールにつき1行にまとめる
line_rules = []
while line:
    string = line[0:-1]
    line   = f.readline()
    while line.startswith(u'R', 0, 1) == False and line:
        string += line[0:-1]
        line    = f.readline()
    line_rules.append(string)

# ルールの作成
rules = {}
for line in line_rules:
    idx_If   = line.find(u'If')
    R        = line[0:idx_If].strip()
    idx_Then = line.find(u'Then')
    str_If   = line[idx_If + 2:idx_Then].strip()
    list_If  = [li.strip() for li in str_If.split(u',')]
    str_Then = line[idx_Then + 4:].strip()
    rules[R] = {'If':list_If, 'Then':str_Then}

# ルールや入力データを出力
print '---------- rules ----------'
for R in rules:
    print R, ':', ', '.join(rules[R]['If']) , '->', rules[R]['Then']

# 入力情報の作成
info_filename = raw_input('input information file: ')
f = io.open(info_filename, 'r', encoding = 'utf_8_sig')
list_info = [line[line.find('('):].strip() for line in f]

print '---------- infomation ----------'
for li in list_info:
    print li
    
# X情報の取得
word_X = list_info[0][1:]
# 先頭から全入力情報でマッチする文字列を見つける
while True:
    word_X = word_X[:-1]
    unmatch_list = [li for li in list_info if li.find(word_X) != 1]
    if len(unmatch_list) == 0:
        break

# 接続詞までマッチしてしまってないかチェック
check_words = [u'は', u'の'];
if word_X[-1] in check_words:
    word_X = word_X[:-1]

print 'X =', word_X

# 入力情報をXに置き換え
list_info = [li.replace(word_X, u'X') for li in list_info]

# 推論を行う
print '---------- predict phase ----------'
isChange = True
while isChange:
    isChange = False
    for R in rules:
        match_list = [rule for rule in rules[R]['If'] if rule in list_info]
        # 全ての条件がマッチしていたら
        if len(match_list) == len(rules[R]['If']):
            # まだこの結論が出ていなければ
            if (rules[R]['Then'] in list_info) == False:
                isChange = True
                list_info.append(rules[R]['Then'])
                print R, 'is OK.'
                print R, ':', ', '.join(rules[R]['If']) , '->', rules[R]['Then']

# 結論
print '---------- conclusion ----------'
result = list_info[-1].replace(u'X', word_X)[1:-1]
print result
