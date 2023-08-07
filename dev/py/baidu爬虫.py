import requests
from bs4 import BeautifulSoup
keyword = input("请输入搜索关键字：")
url = "http://www.baidu.com/s?wd=" + keyword
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3"}
response = requests.get(url, headers=headers)
html = response.content.decode()
soup = BeautifulSoup(html, 'html.parser')
results = soup.find_all('div', class_='result c-container ')
for result in results:
    title = result.h3.a.text.strip()
    link = result.h3.a['href']
    abstract = result.find('div', class_='c-abstract').text.strip()
    print(title)
    print(link)
    print(abstract)
    print()