#include <stdio.h>

int memo[201]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946};
long long int recur(int a){
	if(memo[a]){
		return memo[a];	
	}
	return memo[a] = (recur(a-1) + recur(a-2))%10009;
}
int main(){
	int a;
	scanf("%d", &a);
	long long int result = recur(a);
	printf("%lld\n", result);
	
	return 0;
}
