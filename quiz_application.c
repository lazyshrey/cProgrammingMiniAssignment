#include <stdio.h>

struct Question {
    char text[100];
    char opt1[30];
    char opt2[30];
    char opt3[30];
    char opt4[30];
    int correct;
};

void runQuiz(struct Question q[]);
void displayResults(int score);

int main() {
    struct Question q[5] = {
        {"Which planet is known as the Red Planet?", "Venus", "Mars", "Jupiter", "Saturn", 2},
        {"Which is the longest river in the world?", "Amazon", "Nile", "Yangtze", "Mississippi", 2},
        {"Which gas do plants absorb during photosynthesis?", "Oxygen", "Nitrogen", "Carbon Dioxide", "Hydrogen", 3},
        {"What is the capital of Australia?", "Sydney", "Melbourne", "Canberra", "Brisbane", 3},
        {"What is the hardest natural substance on Earth?", "Gold", "Iron", "Diamond", "Platinum", 3}
    };

    int choice;

    do {
        printf("\nQuiz Application\n");
        printf("1. Start Quiz\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            runQuiz(q);
        } else if (choice != 2) {
            printf("Invalid choice!\n");
        }
    } while (choice != 2);

    return 0;
}

void runQuiz(struct Question q[]) {
    int score = 0;
    int ans;

    for (int i = 0; i < 5; i++) {
        printf("\nQ%d. %s\n", i + 1, q[i].text);
        printf("1. %s\n2. %s\n3. %s\n4. %s\n", q[i].opt1, q[i].opt2, q[i].opt3, q[i].opt4);
        printf("Enter answer (1-4): ");
        scanf("%d", &ans);

        if (ans == q[i].correct) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! Correct answer is Option %d\n", q[i].correct);
        }
    }

    displayResults(score);
}

void displayResults(int score) {
    float percentage = (score / 5.0) * 100;
    printf("\nResult Analysis\n");
    printf("Total Questions\t: 5\n");
    printf("Correct Answers\t: %d\n", score);
    printf("Wrong Answers\t: %d\n", 5 - score);
    printf("Percentage\t: %.2f%%\n", percentage);

    if (score >= 4) {
        printf("Remark\t : Excellent\n");
    } else if (score >= 2) {
        printf("Remark\t : Good\n");
    } else {
        printf("Remark\t : Needs Improvement\n");
    }
}
