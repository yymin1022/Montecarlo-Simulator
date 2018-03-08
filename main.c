#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void carculate(int);

float averValue = 0;

//�������� ������ ���ϴ� �Լ�
double rnd(){
	return ((double)(rand()%RAND_MAX)/(double)RAND_MAX);
}
int main(void){
	int j;
	//1������ 10�������� ������ ������ �ٻ��� ���
	for(j=1; j<=10; j++){
		carculate(j*10000);
	}
	//10�������� ����� �Ϸ��� �� ������ 10���� ��հ��� ����Ͽ� ���
	printf("�������� ��հ��� %f%�Դϴ�", averValue/10.0);
}

//������ �ٻ��� ����ϴ� �Լ�
void carculate(int carcCount){
	int i;
	double errorRate = 0;
	double result = 0;
	double x = 0;
	double y = 0;
	double count = 0;
	double co = 0;
	srand(time(NULL));
	//���̸� ����ϴ� for �ݺ���
	for(i=0; i<carcCount; i++){
		x = rnd();
		y = rnd();
		co=(x*x)+(y*y);
		if(co <= 1){
			count++;
			result = count/carcCount;
		}
	}
	//������ ���
	errorRate = (0.78539816339 - result) / 0.78539816339 * 100;
	//�������� �����̸� -1�� ���� ����� ��ȯ
	if(errorRate<0){
		errorRate = (-1) * errorRate;
	}
	//��հ��� ����ϱ� ���� ��ü �� ���ϱ�
	averValue = averValue + errorRate;
	//����� ���
	printf("%d�� �����Ͽ� ���� ����Դϴ�.\n", i);
	printf("��п� ������ �ٻ��� %f�Դϴ�\n", result);
	printf("��п��� ���� ���̴� ��/4�̸�, �� 0.78539816339 �Դϴ�.\n");
	printf("�������� %f%�Դϴ�.\n\n", errorRate);
}
