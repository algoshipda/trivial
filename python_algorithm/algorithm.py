def next_permutation(a):
	for k in xrange(len(a)-2,-1,-1):
		if a[k] < a[k+1]: break
	else:
		return False
	for l in xrange(len(a)-1, k,-1):
		if a[k] < a[l]: break
	a[k],a[l]=a[l],a[k]
	a[k+1:]=a[k+1:][::-1]
	return True
	
def prev_permutation(a):
	for k in xrange(len(a)-2,-1,-1):
		if a[k] > a[k+1]: break
	else:
		return False
	for l in xrange(len(a)-1, k,-1):
		if a[k] > a[l]: break
	a[k],a[l]=a[l],a[k]
	a[k+1:]=a[k+1:][::-1]
	return True