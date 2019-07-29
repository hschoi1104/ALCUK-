import requests
from bs4 import BeautifulSoup
from oauth2client.service_account import ServiceAccountCredentials
import gspread
import time
#set oauth
scope = ['https://spreadsheets.google.com/feeds',
         'https://www.googleapis.com/auth/drive']
credentials = ServiceAccountCredentials.from_json_keyfile_name('ALCUKPracticeChecker.json', scope)
gc = gspread.authorize(credentials)

#bs4
res = requests.get('https://www.acmicpc.net/user/hschoi1104')
soup = BeautifulSoup(res.content, 'html.parser')

num = soup.select("body > div.wrapper > div.container.content > div.row > div:nth-child(2) > div:nth-child(3) > div.col-md-9 > div:nth-child(1) > div.panel-body > span > a")

#open and select worksheet
wks = gc.open_by_key('1lINh9fp9g0djublzIXbCrlAUFtgpNgyby8BWYMBImwc')
# probDB sheet
worksheet = wks.get_worksheet(0);

cell_list=worksheet.range('A1000:A26000')
pos = 1000
problist=[]
for n in range(0,len(num),2):
    print(num[n].get_text(), num[n+1].get_text())
    probNum = int(num[n].get_text())
    if(probNum>pos):
        while(probNum>pos):
            problist.append(0)
            pos = pos + 1
    if(probNum == pos):
        problist.append(1)
        pos = pos + 1
print(problist)

for i,val in enumerate(problist):
    cell_list[i].value =val

worksheet.update_cells(cell_list)
time.sleep()
