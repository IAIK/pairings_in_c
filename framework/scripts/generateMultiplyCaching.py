words = 8
offset = 8
limit = words-1
regA = "r1"
regB = "r2"
direction = 0
regLoad = 0

for i in range (0, 2*words-1):
	if i > limit:
		for j in range (i-limit, limit+1):
			if direction == 0:
				if regLoad == 1:
					print("regLoadMultiply " + regB + "," + str(offset+j))
					regLoad = 0
				else:
					print("loadMultiply " + regB + "," + regA + "," + str(offset+j) + "," + str(offset+i-j))
			else:
				if regLoad == 1:
					print("regLoadMultiply " + regA + "," + str(offset+j))
					regLoad = 0
				else:
					print("loadMultiply " + regA + "," + regB + "," + str(offset+j) + "," + str(offset+i-j))

	else:
		for j in range (0, i+1):
			if direction == 0:
				if regLoad == 1:
					print("regLoadMultiply " + regA + "," + str(offset+i-j))
					regLoad = 0
				else:
					print("loadMultiply " + regA + "," + regB + "," + str(offset+i-j) + "," + str(offset+j))
			else:
				if regLoad == 1:
					print("regLoadMultiply " + regB + "," + str(offset+i-j))
					regLoad = 0
				else:
					if i == words-1:
						print("loadMultiply " + regA + "," + regB + "," + str(offset+j) + "," + str(offset+i-j))
					else:
						print("loadMultiply " + regB + "," + regA + "," + str(offset+i-j) + "," + str(offset+j))

	print("storeAndShiftAcc " + str(2*offset+i))
	print("")
	direction = 1-direction
	regLoad = 1

