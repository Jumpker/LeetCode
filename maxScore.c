#define MAX(a,b) ((a)>(b)?(a):(b))
int maxScore(char* s) {
    int len = strlen(s);
    int front = 0;
    for(int i=1; i<len; i++){
        int score = 0;
        for(int j=0; j<i; j++){
            if(s[j] == '0') score++;
        }
        for(int j=i; j<len; j++){
            if(s[j] == '1') score++;
        }
        front = MAX(front,score);
    }
    return front;
}