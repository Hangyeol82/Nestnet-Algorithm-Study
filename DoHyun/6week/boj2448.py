N=int(input())

def StarFunc(num):
    if num==3:
        base=['  *  ',' * * ','*****']
        return base

    smallNum = num // 2
    small = StarFunc(smallNum)
    result = []

    for line in small:result.append(' ' * smallNum + line + ' ' * smallNum)
    for line in small:result.append(line + ' ' + line)

    return result



print('\n'.join(StarFunc(N)))