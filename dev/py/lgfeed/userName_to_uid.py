from fastapi import APIRouter
from peewee import fn
from db import get_connection, models
import requests

db = get_connection()

app = APIRouter()


@app.get("/blackHistory/feed/{uid}")
async def get_history_feed(uid: int, per_page: int = 100, page: int = 1):
    response = []
    current_color = "Unknown"
    for feed in (
        models.Feed.select(
            models.Feed.id,
            models.Feed.username,
            models.Feed.user_color,
            models.Feed.content,
            models.Feed.time,
            models.Feed.grub_time,
        )
        .where(models.Feed.user_id == uid)
        .offset((page - 1) * per_page)
        .limit(per_page)
        .order_by(-models.Feed.time)
    ):
        current_color = feed.user_color
        response.append(
            {
                "id": feed.id,
                "name": feed.username,
                "time": feed.time,
                "content": feed.content,
                "grab_time": feed.grub_time,
            }
        )
    return {"user_color": current_color, "feeds": response}


@app.get("/blackHistory/usernames/{uid}")
async def get_history_username(uid: int):
    response = []
    is_visit = {}
    for feed in models.Feed.select(
        models.Feed.username,
    ).where(models.Feed.user_id == uid):
        if is_visit.get(feed.username) is None:
            response.append(feed.username)
            is_visit[feed.username] = 1
    return response


@app.get("/blackHistory/uids/{username}")
async def get_history_username_from(username: str):
    import requests
    username = input()
    headers = {
        'User-Agent':'Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/86.0.4240.75 Mobile Safari/537.36'
    }
    url = "https://www.luogu.com.cn/api/user/search"
    param = {
        "keyword" : username
    }
    response = requests.get(url=url,params=param,headers=headers)
    res = response.json()["users"]
    if res[0] is None :
        uid = 0
    else :
        uid = res[0]["uid"]
    response = []
    is_visit = {}
    for feed in models.Feed.select(
        models.Feed.username,
    ).where(models.Feed.user_id == uid):
        if is_visit.get(feed.username) is None:
            response.append(feed.username)
            is_visit[feed.username] = 1
    return response
