total_words = 4

def highPart(regA, regB, regDst, words, offset):
    direction = 0
    regLoad = 0
    limit = words-1

    print("HighPart: ")

    for i in range (0, 2*words-1):
        if i > limit:
            for j in range (i-limit, limit+1):
                if direction == 0:
                    if regLoad == 1:
                        #print("	regLoadMultiply " + regB + "," + str(offset+j))
                        print("	loadMultiply " + regB + "," + regA + "," + str(offset+j) + "," + str(offset+i-j))
                        regLoad = 0
                    else:
                        print("	loadMultiply " + regB + "," + regA + "," + str(offset+j) + "," + str(offset+i-j))
                else:
                    if regLoad == 1:
                        #print("	regLoadMultiply " + regA + "," + str(offset+j))
                        print("	loadMultiply " + regA + "," + regB + "," + str(offset+j) + "," + str(offset+i-j))
                        regLoad = 0
                    else:
                        print("	loadMultiply " + regA + "," + regB + "," + str(offset+j) + "," + str(offset+i-j))

        else:
            for j in range (0, i+1):
                if direction == 0:
                    if regLoad == 1:
                        #print("	regLoadMultiply " + regA + "," + str(offset+i-j))
                        print("	loadMultiply " + regA + "," + regB + "," + str(offset+i-j) + "," + str(offset+j))
                        regLoad = 0
                    else:
                        print("	loadMultiply " + regA + "," + regB + "," + str(offset+i-j) + "," + str(offset+j))
                else:
                    if regLoad == 1:
                        #print("	regLoadMultiply " + regB + "," + str(offset+i-j))
                        print("	loadMultiply " + regB + "," + regA + "," + str(offset+i-j) + "," + str(offset+j))
                        regLoad = 0
                    else:
                        if i == words-1:
                            print("	loadMultiply " + regA + "," + regB + "," + str(offset+j) + "," + str(offset+i-j))
                        else:
                            print("	loadMultiply " + regB + "," + regA + "," + str(offset+i-j) + "," + str(offset+j))

        if i == (2*words-2):
            print("	storeRemAcc " + regDst + ", " + str(2*offset+i) + ", " + str(2*offset+i+1))
        else: 
            print("	storeAndShiftAcc " + regDst + ", " + str(2*offset+i))
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
                        #print("	regLoadMultiply " + regB + "," + str(offset+j))
                        print("	loadMultiply " + regB + "," + regA + "," + str(offset+j) + "," + str(offset+i-j))
                        regLoad = 0
                    else:
                        print("	loadMultiply " + regB + "," + regA + "," + str(offset+j) + "," + str(offset+i-j))
                else:
                    if regLoad == 1:
                        #print("	regLoadMultiply " + regA + "," + str(offset+j))
                        print("	loadMultiply " + regA + "," + regB + "," + str(offset+j) + "," + str(offset+i-j))
                        regLoad = 0
                    else:
                        print("	loadMultiply " + regA + "," + regB + "," + str(offset+j) + "," + str(offset+i-j))

        else:
            for j in range (0, i+1):
                if direction == 0:
                    if regLoad == 1:
                        #print("	regLoadMultiply " + regA + "," + str(offset+i-j))
                        print("	loadMultiply " + regA + "," + regB + "," + str(offset+i-j) + "," + str(offset+j))
                        regLoad = 0
                    else:
                        print("	loadMultiply " + regA + "," + regB + "," + str(offset+i-j) + "," + str(offset+j))
                else:
                    if regLoad == 1:
                        print("	loadMultiply " + regB + "," + regA + "," + str(offset+i-j) + "," + str(offset+j))
                        #print("	regLoadMultiply " + regB + "," + str(offset+i-j))
                        regLoad = 0
                    else:
                        if i == words-1:
                            print("	loadMultiply " + regA + "," + regB + "," + str(offset+j) + "," + str(offset+i-j))
                        else:
                            print("	loadMultiply " + regB + "," + regA + "," + str(offset+i-j) + "," + str(offset+j))


        if i > limit:
            if i == (2*words-2):
                print("	storeRemAcc " + regDst1 + ", " + str(4+2*offset+i) + ", " + str(4+2*offset+i+1))
            else: 
                print("	storeAndShiftAcc " + regDst1 + ", " + str(4+2*offset+i))
        else:
            print("	storeAndShiftAcc " + regDst0 + ", " + str(2*offset+i))
        print("")
        direction = 1-direction
        regLoad = 1

def middlePart(regA, regB, regRes, regCarryA, regCarryB, words, offsetRegA, offsetRegB, offsetHigh):
    direction = 0
    limit = words-1

    print("middlePart: ")

    for i in range (0, 2*words):
        if i > limit:
            print("	loadAndAddIfCarry  " + regCarryA + ", " + regB + ", " + str(int(offsetRegB+i-words)))
            print("	loadAndAddIfCarry " + regCarryB + ", " + regA + ", " + str(int(offsetRegA+i-words)))
            print("	loadAndAdd " + regRes + "," + str(int((offsetHigh+i-words))))
            print("	loadAndSub " + regRes + "," + str(int(offsetHigh+i)))
            print("	loadAndSub sp," + str(4+int(i)))
            for j in range (i-limit, limit+1):
                print("	loadMultiply " + regA + "," + regB + "," + str(offsetRegA+i-j) + "," + str(offsetRegB+j))
        else:
            print("	loadAndAdd sp, " + str(int(i+2*words)))                   	       # existing part
            print("	loadAndSub " + regRes + "," + str(int(offsetHigh+i)))                  # +High
            print("	loadAndSub " + regRes + "," + str(i))              	               # +Low
            for j in range (0, i+1):
                print("	loadMultiply " + regA + "," + regB + "," + str(offsetRegA+i-j) + "," + str(offsetRegB+j))

        print("	storeAndShiftAcc " + regRes + "," + str(int(words+i)))
        print("")

def propagateAccumulator(regRes, words, offset):
    print("	addCarries")
    #print("	storeAndShiftAcc16 " + str(offset16))

    
    for i in range(offset, 2*words):
        print("	loadRegAndAdd " + regRes + "," + str(i))
        print("	str r5, [" + regRes + ", #" + str(i) + "*4]")

highPart("r8", "r9", "r10", int(total_words/2), int(total_words/2))
lowPart("r8", "r9", "r10", "sp", int(total_words/2), 0)
middlePart("sp", "sp", "r10", "r11", "r12", int(total_words/2), 0, int(total_words/2), total_words)
propagateAccumulator("r1", int(total_words), 12)
