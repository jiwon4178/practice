//using namespace std;
//https://programmers.co.kr/learn/courses/30/lessons/62048

int gcd(int a, int b){		//최대공약수
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

long long solution(int w,int h) {
    long long answer = 1;
    long long multi= (unsigned long long )w * h;		//int to longlong 형변환  / int상태에서는 w*h이 안될때가 있다고함
    answer = multi -w -h + gcd(w,h);
    
    return answer;
}