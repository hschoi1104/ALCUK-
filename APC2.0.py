import requests
from bs4 import BeautifulSoup
from oauth2client.service_account import ServiceAccountCredentials
import gspread
import time

# __init__
gc_key ='your gc_key'
# set oauth
scope = ['https://spreadsheets.google.com/feeds',
         'https://www.googleapis.com/auth/drive']
credentials = ServiceAccountCredentials.from_json_keyfile_name('ALCUKPracticeChecker.json', scope)
gc = gspread.authorize(credentials)
# open and select worksheet
wks = gc.open_by_key(gc_key)


def excel_style(row, col):
    # http://code.activestate.com/recipes/578941-spread-sheet-style-column-enumeration-letter-to-nu/
    """ Convert given row and column number to an Excel-style cell name. """
    quot, rem = divmod(col - 1, 26)
    return ((chr(quot - 1 + ord('A')) if quot else '') +
            (chr(rem + ord('A')) + str(row)))


def writeProbdb(id, idx):
    # bs4
    res = requests.get('https://www.acmicpc.net/user/' + id)
    soup = BeautifulSoup(res.content, 'html.parser')

    num = soup.select(
        "body > div.wrapper > div.container.content > div.row > div:nth-child(2) > div:nth-child(3) > div.col-md-9 > div:nth-child(1) > div.panel-body > span > a")

    if(idx ==0):
        worksheet = wks.get_worksheet(0);
        cell_list = worksheet.range(excel_style(int(1000), int(idx)) + ':' + excel_style(int(26000), int(idx)))
        pos = 1000
        problist = []
        for n in range(0, len(num), 2):
            # print(num[n].get_text(), num[n + 1].get_text())
            probNum = int(num[n].get_text())
            if (probNum > pos):
                while (probNum > pos):
                    problist.append(0)
                    pos = pos + 1
            if (probNum == pos):
                problist.append(1)
                pos = pos + 1
        # print(problist)

        for i, val in enumerate(problist):
            cell_list[i].value = val

        return cell_list

    # probDB sheet
    worksheet = wks.get_worksheet(0);
    cell_list = worksheet.range(excel_style(int(1000), int(idx)) + ':' + excel_style(int(26000), int(idx)))
    pos = 1000
    problist = []
    for n in range(0, len(num), 2):
        # print(num[n].get_text(), num[n + 1].get_text())
        probNum = int(num[n].get_text())
        if (probNum > pos):
            while (probNum > pos):
                problist.append(0)
                pos = pos + 1
        if (probNum == pos):
            problist.append(1)
            pos = pos + 1
    # print(problist)

    for i, val in enumerate(problist):
        cell_list[i].value = val

    return cell_list
    #worksheet.update_cells(cell_list)
    #time.sleep(2)


def read(obj):
    if obj == "prob":
        obj = 0
    elif obj == "user":
        obj = 1
    elif obj == "prac":
        obj = 2
    worksheet = wks.get_worksheet(int(obj))
    res = worksheet.get_all_values()
    return res


def wirteid(size):
    worksheet = wks.get_worksheet(3)
    cell_list = worksheet.range(excel_style(int(2), int(4)) + ':' + excel_style(int(3), int(4)+int(size)-1))
    i=0
    for cell in cell_list:
        if (i>=len(cell_list)/2):
            cell.value = userIDlist[i-int(len(cell_list)/2)][1]
        else:
            cell.value = userIDlist[i][0]
        i+=1
    print(cell_list)
    worksheet.update_cells(cell_list)

    worksheet = wks.get_worksheet(0)
    cell_list = worksheet.range(excel_style(int(997), int(1)) + ':' + excel_style(int(998), int(1) + int(size) - 1))
    i = 0
    for cell in cell_list:
        if (i >= len(cell_list) / 2):
            cell.value = userIDlist[i - int(len(cell_list) / 2)][1]
        else:
            cell.value = userIDlist[i][0]
        i += 1

    print(cell_list)
    cell_list()
    worksheet.update_cells(cell_list)

def grading():
    # select pracres
    worksheet = wks.get_worksheet(3);
    # 채점할 과제 선택
    for i in range(0, len(praclist)):
        print(praclist[i])
        pracres = []
        temp = []
        for t in range(0, len(userIDlist)):
            temp.append(0)

        # 그 과제의 문제 번호들 마다 ProbDB접근
        for j in range(7, len(praclist[i])):
            print(praclist[i][j])
            if (praclist[i][j] == ""):
                break
            else:
                prob = problist[int(praclist[i][j]) - 1]
                print(prob)
                for k in range(0, len(userIDlist)):
                    if (prob[k] == '1'):
                        temp[k] += 1
        print(temp)
        pracres.append(praclist[i][0])
        pracres.append(praclist[i][1])
        pracres.append(praclist[i][2])
        for j in range(0, len(userIDlist)):
            if (pracres[1] == userIDlist[j][3]):
                if (int(pracres[2]) <= int(temp[j])):
                    pracres.append("완료")
                else:
                    pracres.append("안함")
            else:
                pracres.append("-")
        print(pracres)
        cell_list = worksheet.range(excel_style(int(i) + int(4), int(1)) + ':' + excel_style(int(i) + int(4), int(40)))
        for j in range(0, len(pracres)):
            cell_list[j].value = pracres[j]
        worksheet.update_cells(cell_list)
        time.sleep(2)


# getUserIDlist
userIDlist = read("user")

#writeIDlist


for i in range(0,len(userIDlist)):
    id = userIDlist[i][0]
    idx = userIDlist[i][2]
    writeProbdb(id, idx)
    print(userIDlist[i][1])

# getPracList
praclist = read("prac")

# getProbList
problist = read("prob")

grading()

wirteid(len(userIDlist))
