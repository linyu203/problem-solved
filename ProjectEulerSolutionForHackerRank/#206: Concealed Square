This problem is a programming version of Problem 206 from projecteuler.net
https://www.hackerrank.com/contests/projecteuler/challenges/euler206




Find the unique positive integer whose square's decimal representation has the form


where  are known single digits and  are unknown single digits.

In other words, find the unique positive integer when given the every other digit of its square, starting with the first digit and including the last digit of the square.

Input Format

The first line contains a single positive integer  denoting the number of the known digits.

The second line contains the list of single-space separated known digits.

It is guaranteed that the answer exists and it is unique.

Constraints

 as the number of known digits;
The first known digit cannot be zero.
Output Format

On a single line print the answer.

Sample Input 0

3
8 7 6
Sample Output 0

286
Explanation 0

We need to find a positive integer whose square has the form  where each  is a single unknown digit. It is easy to validate that


Therefore the answer is .

Sample Input 1

4
1 2 3 4
Sample Output 1

1312
Explanation 1

We are looking for a positive integer whose square has the form . Given the total number of the digits in the square, we can speculate that the answer is an integer less than . Exhaustive search shows that


Therefore the answer is .





=====code=====

import math
from operator import mod

def checkval(N, str2,base):
    str1 = str(N)
    #print(str1,str2)
    #print(len(str1),len(str2))
    if len(str1) !=  len(str2):
        return -1
    i = int(base) +2;
    l = len(str1)
    if(str1[l-i] != str2[l-i]):
        return -1;
    i += 2;
    while i <= l:
        if str2[l-i] != str1[l-i] :
            return 1
        if(i == l):
            return 0;
        i += 2;
    return 1;

def Solve(N,tar):  
    #From = int(math.sqrt(N));
    #print(N,tar);
    l = len(tar)
    j = int(tar[l-1])
    ends = 1
    while(j == 0):
        #print(tar)
        l -= 2;
        j = int(tar[l-1])
        tar = tar[0:l]
        ends *= 10
        N /= 10
    arr = [];
    if(j == 5):
        arr.append(5)
    elif (j != 6):
        t = int(math.sqrt(j));
        arr.append(t);
        arr.append(10-t);
    else:
        arr.append(4);
        arr.append(6);
    base = 10
    i = 1;
    st = 0;
    while i <= l:
        cnt = len(arr);
        j = N
        while(int(j/(100*base)) == int(N/(100*base))):
            temp = (int(j/base))*base
            for k in range(st,cnt):
                nr = temp + arr[k];
                res = checkval(nr * nr,tar,i);
                if res == 0:
                    print(nr*ends)
                    return 0
                elif res > 0:    
                    #print(nr);
                    arr.append(mod(nr,(base*100)))
            j+=base
        st = cnt
        i += 2
        base *= 100
        #print(nr)

n = int(input())
sstr = str(input())
i = int(sstr[0])
i = int(math.sqrt(i))
i = i*(10**(n-1))

Solve(i,sstr)
