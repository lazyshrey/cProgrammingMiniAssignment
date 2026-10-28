#include <stdio.h>
#include <string.h>

#define MAX 10

struct Question {
  char text[150];
  char opt1[50];
  char opt2[50];
  char opt3[50];
  char opt4[50];
  int correct;
};

void loadQuestions(struct Question q[], int *total);
void displayInstructions();
void startQuiz(struct Question q[], int total);
void displayResult(int score, int total);

int main() {
  struct Question q[MAX];
  int total = 0, choice;

  loadQuestions(q, &total);

  do {
    printf("\nQuiz Application\n");
    printf("1. Start Quiz\n");
    printf("2. View Instructions\n");
    printf("3. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      startQuiz(q, total);
      break;
    case 2:
      displayInstructions();
      break;
    case 3:
      printf("Exiting program.\n");
      break;
    default:
      printf("Invalid choice.\n");
    }
  } while (choice != 3);

  return 0;
}

void loadQuestions(struct Question q[], int *total) {
  *total = 5;

  strcpy(q[0].text, "Which planet is known as the Red Planet?");
  strcpy(q[0].opt1, "Venus");
  strcpy(q[0].opt2, "Mars");
  strcpy(q[0].opt3, "Jupiter");
  strcpy(q[0].opt4, "Saturn");
  q[0].correct = 2;

  strcpy(q[1].text, "Which is the longest river in the world?");
  strcpy(q[1].opt1, "Amazon");
  strcpy(q[1].opt2, "Nile");
  strcpy(q[1].opt3, "Yangtze");
  strcpy(q[1].opt4, "Mississippi");
  q[1].correct = 2;

  strcpy(q[2].text, "Which gas do plants absorb during photosynthesis?");
  strcpy(q[2].opt1, "Oxygen");
  strcpy(q[2].opt2, "Nitrogen");
  strcpy(q[2].opt3, "Carbon Dioxide");
  strcpy(q[2].opt4, "Hydrogen");
  q[2].correct = 3;

  strcpy(q[3].text, "What is the capital of Australia?");
  strcpy(q[3].opt1, "Sydney");
  strcpy(q[3].opt2, "Melbourne");
  strcpy(q[3].opt3, "Canberra");
  strcpy(q[3].opt4, "Brisbane");
  q[3].correct = 3;

  strcpy(q[4].text, "What is the hardest natural substance on Earth?");
  strcpy(q[4].opt1, "Gold");
  strcpy(q[4].opt2, "Iron");
  strcpy(q[4].opt3, "Diamond");
  strcpy(q[4].opt4, "Platinum");
  q[4].correct = 3;
}

void displayInstructions() {
  printf("\nInstructions:\n");
  printf("1. 5 multiple-choice questions.\n");
  printf("2. Each question has 4 options (1-4).\n");
  printf("3. 1 mark per correct answer.\n");
  printf("4. No negative marking.\n");
}

void startQuiz(struct Question q[], int total) {
  int score = 0, ans;

  for (int i = 0; i < total; i++) {
    printf("\nQuestion %d: %s\n", i + 1, q[i].text);
    printf("1. %s\n2. %s\n3. %s\n4. %s\n", q[i].opt1, q[i].opt2, q[i].opt3,
           q[i].opt4);
    printf("Your answer (1-4): ");
    scanf("%d", &ans);

    while (ans < 1 || ans > 4) {
      printf("Invalid choice. Enter option (1-4): ");
      scanf("%d", &ans);
    }

    if (ans == q[i].correct) {
      score++;
    }
  }

  displayResult(score, total);
}

void displayResult(int score, int total) {
  float pct = ((float)score / total) * 100;

  printf("\nResult:\n");
  printf("Total Questions: %d\n", total);
  printf("Correct: %d\n", score);
  printf("Wrong: %d\n", total - score);
  printf("Score: %d/%d\n", score, total);
  printf("Percentage: %.2f%%\n", pct);

  if (pct >= 80.0) {
    printf("Performance: Excellent\n");
  } else if (pct >= 60.0) {
    printf("Performance: Good\n");
  } else if (pct >= 40.0) {
    printf("Performance: Average\n");
  } else {
    printf("Performance: Needs Improvement\n");
  }
}
