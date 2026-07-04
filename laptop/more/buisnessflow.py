import numpy as np
from scipy.optimize import linprog

n, e, p = map(int, input().split())
fact = [None] * p
ware = [None] * p
d = [None] * p
for i in range(p):
    f, w, demand = map(int, input().split())
    fact[i] = f
    ware[i] = w
    d[i] = demand
adj = [[] for i in range(n)]
in_adj = [[] for i in range(n)]
m = {}
cap = {}
inc = 0
for i in range(e):
    u, v, capacity = map(int, input().split())
    adj[u].append((v,capacity))
    in_adj[v].append((u,capacity))
    cap[(u,v)] = capacity
    for j in range(p):
        m[(u,v,j)] = inc
        inc+=1
A_ineq = []
A_eq = []
b_ineq = []
b_eq = []
for u,v in cap:
    row = [0] * inc
    for j in range(p):
        row[m[(u,v,j)]] = 1
    A_ineq.append(row)
    b_ineq.append(cap[(u,v)])
for prod in range(p):
    for j in range(n):
        row = [0] * inc
        rhs = None
        for dest, capacity in adj[j]:
            row[m[(j,dest,prod)]] = 1
        for source, capacity in in_adj[j]:
            row[m[(source,j,prod)]] = -1
        if j == fact[prod]:
            rhs = d[prod]
        elif j == ware[prod]:
            rhs = -d[prod]
        else:
            rhs = 0
        A_eq.append(row)
        b_eq.append(rhs)
A_ub = np.array(A_ineq, dtype = float)
b_ub = np.array(b_ineq, dtype = float)
A_equality = np.array(A_eq, dtype = float)
b_equality = np.array(b_eq, dtype = float)
bounds = [(0, None)] * inc
c = np.zeros(inc)
res = linprog(
    c,
    A_ub=A_ub, b_ub=b_ub,
    A_eq=A_equality, b_eq=b_equality,
    bounds=bounds,
    method="highs"
)
if res.success:
    print("Yes")
else:
    print("No")

