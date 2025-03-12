#define eq(a) ((a=='a')||(a=='e')||(a=='i')||(a=='o')||(a=='u'))
int vowelStrings(char** words, int wordsSize, int left, int right) {
    int cnt=0;
    for(int i=left; i<=right; i++){
        int t=words[i][0], w=words[i][strlen(words[i])-1];
        if((eq(t)) && (eq(w))) cnt++;
    }
    return cnt;
}

void main(){
    char *words[]={"are","amy","u"};
    int left=0, right=2;
    printf("%d", vowelStrings(words, 3, left, right));
}