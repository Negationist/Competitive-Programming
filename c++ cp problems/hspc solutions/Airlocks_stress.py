import itertools
import sys


MAX_N = 7
MAX_CNT = 3
MAX_SUM = 9


def brute(cnt):
    total = sum(cnt)
    vals = []
    for i, c in enumerate(cnt):
        vals.extend([i] * c)

    ans = 0
    for perm in set(itertools.permutations(vals)):
        if all(abs(perm[i] - perm[(i + 1) % total]) == 1 for i in range(total)):
            ans += 1
    return ans


def generate_cases():
    for n in range(1, MAX_N + 1):
        for cnt in itertools.product(range(1, MAX_CNT + 1), repeat=n):
            if sum(cnt) <= MAX_SUM:
                yield list(cnt)


def main():
    limit = int(sys.argv[1]) if len(sys.argv) > 1 else None
    printed = 0

    for cnt in generate_cases():
        print(len(cnt))
        print(" ".join(map(str, cnt)))
        print(brute(cnt))
        printed += 1
        if limit is not None and printed >= limit:
            break


if __name__ == "__main__":
    main()
