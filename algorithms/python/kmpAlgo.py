# -*- coding: utf-8 -*-
"""
@author: [Satyam Koshta] 
@details: this is the implementation of Knuth–Morris–Pratt algorithm (KMP algo)
it returns the number of substring of text that are equal to the given
pattern
@reference: for mare details visit [https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/]
"""
#  Knuth–Morris–Pratt algorithm (KMP algo) for pattern searching

# this function returns the lps (Longest proper Prefix which is also Suffix)
def getLps(string):
    length = len(string)
    lps =[0]*length
    p1 =0
    i=1
    while(i< length):
        if string[i]== string[p1]:
            p1+=1
            lps[i] = p1
            i+=1
            
        else:
            if p1!= 0:
                p1= lps[p1-1]
            else: 
                lps[i]=0
                i +=1
    return lps

#  kmp function to calculate number of substring og text equal to the pattern
def kmp(text, pattern):
    count =0;
    lenPat= len(pattern)
    lenTxt = len(text)
    lpsPat = getLps(pattern)
    i=0
    p1=0
    while( i<lenTxt):
        # print(i,p1, count)
        if(p1==lenPat):
            count+=1
            p1= lpsPat[p1-1]
        if(text[i]==pattern[p1]):
            i +=1
            p1+=1
        else:
            if(p1 !=0):
                p1 = lpsPat[p1-1]
            else:
                i+=1
        # print(i,p1, count)
        # print("________________________________")
    if(p1==lenPat):
        count+=1
    return count


# main function to check the code
def main():
    text ="kakaka"
    pattern ="aka"
    print(kmp(text, pattern))


if __name__ == '__main__':
    main()
