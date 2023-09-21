i=int(input())
l= [0*x for x in range(i)]          #l is the list of the numbers of the best path

l[0],l[1]=1,2                       #the first two numbers of the best path
o,e=3,2                             #o is the odd number, e is the even number
for f in range (2,i):               #f is the position of the number in the best path
    if f%2==0:
        l[f]=l[f-1]+o               #the number is the previous number plus the odd number
        o=o+2                       #the odd number increases by 2
    elif f%2==1: 
        l[f]=l[f-1]+e               #the number is the previous number plus the even number
        e=e+1                       #the even number increases by 1


        
def sign(pos,x):                    #pos is the position of the number in the best path, x is the number
    a=pos%4                         #a is the remainder of pos divided by 4
    if a==1 or a==0: 
        return s[x-l[pos]]          #the sign is the same as the sign of the previous number
    elif a==2 or a==3: 
        return -s[x-l[pos]]         #the sign is the opposite of the sign of the previous number


def times(x):                       #x is the number
    t=0
    for i in l:                     #i is the number in the best path
        if i<=x:
            t=t+1                   #t is the position of the number in the best path
    return t
    
    
s=[0*x for x in range(i)]           #s is the list of the signs of the numbers in the best path
s[0],s[1]=1,1                       #the first two numbers in the best path have the same sign

for x in range(2,i):                #x is the number in the best path
    t=times(x)
    w=0
    for y in range(t):              #y is the position of the number in the best path
        w=w+sign(y,x)
    s[x]=w

print (s)                           #the list of the signs of the numbers in the best path
