#include <stdio.h>
#include <time.h>


int main()
{
 
 

	int ticketAll; //�̿��    
	int ticketTime, ticketTimeCase; //�ְ� �߰� �̿��   
	int ticketAmount; //Ƽ�� ���� ����  
	int inputYear; //�¾ �����  
	int age, ageCase; // ����
	int discount; //��� 
	int ticketIssue; //Ƽ�Ϲ���
	int ticketPrice,  totalTicketPrice;
	int todayDate, idFront, idFrontMonth, idFrontDay, idBack, idBackFirst, yyyymmdd, again, counter;
	int goAgain; 
	
	
	int ticketTimeCaseArr[10]={0}, discountArr[10]={0}, ageCaseArr[10]={0}, ticketPriceArr[10]={0},ticketAmountArr[10]={0};
	

	const int ALLDAYADULT = 59000, ALLDAYTEEN = 52000, ALLDAYKID = 47000, ALLDAYBABY = 15000; // ��ũ+�ڹ��� + �ְ� 
	const int ALLAFTERADULT = 48000, ALLAFTERTEEN= 42000, ALLAFTERKID = 36000, ALLAFTERBABY = 15000; // ��ũ+�ڹ��� +�߰� 
    const int DAYADULT = 56000, DAYTEENAGER =50000, DAYKID =46000, DAYBABY =15000;  // ��ũ + �ְ� 
	const int AFTERADULT = 45000, AFTERTEEN = 40000, AFTERKID = 35000, AFTERBABY = 15000; //��ũ + �߰�
	const int BABYFREE = 0;

	
 // ���� ��¥ ���ϱ� //  //time_t base = 0;  //1970����   ���糯¥�� �ְ� �ʹٸ� base�� time(NULL)�� �־��ָ� �ȴ�.
	time_t timer;
	struct tm* t;                    
	time_t base = time(NULL);	
	t = localtime(&base);
	
	

	         	
	do{//�ٽ� �����ϱ� 
	
		
	do{
		//���� �ʱ�ȭ 
	ticketAll=0, ticketTime=0, discount=0, ageCase = 0, ticketPrice =0, ticketAmount=0, idFront=0, idBack=0;
	
	do{
	printf("\n=====================Ƽ�Ϲ���=======================\n");	
	
	printf("\n"); 
		
	printf("�̿���� �����ϼ���.\n");
	printf("1. �����̿��(���̰���+�μӹڹ���)\n 2.�⺻�̿��(���̰���)\n" );
	scanf("%d", &ticketAll);
	printf("\n");
	
 			if(!(ticketAll==1 || ticketAll== 2 )){
 				printf("������ �ǹٸ��� �ʽ��ϴ�.\n");
			 }
	}while(ticketAll>2); 

	do{
	printf("������ �����ϼ���: \n");
	printf(" 1.1Day(�ְ���-�Ϸ�����)\n 2.4Ater(�߰���-4�� ���� ����)\n ");
	scanf("%d",&ticketTime);
	printf("\n");
	
	 		if(!(ticketTime==1 || ticketTime== 2 )){
 				printf("������ �ǹٸ��� �ʽ��ϴ�.\n");
			 }
	}while(ticketTime>2); 

//�ֹι�ȣ �Է� �ޱ� , ���� ��� (�����) 
		do {
			printf("\n�ֹε�Ϲ�ȣ�� �Է����ּ���. ('-'��� ��ĭ ����ּ���. ex) 051225 3152135)\n");
			scanf("%6d %7d",&idFront, &idBack);
			
			idBackFirst = idBack/1000000;
			idFrontMonth = (idFront/100)%100;
			idFrontDay = idFront%100;
			//������ �ƴ� ����� 2�� 29���� �̺з� �� �� 
			if(idBackFirst >4 || idBackFirst<1 || idFrontDay>31 || idFrontDay<1 || idFrontMonth >12 ||
					idFrontDay <1 || idBack > 9999999 || idFront>999999 ||(idFrontMonth = 2 && idFrontDay>29)) {
				printf("��Ŀ� �°� �ٽ� �Է����ּ���.\n\n");
			}
		} while(idBackFirst >4 || idBackFirst<1 || idFrontDay>31 || idFrontDay<1 || idFrontMonth >12 ||
					idFrontDay <1 || idBack > 9999999 || idFront>999999 ||(idFrontMonth = 2 && idFrontDay>29)) ;
    printf("\n");
    
    
    //���
	 
    do{  
	printf("�������� �����ϼ���.(���� ���� �ڵ�ó��)\n 1.����\n 2.�����\n 3.����������\n 4.���ڳ�\n 5.�ӻ��\n");
	scanf("%d", &discount);
	printf("\n");

	
	 		if(discount >=6){
 				printf("���� ������ ������ �����ϴ�.\n");
			 }
	
	}while(discount>=6);
	
	//���Ű���
	 
	do{   
	printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
	scanf("%d", &ticketAmount);	
	printf("\n");
	
	 		if(ticketAmount >=11){
 				printf("���Ű��ɰ����� �ʰ��Ͽ����ϴ�.\n");
			 }
	}while(ticketAmount>=11); 

   //�ð� �Է� 
	todayDate= (t->tm_year + 1900)*10000 + (t->tm_mon + 1)*100 + t->tm_mday;  //20220101 ���·� ���� 
			
    //1900���, 2000��� �з�
		if (idBackFirst ==3 || idBackFirst == 4) { //2000���� 
				yyyymmdd = idFront + 20000000;
		} else {                  //1900���� 
				yyyymmdd = idFront + 19000000;
		} 
		
	//�� ���� ��� 
			ageCase = (todayDate - yyyymmdd)/10000;

    // ���� ����  
	
	
	if( age>=20 ){
		ageCase = 1;  //���ο�� 
	}
	else if( 13>=age && age<=18 ){
		ageCase = 2;  //û�ҳ��� 
	}
	
	else if( 3>=age && age<=12 ){
		ageCase = 3; //��̿�� 
	}
	
	else if( age>=65){
		ageCase = 4; //  65�� �̻�
		   
		
          }
	
	else if( age == 0){
		ageCase = 5; // 0����~12���� �̸�  
	}
	
	
	
	//Ƽ�� ���� 
	
	if( ticketAll==1 && ticketTime==1 ){
		ticketTimeCase = 1; // ���̰��� + �ڹ��� + 1day 
	}
	else if( ticketAll==1 && ticketTime==2 ){
		ticketTimeCase = 2; // ���̰���+ �ڹ��� + after
	}
	
	else if( ticketAll==2 &&  ticketTime==1 ){
		ticketTimeCase = 3; // ���̰��� + 1day
	}
		
	else if( ticketAll==2 &&  ticketTime==2 ){
		ticketTimeCase = 4; // ���̰��� + after 
	}
	

	
	if(ageCase == 1){ //���ο��
	 
		if(ticketTimeCase ==1){
			ticketPrice =  ALLDAYADULT * ticketAmount;
		}
		else if(ticketTimeCase ==2){
			ticketPrice = ALLAFTERADULT * ticketAmount;
		}
		else if(ticketTimeCase ==3){
			ticketPrice =  DAYADULT * ticketAmount;
		}
		else{
		
			ticketPrice = AFTERADULT * ticketAmount;
		}
	} 
	else if(ageCase == 2 ){ //û�ҳ���
	 
		if(ticketTimeCase ==1){
			ticketPrice = ALLDAYTEEN * ticketAmount;
		}
		else if(ticketTimeCase ==2){
			ticketPrice = ALLAFTERTEEN * ticketAmount;
		}
		else if(ticketTimeCase==3){
			ticketPrice = DAYTEENAGER * ticketAmount;
		}
		else{
			ticketPrice = AFTERTEEN * ticketAmount;		
		}
	} 
	else if(ageCase == 3 ){ // ��̿��
	 
		if(ticketTimeCase ==1){
			ticketPrice = ALLDAYKID * ticketAmount;
		}
		else if(ticketTimeCase ==2){
			ticketPrice = ALLAFTERKID * ticketAmount;
		}
		else if(ticketTimeCase ==3){
			ticketPrice = DAYKID * ticketAmount;
		}
		else {
			ticketPrice = AFTERKID * ticketAmount;			
		}
	} 
	else if(ageCase == 4 ){  // 65���̻� ���
	 
		if(ticketTimeCase ==1){
			ticketPrice = ALLDAYKID * ticketAmount;
		}
		else if(ticketTimeCase ==2){
			ticketPrice = ALLAFTERKID * ticketAmount;
		}
		else if(ticketTimeCase ==3){
			ticketPrice = DAYKID * ticketAmount;
		}
		else{
			ticketPrice = AFTERKID * ticketAmount;			
		}
	}
		
	else if(ageCase == 5 ){  // ���̺� ��� 
	 
		if(ticketTimeCase==1){
			ticketPrice = ALLDAYBABY * ticketAmount;
		}
		else if(ticketTimeCase ==2){
			ticketPrice = ALLAFTERBABY * ticketAmount;
		}
		else if(ticketTimeCase ==3){
			ticketPrice = DAYBABY * ticketAmount;
		}
		else {
			ticketPrice = AFTERBABY * ticketAmount;		
		}
	} 
			
		//12���� �̸��� ���
	if ( age == 0) {
			ticketPrice = 0;
			ageCase = 5;
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
	
	//����� �Ѿ� ���.
	if (ticketPrice==0){
		printf("\n���� ���� �Դϴ�.\n");
	}
	else {
		printf ("\n������ %d�� �Դϴ�.\n",ticketPrice);
	}
	
 	
	
	
	//���û��� ��, ��Ŀ� ���
		ticketTimeCaseArr[counter] = ticketTimeCase;
		discountArr[counter] = discount;
		ageCaseArr[counter] = ageCase;
		ticketPriceArr[counter] = ticketPrice;
		ticketAmountArr[counter]= ticketAmount;
		totalTicketPrice += ticketPrice;
	
//counter�� 1�߰�, �ʱⰪ�� 0 
		counter++; 
		
		//�̾ �������� ���� 
		printf("\n�̾ �̿���� �����Ͻðڽ��ϱ�?\n1.��\n2.�ƴϿ�\n");
		scanf("%d",&again); 
		
		//���� �ʱ�ȭ 
		 
	} while(again == 1);
	
	
	
	printf("\n�̿����ּż� �����մϴ�.\n");
	FILE *filePointer = fopen("report.csv", "a");
	
	
	// ������ ���
	printf("\n\n===================================== �������� =====================================\n") ;
	printf("%s %s %s\t %s \t\t%s\n\n","���û���","����","�ż�","����","������");
	for (int i =0; i<counter; i++) {
		fprintf(filePointer, "%d, %d, %d, %d, %d, %d, %d, %d\n", 
							t->tm_year + 1900,t->tm_mon + 1, t->tm_mday,
							ticketTimeCaseArr[i], discountArr[i], ageCaseArr[i], ticketAmountArr[i], ticketPriceArr[i]);
		  												
		  											
		
		switch (ticketTimeCaseArr[i]) {
			case 1:
				printf("%s\t%s","�����̿��","1Day");
				break;
			case 2:
				printf("%s\t%s","�����̿��","After4"); 
				break;
			case 3:
				printf("%s\t%s","��ũ�̿��","1Day");
				break;
			case 4:
				printf("%s\t%s","��ũ�̿��","After4");
				break;
			default:
				break;
		}
		
		switch (ageCaseArr[i]) {
			case 1:
				printf("%s","��  ��");
				break;
			case 2:
				printf("%s","û�ҳ�");
				break;
			case 3:
				printf("%s","���");
				break;
			case 4:
				printf("%s","��  ��");
				break;
			case 5:
				printf("%s","��  ��");
				break;
			case 6:
				printf("%s","��  ��");
				break;
			default:
				break;
		}
		
		printf("%10d%14d��\t",ticketAmountArr[i],ticketPriceArr[i]) ;
		
		switch (discountArr[i]) {
			case 1:
				printf("%s\n","������ ����");
				break;
			case 2:
				printf("%s\n","����� ���");
				break;
			case 3:
				printf("%s\n","���������� ���");
				break;
			case 4:
				printf("%s\n","�ް��庴 ���");
				break;
			case 5:
				printf("%s\n","�ӻ�� ���");
				break;
			case 6:
				printf("%s\n","�ٵ��� �ູī�� ���");
				break;
			default:
				break;
		}
    }
	printf("\n����� �Ѿ��� %d�� �Դϴ�.", totalTicketPrice);
	printf("\n=====================================================================================\n");
	printf("\n ��� ����(1: ���ο� �ֹ�, 2: ���α׷� ����)\n");
    scanf("%d", &goAgain);
    
    counter = 0; //���� �ʱ�ȭ 
    totalTicketPrice =0;
    }while(goAgain == 1);
		return 0; 



}







