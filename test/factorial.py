"""def factorial(n):
    if n == 1:
        return 1
    return n * factorial(n-1)
        

factorial(5)
"""
"""
def gauss(n):
    if n == 1:
        return 1
    return n + gauss(n - 1)
"""
"""
def digits(n):
    if n < 1:
        return 0
    return 1 + digits(n / 10)

print(digits(234023942))
"""
"""
def collatz(n):
    print(n)
    if n == 1:
        return 1
    if n % 2 == 0:
        return collatz(n/2)
    else:
        return collatz(3*n + 1)

collatz(3330)
"""
"""
a = list()
print(a)

money = 400

ANNUAL_INTEREST = 0.024
MONTHLY_PAYMENT = 100
PHONE_BILL = 7
"""

"""
mydict = { "hello": 2, "bye": 4 }

for i in mydict:
    print(i)
"""
def recurse(text):
    if text:
        if text[0] > 'm':
            return recurse(text[1:])
        else:
            return text[0] + recurse(text[1:])
    else:
        return ""


print(recurse("pineapplecoconut"))
