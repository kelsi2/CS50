import random

num = random.randint(1, 10)

for i in range(3):
    n = int(input("Number: "))

    if n > num:
        print("Guess is too large")
        break
    elif n < num:
        print("Guess is too small")
    else:
        print("Correct!")
