#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void question();

int main() {
	
	question();
	
	return 0;
}

void question() {
	srand(time(NULL));
	
	int x = 1 + rand() % 9; // 1-9
	int y = 1 + rand() % 9; // 1-9
	int response;
	
  printf("How much is %d times %d? ", x, y);
  scanf("%d", &response);
	
	while(response != x*y) {
		switch(1 + rand() % 4) {
			case 1:
				printf("No. Please try again.");
				break;
			case 2:
				printf("Wrong. Try once more.");
				break;
			case 3:
				printf("Don't give up!");
				break;
			case 4:
				printf("No. Keep trying.");
		}
	  printf("How much is %d times %d? ", x, y);
		scanf("%d", &response);
	}
	
	switch(1 + rand() % 4) {
		case 1:
			printf("Very good!");
			break;
		case 2:
			printf("Excellent!");
			break;
		case 3:
			printf("Nice work!");
			break;
		case 4:
			printf("Keep up the good work!");
	}
	printf("\n\n");
	
	question();
}
