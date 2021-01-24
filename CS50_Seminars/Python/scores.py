def main():
    score1 = int(input("Score 1: "))
    score2 = int(input("Score 2: "))
    score3 = int(input("Score 3: "))

    print_score(score1)
    print_score(score2)
    print_score(score3)


def print_score(n):
    for i in range(n):
      # Don't print a new line after each hash
        print("#", end="")
    # After loop finishes print a new line by printing nothing
    print()


main()
