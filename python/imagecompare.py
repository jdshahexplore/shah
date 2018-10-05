import cv2
import sys
sys.setrecursionlimit(50000)
image = cv2.imread("C:\\Users\\saura\\Desktop\\white.jpg")
image1 = cv2.imread("C:\\Users\\saura\\Desktop\\white1.jpg")
flag=1
def check(s,e,n,m):
    global flag
    if flag==0:
        return
    if s<n:
        r=int(s+int((n-s))/2)
    else:
        r=int(s)
    if e<m:
        c=int(e+int((m-e))/2)
    else:
        c=int(e)
    #print(r,c)
    if s==r and e==c:
        if image[r][c]!=image1[r][c]:
            flag=0
        return
    check(s,e,r,c)
    check(r,c,n-1,m-1)
    check(r,e,n,c)
    check(s,c,r,m)


image=cv2.cvtColor(image,cv2.COLOR_BGR2GRAY)
image1=cv2.cvtColor(image1,cv2.COLOR_BGR2GRAY)
a,b=image.shape
c,d=image1.shape
a=min(a,b,c,d)
image=cv2.resize(image,(a,a))
image1=cv2.resize(image1,(a,a))
check(0,0,a,a)
if flag==1:
    print("yes")
else:
    print("no")
