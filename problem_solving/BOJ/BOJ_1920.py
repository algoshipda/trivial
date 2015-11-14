n=input()
a=set(map(int,raw_input().split()))
m=input()
b=map(int,raw_input().split())
ans=[]
for x in b:
	ans.append(1 if x in a else 0)
print '\n'.join(map(str,ans))
