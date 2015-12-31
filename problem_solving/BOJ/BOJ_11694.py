n=input()
a=map(int,raw_input().split())
x=0
for k in a:
	x^=k-1
print x
