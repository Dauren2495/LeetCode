class Solution {
public:
    int strStr(string haystack, string needle) {
        int hsize = haystack.size();
        int psize = needle.size();
        if(psize == 0)
            return 0;
        int *kmp = pattern(needle);
        int count = 0;
        for(int i = 0; i < hsize; i++){
            while(count > 0 && needle[count] != haystack[i])
                count = kmp[count];
            if(needle[count] == haystack[i])
                count++;
            if(count == psize)
                return i - psize + 1;
        }
        return -1;
    }
    int* pattern(string &p){
        int size = p.size();
        int *kmp = new int[size];
        kmp[0] = -1;
        for(int i = 1; i < size; i++){
            kmp[i] = kmp[i - 1] + 1;
            while(kmp[i] > 0 && p[i - 1] != p[kmp[i] - 1])
                kmp[i] = kmp[kmp[i] - 1] + 1;
        }
        return kmp;
    }
};
