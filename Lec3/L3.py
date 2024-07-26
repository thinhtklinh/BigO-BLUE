# # Ex1: Devu, the Dumb Guy -> O(nlogn + n)
# n, x = map(int, input().split())
# arr = [int(num) for num in input().split()]

# arr.sort()
# total = 0
# for m in arr:
#     total += x*m
#     if x > 1:
#         x -= 1

# print(total)


# # Ex2: Chores -> O(nlogn)
# n, a, b = map(int, input().split())
# tasks = [int(num) for num in input().split()]

# tasks.sort()
# way = tasks[b] - tasks[b-1]
# print(way)


# # Ex3: Sort the Array -> O(n)
# n = int(input())
# arr = [int(num) for num in input().split()]

# le = 0
# ri = 0
# check = 0
# flag1 = 0
# flag2 = 0
# while (le < n-1 and ri < n-1 and check < n-1):
#     if not flag1 and arr[le+1] < arr[le]:
#         flag1 = 1
#         ri = le

#     if flag2 and arr[check+1] < arr[check]:
#         print("no")
#         break

#     if not flag2 and flag1 and arr[ri+1] > arr[ri]:
#         if arr[ri+1] < arr[le] or (le != 0 and arr[ri] < arr[le-1]):
#             print("no")
#             break
#         flag2 = 1
#         check = ri - 1

#     if flag2:
#         check += 1
#     elif flag1:
#         ri += 1
#     else:
#         le += 1
# else:
#     if ri == n-1 and le != 0 and arr[ri] < arr[le-1]:
#             print("no")
#     else:    
#         print("yes")
#         if not flag1:
#             print("1 1")
#         else:
#             print(le+1, ri+1)

# Ex4: GukiZ and Contest -> O(n^2)
n = int(input())
arr = [int(num) for num in input().split()]
out = []

arr2 = sorted(arr, reverse=True)
for score in arr:
    i = 0
    while i < n:
        if (arr2[i] == score):
            break
        else:
            i += 1
    out.append(str(i+1))
print(" ".join(out))

# Ex5: Pasha and Tea
n, w = map(int, input().split())
caps = [int(num) for num in input().split()]

caps.sort()

if (caps[0]*2 <= caps[n]):
    total = caps[0]*n*3 # caps[0]*n + caps[0]*2*n
else:
    total = caps[n]/2*n*3

if total > w:
    total = w
print(total)

# # Ex6: Towers
# n = int(input())
# lens = [int(num) for num in input().split()]

# if n == 1:
#     print("1 1")
# else:
#     lens.sort()
#     cnt = 1
#     maxHi = 1
#     curHi = 1

#     for i in range(n-1):
#         if lens[i+1] == lens[i]:
#             curHi += 1
#         else:
#             maxHi = max(maxHi, curHi)
#             curHi = 1
#             cnt += 1
#     maxHi = max(maxHi, curHi)
#     print(maxHi, cnt)

# # Ex7: Business Trip
# k = int(input())
# arr = [int(num) for num in input().split()]
# if k == 0:
#     print(0)
# else:
#     arr.sort(reverse=True)
#     totalH = 0
#     for i in range(12):
#         totalH += arr[i]
#         if totalH >= k:
#             print(i+1)
#             break
#     else:
#         print("-1")

# Ex8: Eight Point Sets
pairs = []
for i in range(8):
    x, y = map(int, input().split())
    pairs.append((x,y))

pairs.sort()
x = 0
for i in range(8):
    if i == 0 or i == 3 or i == 5:
        x = pairs[i][0]
    else:
        if pairs[i][0] != x:
            print("ugly")
            break
    if (i == 3 or i == 5) and pairs[i][1] != pairs[0][1]:
        print("urly")
        break
    if (i == 6) and pairs[i][1] != pairs[1][1]:
        print("urly")
        break
    if (i == 4 or i == 7) and pairs[i][1] != pairs[2][1]:
        print("urly")
        break
else:
    print("respectable")