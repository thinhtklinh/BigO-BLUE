# # Ex2: Night at the Museum
# str = input()
# step = 0
# preC = 'a'
# for c in str:
#     check = abs(ord(preC) - ord(c))
#     if check > 13:
#         check = 26 - check
#     step += check
#     preC = c
# print(step)


# # Ex5: Arrays
# stuf = input()
# a, b = map(int, input().split())
# Arr = [int(num) for num in input().split()]
# Brr = [int(num) for num in input().split()]

# hi = Arr[a-1]
# lo = Brr[-b]

# if hi < lo:
#     print("YES")
# else:
#     print("NO")


## Ex6: Big Segment
# N = int(input())
# left, right = map(int, input().split())
# l, r = 0, 0

# for i in range(1, N):
#     a, b = map(int, input().split())
#     if a < left:
#         left = a
#         l = i
#     if b > right:
#         right = b
#         r = i
#     if r == i and a == left:
#         l = i
#     if l == i and b == right:
#         r = i
#     if a == left and b == right:
#         r = l = i

# if l == r:
#     print(l+1)
# else:
#     print(-1)


## Ex7: Passwords
# n, k = map(int, input().split())
# passlen = dict()
# for i in range(n):
#     passwd = input()
#     if len(passwd) not in passlen.keys():
#         passlen[len(passwd)] = 1
#     else:
#         passlen[len(passwd)] += 1

# realPas = input()
# length = len(realPas)
# minT = maxT = 0
# wrong = 0

# for l in passlen.keys():
#     if l < length:
#         minT += passlen[l]
#         wrong += passlen[l]
#         if wrong >= k:
#             minT += 5 * int(wrong / k)
#             wrong = wrong % k

# maxT = minT

# maxT += passlen[length]
# wrong += passlen[length] - 1
# if wrong >= k:
#     maxT += 5 * int(wrong / k)

# minT += 1

# print(minT, maxT)


## Ex8: Suffix Structures
s = input()
t = input()

if t in s:
    print("automaton")
else:
    dicS = dict()
    dicT = dict()
    for c in s:
        if c not in dicS.keys():
            dicS[c] = 1
        else:
            dicS[c] += 1
    for c in t:
        if c not in dicT.keys():
            dicT[c] = 1
        else:
            dicT[c] += 1
    if len(t) == len(s) and dicT == dicS:
        print("array")
    elif len(t) < len(s) and (set(dicT.keys()) <= set(dicS.keys())):
        for c in dicT.keys():
            if (dicT[c] > dicS[c]):
                print("need tree")
                break
        else:
            s2 = ""
            i2 = 0
            for i in range(len(s)):
                if s[i] == t[i2]:
                    s2 += s[i]
                    i2 += 1
                    if i2 > len(t)-1:
                        break
            if len(s2) == len(t):
                print("automaton")
            else:
                print("both")
    else:
        print("need tree")

def main():
    ## LECTURE 1
    print("PYTHON")

    arr = []

    arr.append(1)
    arr.append(3)
    arr.append(4)

    arr.insert(1, 2)

    print("Size:", len(arr))

    print("3rd element:", arr[2])

    arr[3] = 10

    arr.pop()

    arr.pop(2)

    arr.clear()

    arr.extend(8*[0]);

    arr = arr[0:5]

    arr = [1, 2, 3, 4]

    print("Empty" if len(arr) == 0 else "Not empty")

    for n in arr:
        print(n, end=" ")

    for i in range(len(arr)-1, -1, -1):
        print(arr[i], end=" ")

    sss = "4Hello World"

    if ord(sss[0]) >= ord('0') and ord(sss[0]) <= ord('9'):
        print("Digit")

    print("Is character" if sss[2].isalpha() else "Not character")
    
    num = "123"
    nu = int(num)
    num2 = str(nu)
    print(num2)

if __name__ == "__main__":
    main()