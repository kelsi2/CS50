import random
import time

# If we are using functions we should have a main section to contain everything we are calling


def main():
  # Use the random library to get a random number between 5 and 15
    num = random.randint(5, 15)
    countdown(num)
    print("Happy New Year!")


# def countdown():
#   # Countdown from 10 instead of incrementing from 0 to 9
#     for i in range(10):
#         print(10 - i)

# Allow for variable numbers
def countdown(n):
    for i in range(n):
        print(n - i)
        # Pause for a second between each number so we can run a proper countdown
        time.sleep(1)


main()
