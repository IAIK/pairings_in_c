total_words = 8

def highPart(regA, regB, words, offset):
    direction = 0
    regLoad = 0
    limit = words-1

    print("HighPart: ")

    for i in range (0, 2*words-1):
        if i > limit:
            for j in range (i-limit, limit+1):
                if direction == 0:
                    if regLoad == 1:
                        print("	regLoadMultiply " + regB + "," + str(offset+j))
                        regLoad = 0
                    else:
                        print("	loadMultiply " + regB + "," + regA + "," + str(offset+j) + "," + str(offset+i-j))
                else:
                    if regLoad == 1:
                        print("	regLoadMultiply " + regA + "," + str(offset+j))
                        regLoad = 0
                    else:
                        print("	loadMultiply " + regA + "," + regB + "," + str(offset+j) + "," + str(offset+i-j))

        else:
            for j in range (0, i+1):
                if direction == 0:
                    if regLoad == 1:
                        print("	regLoadMultiply " + regA + "," + str(offset+i-j))
                        regLoad = 0
                    else:
                        print("	loadMultiply " + regA + "," + regB + "," + str(offset+i-j) + "," + str(offset+j))
                else:
                    if regLoad == 1:
                        print("	regLoadMultiply " + regB + "," + str(offset+i-j))
                        regLoad = 0
                    else:
                        if i == words-1:
                            print("	loadMultiply " + regA + "," + regB + "," + str(offset+j) + "," + str(offset+i-j))
                        else:
                            print("	loadMultiply " + regB + "," + regA + "," + str(offset+i-j) + "," + str(offset+j))

        print("	storeAndShiftAcc16 " + str(2*offset+i))
        print("")
        direction = 1-direction
        regLoad = 1

def lowPart(regA, regB, regDst0, regDst1, words, offset):
    direction = 0
    regLoad = 0
    limit = words-1

    print("lowPart: ")

    for i in range (0, 2*words-1):
        if i > limit:
            for j in range (i-limit, limit+1):
                if direction == 0:
                    if regLoad == 1:
                        print("	regLoadMultiply " + regB + "," + str(offset+j))
                        regLoad = 0
                    else:
                        print("	loadMultiply " + regB + "," + regA + "," + str(offset+j) + "," + str(offset+i-j))
                else:
                    if regLoad == 1:
                        print("	regLoadMultiply " + regA + "," + str(offset+j))
                        regLoad = 0
                    else:
                        print("	loadMultiply " + regA + "," + regB + "," + str(offset+j) + "," + str(offset+i-j))

        else:
            for j in range (0, i+1):
                if direction == 0:
                    if regLoad == 1:
                        print("	regLoadMultiply " + regA + "," + str(offset+i-j))
                        regLoad = 0
                    else:
                        print("	loadMultiply " + regA + "," + regB + "," + str(offset+i-j) + "," + str(offset+j))
                else:
                    if regLoad == 1:
                        print("	regLoadMultiply " + regB + "," + str(offset+i-j))
                        regLoad = 0
                    else:
                        if i == words-1:
                            print("	loadMultiply " + regA + "," + regB + "," + str(offset+j) + "," + str(offset+i-j))
                        else:
                            print("	loadMultiply " + regB + "," + regA + "," + str(offset+i-j) + "," + str(offset+j))


        print("	storeAndShiftAcc16 " + str(2*offset+i))
        print("")
        if (i) == limit:
            print("	add " + regDst0 + "," + regDst1 + ",#32")
            print("")
        direction = 1-direction
        regLoad = 1

def middlePart(regA, regB, regAl, regBl, regRes, regCarryA, regCarryB, words, offsetRegA, offsetRegB, offsetHigh):
    direction = 0
    limit = words-1

    print("middlePart: ")

    for i in range (0, 2*words-1):
        if i > limit:
            for j in range (i-limit, limit+1):
                print("	loadMultiply " + regA + "," + regB + "," + str(offsetRegA+i-j) + "," + str(offsetRegB+j))
            if (i%2) == 0:
                print("	loadAndAddIfCarry  " + regCarryA + ", " + regB + ", " + str(int((offsetRegB+i-words)/2)))
                print("	loadAndAddIfCarry " + regCarryB + ", " + regA + ", " + str(int((offsetRegA+i-words)/2)))
                print("	loadAndAdd " + regRes + "," + str(int((offsetHigh+i-words)/2)))
                print("	loadAndSub " + regRes + "," + str(int((offsetHigh+i)/2)))
                print("	loadAndSub sp," + str(4+int(i/2)))
        else:
            for j in range (0, i+1):
                print("	loadMultiply " + regA + "," + regB + "," + str(offsetRegA+i-j) + "," + str(offsetRegB+j))
            #for j in range (i+words-limit, limit+1):
            #    print("loadMultiply " + regAl + "," + regBl + "," + str(i+words-j) + "," + str(j))
            if (i%2) == 0:
                print("	loadAndAdd sp, " + str(4+int((i+words)/2)))                   # existing part
                print("	loadAndSub " + regRes + "," + str(int((offsetHigh+i)/2)))              # +High
                print("	loadAndSub " + regRes + "," + str(int(i/2)))                           # +Low


        if i == 2*words-1:
            print("		storeAndShiftAcc " + regRes + "," + str(int((words+i+1)/2)))
        else: 
            print("	storeAndShiftAcc16 " + str(words+i))
        print("")
        direction = 1-direction
        regLoad = 1

def propagateAccumulator(regRes, regAl, words, offset16):
    print("	addCarries")
    #print("	storeAndShiftAcc16 " + str(offset16))

    for i in range(int((offset16+1)/2), 2*words):
        print("	loadRegAndAdd " + regAl + "," + str(i-words))
        print("	str r5, [" + regRes + ", #" + str(i-words) + "]")

highPart("r1", "r2", int(total_words/2), 8)
lowPart("r1", "r2", "r0", "sp", int(total_words/2), 0)
middlePart("r1", "r1", "r1", "r2", "r0", "r9", "r10", int(total_words/2), 0, 8, 16)
propagateAccumulator("r0", "sp", int(total_words/2), 23)
