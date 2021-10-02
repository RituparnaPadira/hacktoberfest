# -*- coding: utf-8 -*-
"""

@author: [Satyam Koshta] 
@details: this is the program to print spiral square matrix
from serial number 1 to n^2
@example:
for n = 3, result will be:  1 2 3
                            8 9 4
                            7 6 5

for n = 2, result will be:  1 2 
                            4 3

"""

# this get_spiral_matrix(n) function will return the spiral matrix of nXn
def get_spiral_matrix(n):
    # result will store our final spiral matrix content
    result=[]
    n = int(input())
    for i in range(n):
        result.append(list(range(n)))
        
    # initializing required variables
    sti =0; stj= 0; eni=n; enj =n
    count =1
    flag =0
    i=0
    while count <= n*n:
        if flag%4==0:
            i = flag//4
            for j in range(flag//4, n- flag//4):
                result[i][j] = count
                count +=1
            flag +=1
        elif flag%4==1:
            for i in range(flag//4 +1, n- flag//4):
                result[i][j] = count
                count +=1
            flag +=1
            
        elif flag%4==2:
            for j in range(n-flag//4 -2, flag//4 -1 , -1):
                result[i][j]= count
                count +=1
            flag +=1
            
        elif flag%4== 3:
            for i in range(n- flag//4 -2, flag//4 , -1):
                result[i][j] = count
                count +=1
            flag +=1
    
    return result   
    # for i in result:
    #     print(*i)