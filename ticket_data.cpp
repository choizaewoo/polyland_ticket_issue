#include <stdio.h>

int main(){
	FILE *fp = fopen("report.csv","r");
	const int MAX = 100;
	int count = 0;
	int year[MAX], month[MAX], day[MAX], ticketTimeCaseArr[MAX],discountArr[MAX],
					ageCaseArr[MAX], ticketAmountArr[MAX], ticketPriceArr[MAX];	
	
	printf("\n=================================report.csv===============================\n");
	printf("년   월  일  권종\t 우대사항 \t 연령구분\t수량  \t 가격\n");
	
	
	
	while( fscanf(fp, "%d, %d, %d, %d, %d, %d, %d, %d\n", &year[count], &month[count], &day[count], 
						&ticketTimeCaseArr[count], &discountArr[count], &ageCaseArr[count],
						 &ticketAmountArr[count], &ticketPriceArr[count]) !=-1){
			count++;
		}
		
		

		
		fclose(fp);
		
		
		for(int index = 0; index < count; index++){
			printf("%d  %d  %d  %3d  %10d  %16d  %10d %12d\n", year[index], month[index], day[index], 
						ticketTimeCaseArr[index], discountArr[index], ageCaseArr[index],
						 ticketAmountArr[index], ticketPriceArr[index]);
		}
		
		
		return 0;
		
		
		
} 
