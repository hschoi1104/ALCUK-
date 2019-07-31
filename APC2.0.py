import requests
from bs4 import BeautifulSoup
from oauth2client.service_account import ServiceAccountCredentials
import gspread
import time
def excel_style(row, col):
    #http://code.activestate.com/recipes/578941-spread-sheet-style-column-enumeration-letter-to-nu/
    """ Convert given row and column number to an Excel-style cell name. """
    quot, rem = divmod(col-1, 26)
    return((chr(quot-1 + ord('A')) if quot else '') +
           (chr(rem + ord('A')) + str(row)))

def writeProbdb(id,idx):
    # bs4
    res = requests.get('https://www.acmicpc.net/user/' + id)
    soup = BeautifulSoup(res.content, 'html.parser')

    num = soup.select(
        "body > div.wrapper > div.container.content > div.row > div:nth-child(2) > div:nth-child(3) > div.col-md-9 > div:nth-child(1) > div.panel-body > span > a")

    # open and select worksheet
    wks = gc.open_by_key('--gspread ID--')
    # probDB sheet
    worksheet = wks.get_worksheet(0);
    cell_list = worksheet.range(excel_style(int(1000), int(idx))+':'+excel_style(int(26000), int(idx)))
    pos = 1000
    problist = []
    for n in range(0, len(num), 2):
        print(num[n].get_text(), num[n + 1].get_text())
        probNum = int(num[n].get_text())
        if (probNum > pos):
            while (probNum > pos):
                problist.append(0)
                pos = pos + 1
        if (probNum == pos):
            problist.append(1)
            pos = pos + 1
    print(problist)

    for i, val in enumerate(problist):
        cell_list[i].value = val

    worksheet.update_cells(cell_list)
    time.sleep(2)

def readUserID():
    # open and select worksheet
    wks = gc.open_by_key('--gspread ID--')
    # probDB sheet
    worksheet = wks.get_worksheet(1);

    res = worksheet.get_all_values()
    return res

#__init__
# set oauth
scope = ['https://spreadsheets.google.com/feeds',
         'https://www.googleapis.com/auth/drive']
credentials = ServiceAccountCredentials.from_json_keyfile_name('ALCUKPracticeChecker.json', scope)
gc = gspread.authorize(credentials)

#getUserIDlist
userIDlist = readUserID()

for i in range(30,len(userIDlist)):
    id = userIDlist[i][0]
    idx = userIDlist[i][2]
    writeProbdb(id, idx)


