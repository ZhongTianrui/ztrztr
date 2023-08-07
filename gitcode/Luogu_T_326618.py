y, k = map(int,input().split())
if len(str(k)) <= 12 :
    print(abs(100000000000 + y - k))

else :
    print(abs(999999000000 + y - k))