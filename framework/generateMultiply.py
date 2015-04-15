words = 32
limit = int(words/2-1)

for i in range (0, words-1):
	if i > limit:
		for j in range (i-limit, limit+1):
			print("loadMultiply " + str(i-j) + "," + str(j))
	else:
		for j in range (0, i+1):
			print("loadMultiply " + str(i-j) + "," + str(j))

	print("storeAndShiftAcc " + str(i))
	print("")
