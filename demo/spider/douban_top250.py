import requests
import re
import csv

def get_douban_top250(file_name):
    url = "https://movie.douban.com/top250"
    headers = {
        "user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.51 Safari/537.36 Edg/99.0.1150.36"
    }

    params = {
        "start":""
    }
    # 解决写入csv文件时出现多余空行的问题,newline=''
    f = open(file_name,mode="w",encoding="utf-8",newline='')
    csvwriter = csv.writer(f)
    title = ["name","director","year","country","type","rating","comments_num"]
    csvwriter.writerow(title)
    # 解析数据
    obj = re.compile(r'<li>.*?<div class="item">.*?<span class="title">(?P<name>.*?)</span>.*?'
                    r'<p class="">.*?导演: (?P<director>.*?)((&nbsp;&nbsp;)|/).*?<br>(?P<year>.*?)&nbsp;/&nbsp;(?P<country>.*?)&nbsp;/&nbsp;(?P<type>.*?)</p>.*?<span '
                    r'class="rating_num" property="v:average">(?P<rating>.*?)</span>.*?'
                    r'<span>(?P<num>.*?)人评价</span>',re.S)
    
    for start_id in range(0,250,25):
        params["start"] = str(int(start_id))
        resp = requests.get(url, headers=headers, params=params)
        page_content = resp.text
        
        # 开始匹配
        result = obj.finditer(page_content)
        
        for it in result:
            dic = it.groupdict()
            dic['year'] = dic['year'].strip()
            dic['type'] = dic['type'].strip()
            # print(dic.values())
            csvwriter.writerow(dic.values())
        resp.close()
    f.close()
    print("over")

if __name__ == "__main__":
    get_douban_top250("data.csv")