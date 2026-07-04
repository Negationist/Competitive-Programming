# PB: 79.30525159835815 20/20
import random, time
randint = random.randint

starttime = time.time()
pnl = 0
poten = 0
realcorrect = 0
correct = 0
potencorrect = 0
cases = [1]*3 + [3, 4]*3 + [5]*7 + [7, 10]*2
random.shuffle(cases)
for case in cases:
    ev = randint(1, 50)
    bid, ask = [randint(1, 50), randint(1, 50)]
    size = randint(1, 50)
    prevpnl = pnl
    prevpoten = poten
    if case in [1, 2]:
        bid, ask = sorted([bid, ask])
        print("ev:", ev)
        print("a trader says:")
        print(f"{bid} at {ask}, {size} up")
        act = input()
        if act and act[0] == "s":
            print("you sold", size, "shares at price", bid)
            pnl += size*(bid-ev)
        elif act and act[0] in ["b", "t"]:
            print("you bought", size, "shares at price", ask)
            pnl += size*(ev-ask)
        else:
            print("you did not take an action")
            print("pnl: 0")
            print(f"hypothetical buy pnl: {size*(ev-ask)},", "sell pnl:", size*(bid-ev))
        poten += max(0, size*(bid-ev), size*(ev-ask))
    elif case in [3]:
        print("ev:", ev)
        print("a trader says:")
        print(bid, "for", size)
        act = input()
        if act and act[0] == "s":
            print("you sold", size, "shares at price", bid)
            pnl += size*(bid-ev)
        else:
            print("you did not take an action")
            print("pnl: 0")
            print("if sold, pnl would have been", size*(bid-ev))
        poten += max(0, size*(bid-ev))
    elif case in [4]:
        print("ev:", ev)
        print("a trader says:")
        print(size, "at", ask)
        act = input()
        if act and act[0] in ["b", "t"]:
            print("you bought", size, "shares at price", ask)
            pnl += size*(ev-ask)
        else:
            print("you did not take an action")
            print("pnl: 0")
            print("if bought, pnl would have been", size*(ev-ask))
        poten += max(0, size*(ev-ask))
    elif case in [5, 6]:
        bid, ask = sorted([bid, ask])
        print("ev:", ev)
        print(f"make a trade; spread: [{bid}, {ask}]")
        print("max size:", size)
        act = input()
        try:
            a, b, c = act.split(" ")
            if b == "for":
                mybid = int(a)
                mysize = int(c)
                if mybid < ask:
                    print("bid not good enough")
                elif mysize > size:
                    print("size too large")
                else:
                    print("you bought", mysize, "shares at price", mybid)
                    pnl += mysize*(ev-mybid)
            elif b == "at":
                myask = int(c)
                mysize = int(a)
                if myask > bid:
                    print("ask not good enough")
                elif mysize > size:
                    print("size too large")
                else:
                    print("you sold", mysize, "shares at price", myask)
                    pnl += mysize*(myask-ev)
        except:
            print("invalid trade format, did not go through" if act else "you did not take an action")
        print(f"hypothetical buy pnl: {size*(ev-ask)}, sell pnl: {size*(bid-ev)}")
        poten += max(0, size*(ev-ask), size*(bid-ev))
    elif case in [7, 8, 9, 10]:
        if case == 7:
            print("Transaction Cap: 1")
        elif case == 8:
            print("Transaction Cap: 2")
        elif case == 9:
            print("Transaction Cap: 3")
        elif case == 10:
            print("Transaction Cap: Unlimited")
        print(f"ev: {ev}")
        tradect = 4
        trades = [sorted([randint(1, 50), randint(1, 50)]) for i in range(tradect)]
        sizes = [min(randint(1, 50), randint(1, 50)) for i in range(tradect)]
        types = [["buy", "sell", "both"][randint(0, 2)] for i in range(tradect)]
        for i in range(tradect):
            bid = trades[i][0]
            ask = trades[i][1]
            size = sizes[i]
            ticker = chr(i+97)
            if types[i] == "buy":
                print(f"{ticker}: {bid} for {size}")
            elif types[i] == "sell":
                print(f"{ticker}: {size} at {ask}")
            elif types[i] == "both":
                print(f"{ticker}: {bid} at {ask}, {size} up")
        acts = input()
        if acts:
            used = set()
            data = acts.split(",")
            if case == 7:
                data = [data[0]]
            if case == 8:
                data = data[0:2]
            if case == 9:
                data = data[0:3]
            for act in data:
                try:
                    action, a = act.strip().split(" ")
                    num = ord(a)-97
                    assert 0 <= num < tradect
                    if num in used:
                        print("duplicate instrument")
                        continue
                    used.add(num)
                except:
                    print("invalid trade format, did not go through")
                    continue
                bid = trades[num][0]
                ask = trades[num][1]
                size = sizes[num]
                typ = types[num]
                try:
                    if typ == "buy":
                        assert action[0] == "s"
                    elif typ == "sell":
                        assert action[0] in ["b", "t"]
                except AssertionError:
                    print("invalid trade, did not go through")
                    continue
                if action[0] == "s":
                    print("you sold", size, "shares at price", bid)
                    print("--> PNL:", size*(bid-ev))
                    pnl += size*(bid-ev)
                elif action[0] in ["b", "t"]:
                    print(f"you bought {size} shares at price {ask}")
                    print("--> PNL:", (ev-ask)*size)
                    pnl += (ev-ask)*size
        print("Profitable hypothetical trades:")
        outcomes = []
        for num in range(tradect):
            bid = trades[num][0]
            ask = trades[num][1]
            size = sizes[num]
            typ = types[num]
            if typ in ["buy", "both"]:
                if size*(bid-ev) > 0:
                    outcomes.append(("sold", chr(num+97), "->", size*(bid-ev)))
            if typ in ["sell", "both"]:
                if (ev-ask)*size > 0:
                    outcomes.append(("take", chr(num+97), "->", (ev-ask)*size))
        outcomes.sort(key=lambda x: -x[3])
        print(" | ".join([" ".join(map(str, out)) for out in outcomes]))
        bpa = sum(i[3] for i in outcomes[0:[1,2,3,tradect*3][case-7]])
        print("Best possible:", 0 if bpa == 0 else "+"+str(bpa))
        poten += bpa

    potencorrect += 1
    if (pnl-prevpnl) > 0 or (pnl==prevpnl and (poten-prevpoten) == 0): correct += 1
    if (poten-prevpoten) == (pnl-prevpnl): realcorrect += 1
    print(f"-->     DELTA: {'+' if pnl>prevpnl else ''}{pnl-prevpnl} / {'+' if poten>prevpoten else ''}{poten-prevpoten}")
    print(f"--> TOTAL PNL: {pnl} / {poten}")
    print(f"-->  ACCURACY: {realcorrect} / {potencorrect}")
    # print(f"-->      SIGN: {correct} / {potencorrect}")
    print(f"--> TIME USED: {(time.time()-starttime)}\n")