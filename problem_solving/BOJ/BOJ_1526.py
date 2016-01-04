a=input()

while True:
	x=map(int,str(a))
	if x.count(4)+x.count(7)==len(x):
		print a
		break
	a-=1
