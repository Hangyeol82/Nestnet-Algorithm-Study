N=int(input())

def StarFunc(num):
    if num==1:return ['*']
    
    smallNum=num//3
    big=StarFunc(smallNum)
    small=[]
    for i in big:small.append(i*3)
    for i in big:small.append(i+' '*smallNum+i)
    for i in big:small.append(i*3)
    return small


print('\n'.join(StarFunc(N)))