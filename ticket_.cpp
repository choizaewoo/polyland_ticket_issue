#include <stdio.h>
#include <time.h>
int main()
{
 
 
 // ���� ��¥ ���ϱ� // 

	struct tm* t;
	//time_t base = 0;  //1970�� 1�� 1��.   ���糯¥�� �ְ� �ʹٸ� base�� time(NULL)�� �־��ָ� �ȴ�. 
	time_t base = time(NULL);
	
	t = localtime(&base);
	
	
	printf(" ���� ��¥: %d %d %d\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
 	printf("\n");
 
	int ticketAll; //�̿��    
	int selectTime; //�ְ� �߰� �̿��   
	int ticketAmount; //Ƽ�� ���� ����   
	int discount; //��� 
	int ticketIssue; //Ƽ�Ϲ��� 
	int ticketPrice; //Ƽ�Ͽ��
	int currentDate; //���糯¥  
	int startAgain; //�籸�� 
 	int bill;  //������
	  
	const int allDayAdult = 59000, allDayTeen = 52000, allDayKid = 47000, allDayBaby = 15000; // ��ũ+�ڹ��� + �ְ� 
	const int allAterAdult = 48000, allAfterTeen = 42000, allAfterKid = 36000, allAfterBaby = 15000; // ��ũ+�ڹ��� +�߰� 
    const int dayAdult = 56000, dayTeenAger =50000, dayKid =46000, dayBaby =15000;  // ��ũ + �ְ� 
	const int afterAdult = 45000, afterTeen = 40000, afterKid = 35000, afterBaby = 15000; //��ũ + �߰�
	const int babyFree = 0;

	
	
	int bornYear; // �¾�����
	int bornYearFront; // �¾�⵵ 
	int bornDate; // �¾����
	int age; // ����  
	
	age = (currentDate - bornYearFront)+1;
	
	
	do {
		
	
	
	do{
	printf("�̿���� �����ϼ���.\n 1.���̰���+�μӹڹ���\n 2.���̰���\n" );
	scanf("%d", &ticketAll);
	printf("\n");
	
	
 			if(!(ticketAll==1 || ticketAll== 2 )){
 				printf("������ �ǹٸ��� �ʽ��ϴ�.\n");
			 }
	}while(ticketAll>2); 

	do{
	printf("������ �����ϼ���: \n 1.1Day(�ְ���-�Ϸ�����) \n 2.4Ater(�߰���-4�� ���� ����)\n ");
	scanf("%d",&selectTime);
	printf("\n");
	
	 		if(!(selectTime==1 || selectTime== 2 )){
 				printf("������ �ǹٸ��� �ʽ��ϴ�.\n");
			 }
	}while(selectTime>2); 

	
	
	printf("�ֹε�Ϲ�ȣ ���ڸ��� �Է��ϼ���: ex) 19940310 \n");
	scanf("%d", &age);

	do{   
	printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
	scanf("%d", &ticketAmount);	
	printf("\n");
	
	
	 		if(ticketAmount >=11){
 				printf("���Ű��ɰ����� �ʰ��Ͽ����ϴ�.\n");
			 }
	}while(ticketAmount>=11); 

	do{  
	printf("�������� �����ϼ���.(���� ���� �ڵ�ó��)\n 1.����\n 2.�����\n 3.����������\n 4.���ڳ�\n 5.�ӻ��\n");
	scanf("%d", &discount);
	printf("\n");

	
	 		if(discount >=6){
 				printf("���� ������ ������ �����ϴ�.\n");
			 }
	}while(discount>=6); 
	 
	
	//Ƽ�� ���� 
	
	if( ticketAll==1 && selectTime==1 ){
		ticketIssue = 1; // ���̰��� + �ڹ��� + 1day 
	}
	else if( ticketAll==1 && selectTime==2 ){
		ticketIssue = 2; // ���̰���+ �ڹ��� + after
	}
	
	else if( ticketAll==2 &&  selectTime==1 ){
		ticketIssue = 3; // ���̰��� + 1day
	}
		
	else if( ticketAll==2 &&  selectTime==2 ){
		ticketIssue = 4; // ���̰��� + after 
	}
	
	
	// ���� ����  
	
	if( age>=20 ){
		age = 1;  //���ο�� 
	}
	else if( 13>=age && age<=18 ){
		age = 2;  //û�ҳ��� 
	}
	
	else if( 3>=age && age<=12 ){
		age = 3; //��̿�� 
	}
	
	else if( age>=65){
		age = 4; // ��65�� �̻� ��̿��   
		
          }
	
	else if( age<1){
		age = 0; // 0����~12���� �̸�  
	}
	

	
	
	//Ƽ�� ���� �ݾ�
	if (age == 0){   //12���� �̸� 
		ticketPrice = babyFree;
	} 
	
	if(age == 1){
		if(ticketIssue ==1){
			ticketPrice =  allDayAdult * ticketAmount;
		}
		else if(ticketIssue ==2){
			ticketPrice = allAterAdult * ticketAmount;
		}
		else if(ticketIssue ==3){
			ticketPrice =  dayAdult * ticketAmount;
		}
		else if(ticketIssue ==4){
			ticketPrice = afterAdult * ticketAmount;
			
		}
	} 
	if(age == 2 ){
		if(ticketIssue ==1){
			
			ticketPrice = allDayTeen * ticketAmount;
		}
		else if(ticketIssue ==2){
			ticketPrice = allAfterTeen * ticketAmount;
		}
		else if(ticketIssue ==3){
			ticketPrice = dayTeenAger * ticketAmount;
		}
		else if(ticketIssue ==4){
			ticketPrice = afterTeen * ticketAmount;
			
		}
	} 
	if(age == 3 ){
		if(ticketIssue ==1){
			ticketPrice = allDayKid * ticketAmount;
		}
		else if(ticketIssue ==2){
			ticketPrice = allAfterKid * ticketAmount;
		}
		else if(ticketIssue ==3){
			ticketPrice = dayKid * ticketAmount;
		}
		else if(ticketIssue ==4){
			ticketPrice = afterKid * ticketAmount;
			
		}
	} 
	if(age == 4 ){
		if(ticketIssue ==1){
			ticketPrice = allDayKid * ticketAmount;
		}
		else if(ticketIssue ==2){
			ticketPrice = allAfterKid * ticketAmount;
		}
		else if(ticketIssue ==3){
			ticketPrice = dayKid * ticketAmount;
		}
		else if(ticketIssue ==4){
			ticketPrice = afterKid * ticketAmount;
			
		}
	} 

		
	
	

	//����ῡ ������ ���� 
	

	if (discount == 2) {
		ticketPrice = ticketPrice/2 ; // ��� Ƽ�� 50�� ��� 
	} else if (discount == 3) {
		ticketPrice = ticketPrice/2 ;
	} else if (discount == 4 && ticketAll==1) { //�����̿�Ǹ� ��� 
		ticketPrice = ticketPrice * 0.51;
	} else if (discount == 5 && ticketAll==1 ) {
		ticketPrice = ticketPrice/2;
	} else if (discount == 6 && ticketAll==1) {
		ticketPrice = ticketPrice*0.7;
	} else {
		printf("\n��� ������ �����ϴ�.\n");
	}
	printf("\n");
	
    printf("�̿���� �� �����Ͻðڽ��ϱ�?\n 1.�����ϱ�\n 2.�ƴϿ�\n");
    scanf("%d", &startAgain);

    
    }while(startAgain == 1);     //do ~ while �ݺ�
	 
    
    
    
    	
    do{
    	printf("�������� ����Ͻðڽ��ϱ�?\n  1.��\n 2.�ƴϿ�\n");
		scanf("%d", &bill);	
		 
		 if(bill==1){
 				printf("�������� ����մϴ�.\n");
 					printf("=======================������=======================\n");
    				printf("�����Ͻ� Ƽ�� : %d, ���� : %d, ������ : %d, ��: %d��\n", ticketAll, ticketAmount, discount, ticketPrice); 
					
						printf("\n");
						
						scanf("���� ��¥ : %d", &currentDate);



			 }
			 else{
			 	printf("�������� ������� �ʽ��ϴ�. �̿����ּż� �����մϴ�.\n");
			 } 
			 
	}while(bill>2); 
    
    



 

return 0;
}

		 
 
 
 



 


