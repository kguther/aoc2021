from syntax_checker import get_score_of_file


def main():
    score = get_score_of_file("input")
    print(f"Total error score is {score}")

if __name__ == "__main__":
    main()