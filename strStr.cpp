/*
 Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack. 
*/

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(strlen(needle)==0) //THis is important!!
        return haystack;
        int i=0,j=0;
        while(haystack[i+j]!='\0'&& needle[j]!='\0')
        {
            if(haystack[i+j]==needle[j]&&haystack[i+j]!='\0')
            j++;
            else
            {
                i++;
                j=0;
            }
            if(needle[j]=='\0')
            return haystack+i;
        }
        return NULL;
    }
};
