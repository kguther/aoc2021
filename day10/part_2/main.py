from file_scorer import FileScorer


def main():
    scorer = FileScorer()
    score = scorer.score_file("input")
    print(f"Total error score is {score}")

if __name__ == "__main__":
    main()