import math;

if __name__ == '__main__':
    print('input Um s')
    x = map(float,input().split(' '))
    print(list(map(lambda x: 0.103 * x,x)))

    # a = list(map(float,input().split(' ')))
    
    # for x in range(0,len(a)):
    #     print(a[x]*17.5)