N=int(input())

def MakeMoo(length,k):

    print(f"S({k+1}):",length,k+3,length,)
    if N<=2*length+k+3:
        if N<=length:
            print("앞에 해당해")
            if N%3==1:
                print('m')
                return
            else:
                print('o')
                return
        elif length<N<=length+k+3:
            print("중간에 해당해")
            if N==length+1:
                print('m')
                return
            else:
                print('o')
                return
        else:
            print("뒤에 해당해")
            if (N-(length+k+3))%3==1:
                print('m')
                return
            else:
                print('o')
                return
    MakeMoo(2*length+k+3,k+1)

if N<=10: print(['m','o','o','m','o','o','o','m','o','o'][N-1])
else:MakeMoo(3,1)
#S(2) 10 5 10
#S(3) 25 6 25
#S(4) 56 7 56
#S(5) 106 8 106