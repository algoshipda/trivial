a=map(int,raw_input())
cnt=[0]*9
for i in xrange(9):
	cnt[i]+=a.count(i)
cnt[6]+=a.count(9)
ans=0
ok=False
while not ok:
	ans+=1
	for i in xrange(9):
		cnt[i]-=1
	cnt[6]-=1
	ok=True
	for i in xrange(9):
		if cnt[i]>0:
			ok=False
			break
print ans
