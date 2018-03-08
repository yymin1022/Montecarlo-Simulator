#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carculate(int);

float averValue = 0;

//랜덤으로 난수를 구하는 함수
double rnd(){
	return ((double)(rand()%RAND_MAX)/(double)RAND_MAX);
}
int main(void){
	int j;
	//1만부터 10만까지의 값으로 넓이의 근삿값을 계산
	for(j=1; j<=10; j++){
		carculate(j*10000);
	}
	//10만까지의 계산을 완료한 후 오차율 10개의 평균값을 계산하여 출력
	printf("오차율의 평균값은 %f%입니다", averValue/10.0);
}

//넓이의 근삿값을 계산하는 함수
void carculate(int carcCount){
	int i;
	double errorRate = 0;
	double result = 0;
	double x = 0;
	double y = 0;
	double count = 0;
	double co = 0;
	srand(time(NULL));
	//넓이를 계산하는 for 반복문
	for(i=0; i<carcCount; i++){
		x = rnd();
		y = rnd();
		co=(x*x)+(y*y);
		if(co <= 1){
			count++;
			result = count/carcCount;
		}
	}
	//오차율 계산
	errorRate = (0.78539816339 - result) / 0.78539816339 * 100;
	//오차율이 음수이면 -1을 곱해 양수로 변환
	if(errorRate<0){
		errorRate = (-1) * errorRate;
	}
	//평균값을 계산하기 위해 전체 값 더하기
	averValue = averValue + errorRate;
	//계산결과 출력
	printf("%d번 시행하여 계산된 결과입니다.\n", i);
	printf("사분원 넓이의 근삿값은 %f입니다\n", result);
	printf("사분원의 실제 넓이는 π/4이며, 약 0.78539816339 입니다.\n");
	printf("오차율은 %f%입니다.\n\n", errorRate);
}
