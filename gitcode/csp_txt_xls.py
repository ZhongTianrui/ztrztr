import xlwt
import xlrd
#xlwt,xlrd是python将数据导入excel表格使用的库

wb = xlwt.Workbook()
# 添加一个表
ws = wb.add_sheet('csp')
f = open("csp_data.txt", encoding='utf-8', errors='ignore')
i = 0
#添加数据使用.write函数（横坐标，纵坐标，内容）注意横纵坐标从0开始，横纵坐标即对于excel而言
for line in f :
    li = line.strip().split(' ')
    print(li)
    ws.write(i, 0, li[0])
    ws.write(i, 1, li[1])
    i += 1
ws = wb.add_sheet('csp_2020')
f = open("csp_2020_data.txt", encoding='utf-8', errors='ignore')
i = 0
#添加数据使用.write函数（横坐标，纵坐标，内容）注意横纵坐标从0开始，横纵坐标即对于excel而言
for line in f :
    li = line.strip().split(' ')
    print(li)
    ws.write(i, 0, li[0])
    ws.write(i, 1, li[1])
    i += 1
ws = wb.add_sheet('csp_2021')
f = open("csp_2021_data.txt", encoding='utf-8', errors='ignore')
i = 0
#添加数据使用.write函数（横坐标，纵坐标，内容）注意横纵坐标从0开始，横纵坐标即对于excel而言
for line in f :
    li = line.strip().split(' ')
    print(li)
    ws.write(i, 0, li[0])
    ws.write(i, 1, li[1])
    i += 1
ws = wb.add_sheet('csp_2022')
f = open("csp_2022_data.txt", encoding='utf-8', errors='ignore')
i = 0
#添加数据使用.write函数（横坐标，纵坐标，内容）注意横纵坐标从0开始，横纵坐标即对于excel而言
for line in f :
    li = line.strip().split(' ')
    print(li)
    ws.write(i, 0, li[0])
    ws.write(i, 1, li[1])
    i += 1

#将数据导出，保存格式为xxx.xls。其中xxx与上文表名同步
#注意此处一定要保存为.xls形式，如果是xlsx会打不开
wb.save('csp_data.xls')
