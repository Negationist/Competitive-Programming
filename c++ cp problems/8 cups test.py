import random

def check(temp):
    for i in range(1, len(temp)):
        if (abs(temp[i] - 1.0)) > 1e-18:
            return False
    return True
n=8
with open('output.txt', 'a') as f:
    times = 1
    total = 0
    for i in range(times):
        buckets = [0.0]*n
        buckets[0] = n
        cnt = 0
        while not check(buckets):
            indices = random.sample(range(len(buckets)), 2) 
            avg = (buckets[indices[0]] + buckets[indices[1]])/2
            buckets[indices[0]] = avg
            buckets[indices[1]] = avg
            cnt += 1
            print(n, buckets, cnt, indices[0], indices[1])
        f.write(f"{cnt}\n")
        total += cnt
    print(total, total/times)