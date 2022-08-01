char * generateTheString(int n){
    int s;
    static char ret_str[501] = "";

    s = n % 2 ? 1 : n;

    for (int i = 0; i < n; i ++){
        if (i < s - 1){
            ret_str[i] = 's';
        }
        else{
            ret_str[i] = 't';
        }
    }
        ret_str[n] = '\0';

    return ret_str;
}