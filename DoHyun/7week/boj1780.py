N=int(input())
field=[]
for i in range(N):field.append(list(map(int,input().split())))
result={-1:0,0:0,1:0}

def allSame(y,x,num):
    for i in range(y,y+num):
        for j in range(x,x+num):
            if field[y][x]!=field[i][j]:return False
    return True

def check1Case(y,x,num):
    
    #종이가 모두 같은 경우 basecondition
    if(allSame(y,x,num)):
        result[field[y][x]]+=1
        return 
    #종이가 3x3인데 모두 같지 않은경우 basecondition
    elif num==1:
        for i in range(y,y+num):
            for j in range(x,x+num):result[field[i][j]]+=1
        return
    #종이가 다른 경우
    else:
        for i in range(3):
            for j in range(3):
                check1Case(y+i*num//3,x+j*num//3,num//3)
        
check1Case(0,0,N)
print(f"{result[-1]}\n{result[0]}\n{result[1]}")




        